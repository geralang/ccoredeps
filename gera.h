
#ifndef GERA_H
#define GERA_H

#include "geratypes.h"


#define GERA_CLOSURE(returns, ...) \
    struct { \
        GeraAllocation* captures; \
        returns (*call)(GeraAllocation*, __VA_ARGS__); \
    }
#define GERA_CLOSURE_NOARGS(returns) \
    struct { \
        GeraAllocation* captures; \
        returns (*call)(GeraAllocation*); \
    }

#define GERA_STRING_NULL_TERM(s_name, d_name) \
    char d_name[s_name.length_bytes + 1]; \
    for(size_t c = 0; c < s_name.length_bytes; c += 1) { \
        d_name[c] = s_name.data[c]; \
    } \
    d_name[s_name.length_bytes] = '\0';

#define GERA_INT_MIN (-9223372036854775807 - 1)

GeraAllocation* gera___rc_alloc(size_t size, GeraFreeHandler fh);
void gera___rc_incr(GeraAllocation* a);
void gera___rc_decr(GeraAllocation* a);
void gera___rc_lock_read(GeraAllocation* a);
void gera___rc_unlock_read(GeraAllocation* a);
void gera___rc_lock_write(GeraAllocation* a);
void gera___rc_unlock_write(GeraAllocation* a);
void gera___free_nothing(char* data, size_t size);
GeraString gera___alloc_string(const char* data);
GeraString gera___wrap_static_string(const char* data);
size_t gera___codepoint_size(char fb);
void gera___panic(const char* reason);

extern GeraArray GERA_ARGS;


#endif