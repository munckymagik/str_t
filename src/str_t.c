#include "str_t.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

str_t* str_new_from_zero_terminated(const char* ptr){
  size_t len = strnlen(ptr, MAX_STR_LEN);
  return str_new_from_raw_parts(ptr, len);
}


str_t* str_new_from_raw_parts(const char* ptr, size_t len) {
  // Create the string, not deliberately null terminated
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
