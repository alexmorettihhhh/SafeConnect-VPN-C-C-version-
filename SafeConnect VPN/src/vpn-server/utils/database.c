#include <stdio.h>
#include <sqlite3.h>
#include "database.h"

sqlite3* db;

int open_db() {
    if (sqlite3_open("vpn_management.db", &db)) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        return -1;
    }
    return 0;
}

int create_table() {
    const char* create_table_sql = "CREATE TABLE IF NOT EXISTS vpn_servers (id INTEGER PRIMARY KEY, name TEXT, status TEXT);";
    char* err_msg = 0;
    if (sqlite3_exec(db, create_table_sql, 0, 0, &err_msg) != SQLITE_OK) {
        printf("SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        return -1;
    }
    return 0;
}

int insert_server(int id, const char* name, const char* status) {
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO vpn_servers (id, name, status) VALUES (%d, '%s', '%s');", id, name, status);
    char* err_msg = 0;
    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        printf("SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        return -1;
    }
    return 0;
}
