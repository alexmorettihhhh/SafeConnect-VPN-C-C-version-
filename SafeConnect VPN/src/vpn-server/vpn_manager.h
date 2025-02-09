#ifndef VPN_MANAGER_H
#define VPN_MANAGER_H

void init_vpn_servers();  // Инициализация серверов
void start_vpn_server(int index);  // Запуск VPN-сервера по индексу
void stop_vpn_server(int index);  // Остановка VPN-сервера по индексу
void get_vpn_server_status(int index);  // Получение статуса VPN-сервера по индексу

void connect_vpn_client(int server_index, const char *client_ip);  // Подключение клиента
void disconnect_vpn_client(int server_index, const char *client_ip);  // Отключение клиента

void restart_vpn_server(int index);  // Перезапуск VPN-сервера
void create_vpn_tunnel(const char *local_ip, const char *remote_ip);  // Создание VPN туннеля
void delete_vpn_tunnel(const char *tunnel_id);  // Удаление VPN туннеля

#endif
