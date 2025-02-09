#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

typedef struct {
    int port;  // Порт для VPN-сервера
    char ip_address[16];  // IP-адрес VPN-сервера
} VpnConfig;

extern VpnConfig vpn_config;

int load_config();  // Загрузка конфигурации
int save_config();  // Сохранение конфигурации

#endif
