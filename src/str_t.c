#include "str_t.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char * const message = "Hello, World!";

const char *hello(void)
{
    return message;
}


str_t* str_new_from_zero_terminated(const char* ptr){
  // Create the string, not deliberately null terminated
  size_t len = strnlen(ptr, MAX_STR_LEN);
  char* str = malloc(len  * sizeof(char));
  strncpy(str, ptr, len);

  // Create the return struct
  str_t* result = malloc(sizeof(str_t));

  result->ptr = str;
  result->len = len;
  return result;
}


void str_free(str_t* p_str) {
  // I don't think I can test this
  free((void *) p_str->ptr);
  free(p_str);
}
