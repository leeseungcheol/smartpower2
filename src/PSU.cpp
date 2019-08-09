#include "psu.h"

Psu::Psu() {
    info = PsuInfo();

    wattHoursCalculationEnabled = false;

    active = false;
    initialized = false;

    startedAt = 0;
    updatedAt = 0;
    calcedAt = 0;

    pinMode(POWER_SWITCH_PIN, OUTPUT);
}

PsuInfo Psu::getInfo() { return info; }

void Psu::togglePower() { setState(state == POWER_OFF ? POWER_ON : POWER_OFF); }

void Psu::setConfig(ConfigHelper *config) { this->config = config; }

void Psu::setOnPowerOn(PsuEventHandler h) { onPowerOn = h; }

void Psu::setOnPowerOff(PsuEventHandler h) { onPowerOff = h; }

void Psu::setState(PowerState value, bool forceUpdate) {
    output->print(FPSTR(str_psu));
    output->printf_P(strf_power, value == POWER_ON ? "on " : "off ");
    output->println();

    if ((forceUpdate) || (state != value)) {
        state = value;
        if (state == POWER_ON){
           start();
            if (onPowerOn) onPowerOn();
        } else if (state == POWER_OFF) {
            stop();
            if (onPowerOff) onPowerOff();
        }
        digitalWrite(POWER_SWITCH_PIN, state);
        storePowerState(state);
    }
}

PowerState Psu::getState() { return state; }

float Psu::getOutputVoltage() { return outputVoltage; }

void Psu::setOutputVoltage(float value) {
    output->print(FPSTR(str_psu));
    output->printf_P(strf_output_voltage, value);
    output->println();
    
    outputVoltage = value;
    mcp4652_write(WRITE_WIPER0, quadraticRegression(value));
}

void Psu::begin() {
    if (!initialized) init();

    float v = config->getOutputVoltage();
    this->setOutputVoltage(v);

    PowerState ps;
    switch (config->getBootPowerState()) {
        case BOOT_POWER_OFF:
            ps = POWER_OFF;
            break;
        case BOOT_POWER_ON:
            ps = POWER_ON;
            break;
        case BOOT_POWER_LAST_STATE:
            ps = restorePowerState();
            break;
        default:
            ps = POWER_OFF;
    }

    setState(ps, true);
}

void Psu::storePowerState(PowerState state) {
    File f = SPIFFS.open(FILE_LAST_POWER_STATE, "w");
    f.println(state);
    f.flush();
    f.close();
}

PowerState Psu::restorePowerState() {
    if (!SPIFFS.exists(FILE_LAST_POWER_STATE)) {
        storePowerState(POWER_OFF);
        return POWER_OFF;
    }
    File f = SPIFFS.open(FILE_LAST_POWER_STATE, "r");
    PowerState value = PowerState(f.readString().toInt());
    f.close();
    return value;
}

void Psu::start() {
    startedAt = millis();
    updatedAt = startedAt;
    calcedAt = startedAt;
    active = true;
}

void Psu::stop() { active = false; }

void Psu::loop() {
    if (!active) return;

    if (millis_since(updatedAt) >= MEASUREMENT_INTERVAL_ms) {
        info.voltage = ina231_read_voltage();
        info.current = ina231_read_current();
        updatedAt = millis();
    }

    if (millis_since(calcedAt) >= ONE_SECOND_ms) {
        info.power = ina231_read_power();
        if (wattHoursCalculationEnabled) {
            info.wattSeconds += info.power;
        }
        calcedAt = millis();
    }
}

void Psu::setWattHours(double value) {
    info.wattSeconds = value / ONE_HOUR_s;
}

void Psu::enableWattHoursCalculation(bool enabled) {
    wattHoursCalculationEnabled = enabled;
}

bool Psu::isWattHoursCalculationEnabled() {
    return wattHoursCalculationEnabled;
}

float Psu::getVoltage() { return info.voltage; }

float Psu::getCurrent() { return info.current; }

float Psu::getPower() { return info.power; }

double Psu::getWattHours() { return info.wattSeconds * ONE_HOUR_s; }

String Psu::toString() {
    String str = String(getVoltage(), 3);
    str += "V, ";
    str += String(getCurrent(), 3);
    str += "A, ";
    str += String(getPower(), 3);
    str += "W, ";
    str += String(getWattHours(), 3);
    str += "Wh, ";
    return str;
}

unsigned long Psu::getDuration() {
    return millis_passed(startedAt, updatedAt) / ONE_SECOND_ms;
}

void Psu::init() {
    // meter
    ina231_configure();
    // pot
    mcp4652_init();
    initialized = true;
}

String Psu::getStateDescription() {
    char tmp[OUTPUT_MAX_LENGTH];
    sprintf(tmp, "power is %s ", getState() == POWER_ON ? "ON" : "OFF");    
    return String(tmp);
}
