#ifndef __debug_macro__
#define __debug_macro__

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#if defined(DEBUG)
    #define DEBUG_LOG
#endif /* DEBUG */

#ifdef DEBUG_LOG

#define init_semihosting\
        do { initialise_monitor_handles(); } while (0)

#define log_debug(fmt, ...)\
        do { sprintf(stderr, "[DEBUG] %10s:%10d:%15s(): " fmt, __FILE__, __LINE__, __func__,## __VA_ARGS__); } while (0)

#define log_err(fmt, ...) \
        do { sprintf(stderr, "[ERROR] %10s:%10d:%15s(): " fmt, __FILE__,  __LINE__, __func__,## __VA_ARGS__); } while (0)

#define log_warn(fmt, ...) \
        do { sprintf(stderr, "[WARN] %10s:%10d:%15s(): " fmt, __FILE__, \
                                __LINE__, __func__, ##__VA_ARGS__); } while (0)
                                
#define log_info(fmt, ...) \
        do { sprintf(stderr, "[INFO] %10s:%10d:%15s(): " fmt, __FILE__, \
                                __LINE__, __func__, ##__VA_ARGS__); } while (0)

extern void initialise_monitor_handles(void);

#else /* DEBUG */

#define init_semihosting do {} while (0)

#define log_debug(fmt, ...)  do {} while (0)
#define log_err(fmt, ...)  do {} while (0)
#define log_warn(fmt, ...)  do {} while (0)
#define log_info(fmt, ...)  do {} while (0)

#endif /* DEBUG */
#endif /* __debug_macro__ */