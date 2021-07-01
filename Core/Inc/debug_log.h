#ifndef __DEBUG_LOG_H
#define __DEBUG_LOG_H

#include <stdio.h>
#include <stdarg.h>

/**
 * define log_fatal
 */
#if defined(DEBUG) || defined(INFO) || \
    defined(WARN) || defined(ERROR) || defined(FATAL)
    #define log_fatal(fmt, ...) \
        do { \
            printf("FATAL %s:%d: " fmt, __FILE__, __LINE__, ## __VA_ARGS__); \
        } while(0)

    #define init_semihosting() \
        do { \
            initialise_monitor_handles(); \
        } while (0)

    extern void initialise_monitor_handles(void);
#else
    #define log_fatal(fmt, ...) \
        do { } while(0)

    #define init_semihosting() \
        do { } while(0)
#endif /* define log_fatal */

/**
 * define log_error
 */
#if defined(DEBUG) || defined(INFO) || \
    defined(WARN) || defined(ERROR)
    #define log_error(fmt, ...) \
        do { \
            printf("ERROR %s:%d: " fmt, __FILE__, __LINE__, ## __VA_ARGS__); \
        } while(0)
#else
    #define log_error(fmt, ...) \
        do { } while(0)
#endif /* define log_error */

/**
 * define log_warn
 */
#if defined(DEBUG) || defined(INFO) || \
    defined(WARN)
    #define log_warn(fmt, ...) \
        do { \
            printf("WARN %s:%d: " fmt, __FILE__, __LINE__, ## __VA_ARGS__); \
        } while(0)
#else
    #define log_warn(fmt, ...) \
        do { } while(0)
#endif /* define log_warn */

/**
 * define log_info
 */
#if defined(DEBUG) || defined(INFO)
    #define log_info(fmt, ...) \
        do { \
            printf("INFO %s:%d: " fmt, __FILE__, __LINE__, ## __VA_ARGS__); \
        } while(0)
#else
    #define log_info(fmt, ...) \
        do { } while(0)
#endif /* define log_info */

/**
 * define log_debug
 */
#if defined(DEBUG)
    #define log_debug(fmt, ...) \
        do { \
            printf("DEBUG %s:%d: " fmt, __FILE__, __LINE__, ## __VA_ARGS__); \
        } while(0)
#else
    #define log_debug(fmt, ...) \
        do { } while(0)
#endif /* define log_debug */

#endif /* __DEBUG_LOG_H */