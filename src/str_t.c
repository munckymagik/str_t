#include "str_t.h"
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

void str_move(str_t** p_source, str_t** p_destination) {
  *p_destination = malloc(sizeof(str_t));
  (*p_destination)->ptr = (*p_source)->ptr;
  (*p_destination)->len = (*p_source)->len;

  free(*p_source);
  *p_source = NULL;
}

void str_free(str_t* p_str) {
  // I don't think I can test this
  free((void *) p_str->ptr);
  free(p_str);
}

str_err_t str_copy_to_zero_terminated(const str_t* p_source, char* p_destination, size_t dest_size) {

  // Using this style of error checking out of nostalgia for how we had to do it
  // at my former job writing POS code in C(++).
  str_err_t res = STR_T_OK;

  // destination buffer needs to be large enough for the source string plus
  // the zero terminator
  if(dest_size <= p_source->len) {
    res = STR_T_BUFFER_TOO_SMALL;
  }

  if(STR_T_OK == res) {
    strncpy(p_destination, p_source->ptr, p_source->len);
    p_destination[p_source->len] = '\0';
  }

  return res;
}

str_t* str_copy(const str_t* p_source){
  return str_new_from_raw_parts(p_source->ptr, p_source->len);
}

str_t* str_concat(const str_t* p_str, str_t* p_other){
  char* concat_str = calloc(p_str->len + p_other->len, sizeof(char));
  strncpy(concat_str, p_str->ptr, p_str->len);

  char* copy_other_to = concat_str + sizeof(char) * p_str->len;
  strncpy(copy_other_to, p_other->ptr, p_other->len);

  str_t* result = malloc(sizeof(str_t));
  result->len = p_str->len + p_other->len;
  result->ptr = concat_str;
  return result;
}
