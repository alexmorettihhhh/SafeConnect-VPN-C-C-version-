#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>

// Структура для хранения информации о VPN-сервере
typedef struct {
    int id;             // Уникальный идентификатор сервера
    char name[50];      // Имя сервера
    char status[10];    // Статус сервера (например, "Running", "Stopped")
} VpnServer;

// Функции для работы с базой данных
int open_db();                       // Открытие базы данных
int close_db();                      // Закрытие базы данных
int create_table();                  // Создание таблицы для серверов
int insert_server(VpnServer* server); // Вставка информации о сервере в базу данных
int update_server_status(int id, const char* status);  // Обновление статуса сервера
int get_server_status(int id, char* status);           // Получение статуса сервера
int get_all_servers();               // Получение списка всех серверов

#endif // DATABASE_H
