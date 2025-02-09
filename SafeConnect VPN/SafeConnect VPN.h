#ifndef SAFE_CONNECT_VPN_H
#define SAFE_CONNECT_VPN_H

// Прототипы функций и классов, используемых в проекте
void startVPNServer();  // Функция для старта VPN сервера
void stopVPNServer();   // Функция для остановки VPN сервера
void analyzeTraffic();  // Функция для анализа трафика
void monitorResources(); // Функция для мониторинга ресурсов

// Возможно, добавление каких-то структур или классов, например:
struct VPNServer {
    int id;
    char ipAddress[16];
    bool isRunning;
};

#endif // SAFE_CONNECT_VPN_H
