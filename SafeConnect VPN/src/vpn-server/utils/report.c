#include <stdio.h>
#include "report.h"

void generate_report() {
    FILE *report_file = fopen("vpn_report.txt", "w");
    if (!report_file) {
        printf("Error opening report file.\n");
        return;
    }

    fprintf(report_file, "VPN Server Status Report\n");
    fprintf(report_file, "========================\n");
    for (int i = 0; i < MAX_SERVERS; i++) {
        fprintf(report_file, "Server %d: %s\n", i + 1, vpn_servers[i].is_running ? "Running" : "Stopped");
    }

    fclose(report_file);
    printf("Report generated: vpn_report.txt\n");
}
