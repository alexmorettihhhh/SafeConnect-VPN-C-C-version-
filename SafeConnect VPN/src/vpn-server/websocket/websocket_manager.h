#ifndef WEBSOCKET_MANAGER_H
#define WEBSOCKET_MANAGER_H

void start_websocket_server();  // Функция для запуска WebSocket-сервера для удаленного администрирования
void send_websocket_message(const char* message);  // Функция для отправки сообщений через WebSocket

#endif
