#include <stddef.h>

#include "unity.h"
#include "str_t.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_read_string()
{
  str_t str_info;

  read_string("h3lL0", &str_info);

  TEST_ASSERT_EQUAL_INT(5, str_info.len);
  TEST_ASSERT_EQUAL_INT(3, str_info.alpha_count);
  TEST_ASSERT_EQUAL_STRING("0Ll3h", str_info.reversed);


  str_free(&str_info);
}

void test_alpha_edge_cases(){
  str_t str_info;

  read_string("@AAZZZ[[[[[`aazzz{{{{{", &str_info);

  TEST_ASSERT_EQUAL_INT(10, str_info.alpha_count);

  str_free(&str_info);
}


int main(void)
{
   UnityBegin("tests/test_str_t.c");

   RUN_TEST(test_read_string);
   RUN_TEST(test_alpha_edge_cases);

   UnityEnd();

   return 0;
}
