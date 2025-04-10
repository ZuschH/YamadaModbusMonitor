#include "config_parser.h"
#include "ini.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int handler(void* user, const char* section, const char* name, const char* value) {
    config_t* config = (config_t*)user;

    #define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0

    if (MATCH("serial", "port")) {
        strncpy(config->serial_port, value, sizeof(config->serial_port)-1);
    } else if (MATCH("serial", "baudrate")) {
        config->baudrate = atoi(value);
    } else if (MATCH("modbus", "poll_interval_ms")) {
        config->poll_interval_ms = atoi(value);
    } else if (MATCH("modbus", "timeout_ms")) {
        config->timeout_ms = atoi(value);
    } else if (MATCH("logging", "log_dir")) {
        strncpy(config->log_dir, value, sizeof(config->log_dir)-1);
    } else if (MATCH("logging", "log_format")) {
        strncpy(config->log_format, value, sizeof(config->log_format)-1);
    } else if (MATCH("network", "ssh_target")) {
        strncpy(config->ssh_target, value, sizeof(config->ssh_target)-1);
    } else if (MATCH("network", "ssh_port")) {
        config->ssh_port = atoi(value);
    } else if (MATCH("network", "ssh_user")) {
        strncpy(config->ssh_user, value, sizeof(config->ssh_user)-1);
    } else {
        return 0; /* unknown key */
    }
    return 1;
}

int load_config(const char* filename, config_t* config) {
    memset(config, 0, sizeof(*config));
    return ini_parse(filename, handler, config);
}
