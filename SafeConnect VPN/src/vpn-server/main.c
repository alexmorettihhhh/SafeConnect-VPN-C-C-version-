#include <stdio.h>
#include "vpn_manager.h"
#include "traffic_analyzer.h"
#include "monitoring.h"
#include "websocket_manager.h"
#include "logger.h"
#include "config_manager.h"

int main() {
    int choice;

    // ��������� ������������
    if (load_config() != 0) {
        log_event("Error loading configuration.");
        return -1;
    }

    printf("Welcome to the VPN Management System\n");
    printf("1. Start VPN Server\n");
    printf("2. Stop VPN Server\n");
    printf("3. Get Server Status\n");
    printf("4. Analyze Traffic\n");
    printf("5. Monitor Resources\n");
    printf("6. Start WebSocket Server (Remote Admin)\n");
    printf("Please select an option: ");

    scanf("%d", &choice);

    switch (choice) {
    case 1:
        start_vpn_server(0);  // ������ ������� VPN-�������
        break;
    case 2:
        stop_vpn_server(0);  // ��������� ������� VPN-�������
        break;
    case 3:
        get_vpn_server_status(0);  // ��������� ������� ������� VPN-�������
        break;
    case 4:
        analyze_traffic();  // ������ �������
        break;
    case 5:
        monitor_resources();  // ���������� ��������� ��������
        break;
    case 6:
        start_websocket_server();  // ����� WebSocket-������� ��� ���������� �����������������
        break;
    default:
        printf("Invalid choice.\n");
        break;
    }

    return 0;
}
