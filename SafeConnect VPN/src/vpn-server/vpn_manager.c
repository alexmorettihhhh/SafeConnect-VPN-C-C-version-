#include <stdio.h>
#include <string.h>
#include "vpn_manager.h"
#include "logger.h"

// Массив для хранения подключенных клиентов
#define MAX_CLIENTS 10
char connected_clients[MAX_CLIENTS][16];  // Массив для хранения IP-адресов подключенных клиентов
int client_count[MAX_SERVERS] = { 0 };  // Количество подключенных клиентов на каждом сервере

void connect_vpn_client(int server_index, const char* client_ip) {
    if (server_index < 0 || server_index >= MAX_SERVERS) {
        printf("Invalid server index.\n");
        return;
    }

    if (client_count[server_index] >= MAX_CLIENTS) {
        printf("Maximum number of clients reached for %s.\n", vpn_servers[server_index].name);
        return;
    }

    strcpy(connected_clients[client_count[server_index]], client_ip);
    client_count[server_index]++;
    log_event("Client connected to VPN server", LOG_INFO);
    printf("Client %s connected to %s\n", client_ip, vpn_servers[server_index].name);
}

void delete_vpn_tunnel(const char* tunnel_id) {
    printf("Deleting VPN tunnel %s...\n", tunnel_id);
    // Логика удаления туннеля
}

void create_vpn_tunnel(const char* local_ip, const char* remote_ip) {
    printf("Creating VPN tunnel from %s to %s...\n", local_ip, remote_ip);
    // Логика создания туннеля
}

void disconnect_vpn_client(int server_index, const char* client_ip) {
    if (server_index < 0 || server_index >= MAX_SERVERS) {
        printf("Invalid server index.\n");
        return;
    }

    for (int i = 0; i < client_count[server_index]; i++) {
        if (strcmp(connected_clients[i], client_ip) == 0) {
            // Сдвигаем элементы массива
            for (int j = i; j < client_count[server_index] - 1; j++) {
                strcpy(connected_clients[j], connected_clients[j + 1]);
            }
            client_count[server_index]--;
            log_event("Client disconnected from VPN server", LOG_INFO);
            printf("Client %s disconnected from %s\n", client_ip, vpn_servers[server_index].name);
            return;
        }
    }

    printf("Client %s not found on %s\n", client_ip, vpn_servers[server_index].name);
}
