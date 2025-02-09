#ifndef LOGGER_H
#define LOGGER_H

typedef enum {
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} LogLevel;

void log_event(const char *event, LogLevel level);  // Функция для записи событий в лог с уровнями

#endif
