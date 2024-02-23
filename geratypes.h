
#ifndef GERATYPES_H
#define GERATYPES_H

#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>

#ifdef _WIN32
    #include <windows.h>
    #define GERACORE_MUTEX CRITICAL_SECTION
    #define GERACORE_THREAD_ID DWORD
#else
    #include <pthread.h>
    #define GERACORE_MUTEX pthread_mutex_t
    #define GERACORE_THREAD_ID pthread_t
#endif

typedef void (*GeraFreeHandler)(char* data, size_t size);

typedef struct GeraAllocation {
    GERACORE_MUTEX rc_mutex;
    size_t rc;
    size_t size;
    GeraFreeHandler fh;
    GERACORE_MUTEX data_mutex;
    char data[];
} GeraAllocation;

typedef struct GeraArray {
    GeraAllocation* allocation;
    size_t length;
    char* data;
} GeraArray;

typedef struct GeraString {
    GeraAllocation* allocation;
    size_t length;
    size_t length_bytes;
    const char* data;
} GeraString;

typedef double gfloat;
typedef int64_t gint;
typedef uint64_t guint;
typedef char gbool;


#endif