#pragma once

#include <pgmspace.h>

#define NO_GLOBAL_SSDP
#define NO_GLOBAL_MDNS
#define NO_GLOBAL_NBNS
#define NO_GLOBAL_NETBIOS
#define NO_GLOBAL_ARDUINOOTA

//#define SERIAL_DEBUG

//#define DEBUG_LEDS
//#define DEBUG_WEB_SERVICE
//#define DEBUG_SHELL
//#define DEBUG_TELNET
//#define DEBUG_CONFIG
//#define DEBUG_FILE_STORAGE
//#define DEBUG_TIME_BACKUP
//#define DEBUG_CLI
#define DEBUG_LCD

#define USE_DEBUG_SERIAL Serial

#define USE_SERIAL Serial

//#define DISABLE_HTTP
//#define DISABLE_LCD
//#define DISABLE_TIME_BACKUP
//#define DISABLE_TELNET
//#define DISABLE_TELNET_SHELL
//#define DISABLE_SERIAL_SHELL
//#define DISABLE_OTA_UPDATE
//#define DISABLE_NTP
//#define DISABLE_NETWORK_DISCOVERY

#define APPNAME "SmartPower2"
#define FW_VERSION \
    "0.6.1"        \
    " (" __DATE__ ")"

#define LOOP_STATS_INTERVAL 5000UL

#define START_SHOWING_RESTART_COUNTER_ON 5
#define ONE_MHz_hz 1000000UL
#define ONE_SECOND_ms 1000
#define ONE_MINUTE_s 60
#define ONE_HOUR_s 3600
#define ONE_HOUR_ms ONE_HOUR_s* ONE_SECOND_ms;
#define SEVENTY_YEARS_ms 2208988800UL

#define FILENAME_MAX_LENGTH 31
#define FILE_CONFIG "/cfg/settings.ini"
#define FILE_LAST_POWER_STATE "/cfg/powerstate"
#define FILE_TIME_BACKUP "/cfg/clock"
#define FILE_WEB_SETTINGS "/www/js/settings.js"

#define HOSTNAME "smartpower2"
#define WIFI_CONNECT_TIMEOUT 40
#define MAX_WEB_CLIENTS 5
#define OTA_PORT 8266
#define DNS_PORT 53
#define HTTP_PORT 80
#define WEBSOCKET_PORT 81
#define TELNET_PORT 23
#define WEB_ROOT "/www"
#define NTP_REMOTE_PORT 123
#define NTP_LOCAL_PORT 2390

#define DEF_NTP_POOL_SERVER "pool.ntp.org"
#define NTP_SYNC_INTERVAL_MIN_s 60
#define TIME_BACKUP_INTERVAL_MIN_s 600

#define DISPLAY_VIRTUAL_COLS 63
#define DISPLAY_VIRTUAL_ROWS 4

#define SCREEN_WIDTH 80
#define INPUT_MAX_LENGTH 128
#define OUTPUT_MAX_LENGTH 128

// slave address are 0x27 or 0x3f
#define LCD_SLAVE_ADDRESS 0x3f

#define CHAR_NULL '\x00'
#define CHAR_BEL '\x07'
#define CHAR_BS '\x08'
#define CHAR_TAB '\x09'
#define CHAR_LF '\x0a'
#define CHAR_LT '\x8b'
#define CHAR_CR '\x0d'
#define CHAR_SPACE '\x20'
#define CHAR_DEL '\x7f'
#define CHAR_BIN '\xFF'
#define CHAR_CSI '\x9b'
#define CHAR_ESC '\x1b'

#define ESC_CURSOR_HOME "\x1b[H"
#define ESC_SAVE_CURSOR "\x1b[s"
#define ESC_UNSAVE_CURSOR "\x1b[u"
#define ESC_SAVE_CURSOR_AND_ATTRS "\x1b[7"
#define ESC_RESTORE_CURSOR_AND_ATTRS "\x1b[8"

#define ESC_CLEAR "\x1b[2J"
#define ESC_CLEAR_BOTTOM "\x1b[J"
#define ESC_CLEAR_EOL "\x1b[0K"

#define ESCF_CURSOR_BACKWARD "\x1b[%dD"
#define ESC_CURSOR_UP "\x1b[1A"
#define ESC_CURSOR_DOWN "\x1b[1B"
#define ESC_CURSOR_FORWARD "\x1b[1C"
#define ESC_CURSOR_BACKWARD "\x1b[1D"

static const char strf_file_print[] PROGMEM = "Print %s";
static const char strf_file_deleted[] PROGMEM = "File % deleted";
static const char strf_file_not_found[] PROGMEM = "File %s not found";
static const char strf_config_param_value[] PROGMEM = "'%s'='%s'";
static const char strf_config_param_changed[] PROGMEM =
    "%s сhanged '%s' -> '%s'";
static const char strf_unknown_command_item[] PROGMEM =
    "Unknown item '%s' for command '%s'";
static const char strf_unknown_action_param[] PROGMEM =
    "Unknown param '%s' for action '%s'";
static const char strf_config_unknown_param[] PROGMEM = "Unknown param '%s'";
static const char strf_ip_port[] PROGMEM = "%s:%d";
static const char strf_set_param[] PROGMEM = "set %s";
static const char strf_progress[] PROGMEM = " %u%%\r";
static const char strf_boot_progress[] PROGMEM = "%s %u%%";

static const char str_done[] PROGMEM = "done";
static const char str_error[] PROGMEM = "error ";
static const char str_start[] PROGMEM = "start ";
static const char str_stopped[] PROGMEM = "stopped";
static const char str_failed[] PROGMEM = "failed";
static const char str_ready[] PROGMEM = "ready";
static const char str_firmware[] PROGMEM = "firmware";
static const char str_spiffs[] PROGMEM = "spiffs";
static const char str_unknown[] PROGMEM = "unknown";
static const char str_complete[] PROGMEM = "complete";
static const char str_arrow_dest[] PROGMEM = " -> ";
static const char str_arrow_src[] PROGMEM = " <- ";
static const char str_power[] PROGMEM = "[power]";
static const char str_lcd[] PROGMEM = "[lcd] ";
static const char str_netbios[] PROGMEM = "[netbios] ";
static const char str_ota_update[] PROGMEM = "[otaupdate] ";
static const char str_clock[] PROGMEM = "[clock] ";
static const char str_telnet[] PROGMEM = "[telnet] ";
static const char str_avaible_system_actions[] PROGMEM =
    "Available actions are: reset, load, save, restart, power";
