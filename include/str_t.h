#ifndef STR_T_H
#define STR_T_H

#include <stddef.h>

// Structure that will hold our string
typedef struct str {
  char* reversed;
  long alpha_count;
  size_t len;
} str_t;

/*
  Read bits of (pretend) useful information from p_zstr into str_info. Contains
  some dynamically allocated memory which must be freed with str_free.
 */
void read_string(const char* p_zstr, str_t* str_info);

/*
 * Destroy a str_t.
 *
 * Frees any memory allocated by this module.
 */
void str_free(str_t* p_str);

#endif
