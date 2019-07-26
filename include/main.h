//#include <GDBStub.h>

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <HardwareSerial.h>

#include "Types.h"

#define PAGE_HOME 1
#define PAGE_SETTINGS 2
#define PAGE_STATUS 3

#define POWER_ONOFF 'o'
#define SET_DEFAULT_VOLTAGE 'v'
#define SET_VOLTAGE 'w'
#define SAVE_NETWORKS 'n'
#define SET_POWERMODE 'a'
#define PAGE_STATE 'p'
#define DATA_PVI 'd'
#define SET_MEASURE_MODE 'm'

#define TAG_FIRMWARE_INFO 'f'
#define TAG_SYSTEM_INFO 'S'
#define TAG_NETWORK_INFO 'N'

void setup();
void loop();

extern void onHttpClientConnect(uint8_t);
extern void onHttpClientDisconnect(uint8_t);
extern void onHttpClientData(uint8_t num, String data);

extern void set_power_state(PowerState state);
extern void set_output_voltage(float value);
extern ulong get_lps();
extern ulong get_longest_loop();

static void ICACHE_RAM_ATTR powerButtonHandler();
void handle_power_button_press();
void calcLoopTimings();
void setup_hardware();
void sendClients(String, uint8_t);
void sendClients(String, uint8_t, uint8_t);
void sendOnPageState(uint8_t num, uint8_t page);

void update_display();
void update_wifi_led();
void delaySequence(uint8_t sec);
int quadraticRegression(double volt);
void onBootProgress(uint8_t per, const char *message = NULL);

ADC_MODE(ADC_VCC);