
#ifndef GERACOREDEPS_H
#define GERACOREDEPS_H

#include "geratypes.h"


void* geracoredeps_malloc(size_t size);
void* geracoredeps_realloc(void* ptr, size_t size);
void geracoredeps_free(void* ptr);


GERACORE_MUTEX geracoredeps_create_mutex();
void geracoredeps_lock_mutex(GERACORE_MUTEX* m);
void geracoredeps_unlock_mutex(GERACORE_MUTEX* m);
void geracoredeps_free_mutex(GERACORE_MUTEX* m);


void geracoredeps_eprint(const char* text);

size_t geracoredeps_display_uint_length(size_t n);
void geracoredeps_display_uint(size_t n, char* buf);
size_t geracoredeps_display_sint_length(gint n);
void geracoredeps_display_sint(gint n, char* buf);
size_t geracoredeps_display_float_length(gfloat n);
void geracoredeps_display_float(gfloat n, char* buf);
size_t geracoredeps_display_pointer_length(void* p);
void geracoredeps_display_pointer(void* p, char* buf);

extern gbool geracoredeps_parse_success;

gint geracoredeps_parse_sint(char* parsed);
gfloat geracoredeps_parse_float(char* parsed);


void geracoredeps_exit(int code);

#endif