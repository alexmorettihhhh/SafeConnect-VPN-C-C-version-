#include <stdio.h>
#include <time.h>
#include "logger.h"

void log_event(const char* event, LogLevel level) {
    FILE* log_file = fopen("vpn_management.log", "a");
    if (log_file) {
        // ��������� �������� �������
        time_t t;
        time(&t);
        struct tm* tm_info = localtime(&t);

        // ����������� � ����� � ��������
        fprintf(log_file, "[%02d-%02d-%04d %02d:%02d:%02d] ", tm_info->tm_mday, tm_info->tm_mon + 1,
            tm_info->tm_year + 1900, tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);

        // ������� �����������
        switch (level) {
        case LOG_INFO:
            fprintf(log_file, "INFO: ");
            break;
        case LOG_WARNING:
            fprintf(log_file, "WARNING: ");
            break;
        case LOG_ERROR:
            fprintf(log_file, "ERROR: ");
            break;
        }

        fprintf(log_file, "%s\n", event);
        fclose(log_file);
    }
}
