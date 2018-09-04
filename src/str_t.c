#include "str_t.h"
#include <stdlib.h>

void reverse(const char* reverse_me, char* result, size_t len);

void read_string(const char* p_zstr, str_t* str_info) {
  size_t len = 0;
  long alpha_count = 0;

  for (char* s = (char*) p_zstr; *s != '\0' ; s += sizeof(char)) {
    len++;
    if((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')) {
      alpha_count++;
    }
  }

  str_info->reversed = malloc((len + 1) * sizeof(char));
  reverse(p_zstr, str_info->reversed, len);

  str_info->alpha_count = alpha_count;
  str_info->len = len;
}

void reverse(const char* reverse_me, char* result, size_t len) {
  char* reverse_me_char = (char*) reverse_me;
  char* result_char = result + len * sizeof(char);

  *result_char = '\0';

  for (size_t i = 0; i < len; i++) {
    result_char -= sizeof(char);
    *result_char = *reverse_me_char;
    reverse_me_char += sizeof(char);
  }
}

void str_free(str_t* str_info) {
  free(str_info->reversed);
}
