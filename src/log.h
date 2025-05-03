#ifndef LOG_H
#define LOG_H

int init_log(const char *filename);
void log_input(const char *msg);
void log_output(const char *msg);
void close_log(void);

#endif
