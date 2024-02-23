
// Default implementation of the Gera core dependencies using libc.
// To support a target that does not support the C standard library,
// reimplement this set of functions.
// Consider also changing the definitions of 'GERACORE_MUTEX' and
// 'GERACORE_THREAD_LOCAL' inside of 'geracoredeps.h'.

#include "geracoredeps.h"
#include "gera.h"


#include <stdlib.h>

void* geracoredeps_malloc(size_t size) {
    return malloc(size);
}

void* geracoredeps_realloc(void* ptr, size_t size) {
    return realloc(ptr, size);
}

void geracoredeps_free(void* ptr) {
    free(ptr);
}


#ifdef _WIN32
    GERACORE_MUTEX geracoredeps_create_mutex() {
        GERACORE_MUTEX m;
        InitializeCriticalSection(&m);
        return m;
    }

    void geracoredeps_lock_mutex(GERACORE_MUTEX* m) {
        EnterCriticalSection(m);
    }

    void geracoredeps_unlock_mutex(GERACORE_MUTEX* m) {
        LeaveCriticalSection(m);
    }

    void geracoredeps_free_mutex(GERACORE_MUTEX* m) {
        DeleteCriticalSection(m);
    }

    GERACORE_THREAD_ID geracoredeps_thread_id() {
        return GetCurrentThreadId();
    }
#else
    GERACORE_MUTEX geracoredeps_create_mutex() {
        GERACORE_MUTEX m;
        if(pthread_mutex_init(&m, NULL) != 0) { 
            gera___panic("Unable to create a mutex!");
        } 
        return m;
    }

    void geracoredeps_lock_mutex(GERACORE_MUTEX* m) {
        if(pthread_mutex_lock(m) != 0) {
            gera___panic("Unable to lock a mutex!");
        }
    }

    void geracoredeps_unlock_mutex(GERACORE_MUTEX* m) {
        if(pthread_mutex_unlock(m) != 0) {
            gera___panic("Unable to unlock a mutex!");
        }
    }

    void geracoredeps_free_mutex(GERACORE_MUTEX* m) {
        if(pthread_mutex_destroy(m) != 0) {
            gera___panic("Unable to destroy a mutex!");
        }
    }

    GERACORE_THREAD_ID geracoredeps_thread_id() {
        return pthread_self();
    }
#endif


#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <locale.h>

void geracoredeps_eprint(const char* text) {
    size_t length = strlen(text);
    fwrite(text, sizeof(char), length, stderr);
}

size_t geracoredeps_display_uint_length(size_t n) {
    return snprintf(NULL, 0, "%zu", n);
}

void geracoredeps_display_uint(size_t n, char* buf) {
    sprintf(buf, "%zu", n);
}

size_t geracoredeps_display_sint_length(gint n) {
    return snprintf(NULL, 0, "%lld", (long long int) n);
}

void geracoredeps_display_sint(gint n, char* buf) {
    sprintf(buf, "%lld", (long long int) n);
}

size_t geracoredeps_display_float_length(gfloat n) {
    return snprintf(NULL, 0, "%f", n);
}

void geracoredeps_display_float(gfloat n, char* buf) {
    sprintf(buf, "%f", n);
}

size_t geracoredeps_display_pointer_length(void* p) {
    return snprintf(NULL, 0, "%p", p);
}

void geracoredeps_display_pointer(void* p, char* buf) {
    sprintf(buf, "%p", p);
}


void geracoredeps_exit(int code) {
    exit(code);
}