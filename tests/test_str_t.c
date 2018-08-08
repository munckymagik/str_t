#include <stddef.h>
#include <string.h>

#include "unity.h"
#include "str_t.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_hello(void)
{
   TEST_ASSERT_EQUAL_STRING("Hello, World!", hello());
}

void test_creating_new_raw_zero_terminated() {
  str_t* str = str_new_from_zero_terminated("Hello matey.");
  TEST_ASSERT_NOT_NULL(str);

  TEST_ASSERT_EQUAL_INT(12, str->len);
  TEST_ASSERT_EQUAL_STRING_LEN("Hello matey.", str->ptr, 12);

  str_free(str);
}

void test_create_empty_string() {
  str_t* str = str_new_from_zero_terminated("");
  TEST_ASSERT_NOT_NULL(str);

  TEST_ASSERT_EQUAL_INT(0, str->len);

  str_free(str);
}

void test_creating_new_raw_parts() {
  str_t* str = str_new_from_raw_parts("Hello sailor.", 5);

  TEST_ASSERT_NOT_NULL(str);

  TEST_ASSERT_EQUAL_INT(5, str->len);
  TEST_ASSERT_EQUAL_STRING_LEN("Hello", str->ptr, 5);

  str_free(str);
}

int main(void)
{
   UnityBegin("tests/test_str_t.c");

   RUN_TEST(test_hello);
   RUN_TEST(test_creating_new_raw_zero_terminated);
   RUN_TEST(test_creating_new_raw_parts);
   RUN_TEST(test_create_empty_string);

   UnityEnd();

   return 0;
}
