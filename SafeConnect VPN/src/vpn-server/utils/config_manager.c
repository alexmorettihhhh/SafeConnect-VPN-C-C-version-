#include <stdio.h>
#include <string.h>
#include "config_manager.h"

#define CONFIG_FILE "vpn_config.txt"

VpnConfig vpn_config;

int load_config() {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (!file) {
        printf("Error: Unable to open configuration file.\n");
        return -1;
    }

    fscanf(file, "IP_ADDRESS=%s\n", vpn_config.ip_address);
    fscanf(file, "PORT=%d\n", &vpn_config.port);
    fclose(file);
    printf("Configuration loaded: IP Address = %s, Port = %d\n", vpn_config.ip_address, vpn_config.port);
    return 0;
}

int reload_config() {
    printf("Reloading configuration...\n");
    return load_config();  // Перезагружаем конфигурацию
}

int save_config() {
    FILE* file = fopen(CONFIG_FILE, "w");
    if (!file) {
        printf("Error: Unable to open configuration file for saving.\n");
        return -1;
    }

    fprintf(file, "IP_ADDRESS=%s\n", vpn_config.ip_address);
    fprintf(file, "PORT=%d\n", vpn_config.port);
    fclose(file);

    printf("Configuration saved.\n");
    return 0;
}
