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

void test_copy_to_zero_terminated() {
  str_t* str = str_new_from_zero_terminated("Hi!");
  char dest[4] = {'o', 'o', 'o', 'o'};

  str_err_t res = str_copy_to_zero_terminated(str, dest, sizeof(dest));

  TEST_ASSERT_EQUAL_INT(STR_T_OK, res);
  TEST_ASSERT_EQUAL_STRING("Hi!", dest);

  str_free(str);
}

void test_copy_to_zero_terminated_error() {
  str_t* str = str_new_from_zero_terminated("Hi!");
  char dest[3];

  str_err_t res = str_copy_to_zero_terminated(str, dest, sizeof(dest));
  TEST_ASSERT_EQUAL_INT(STR_T_BUFFER_TOO_SMALL, res);


  str_free(str);
}


void test_str_copy() {
  str_t* source = str_new_from_zero_terminated("Hi!");
  str_t* copy = str_copy(source);

  TEST_ASSERT_EQUAL_INT(3, copy->len);
  TEST_ASSERT_EQUAL_STRING_LEN("Hi!", copy->ptr, 3);

  TEST_ASSERT_NOT_EQUAL(source, copy);

  str_free(source);
  str_free(copy);
}

void test_str_concat() {
  str_t* hello = str_new_from_zero_terminated("Hello ");
  str_t* matey = str_new_from_zero_terminated("matey!");

  str_t* hello_matey = str_concat(hello, matey);

  TEST_ASSERT_EQUAL_INT(12, hello_matey->len);
  TEST_ASSERT_EQUAL_STRING_LEN("Hello matey!", hello_matey->ptr, 12);

  str_free(hello);
  str_free(matey);
  str_free(hello_matey);
}

int main(void)
{
   UnityBegin("tests/test_str_t.c");

   RUN_TEST(test_creating_new_raw_zero_terminated);
   RUN_TEST(test_creating_new_raw_parts);
   RUN_TEST(test_create_empty_string);
   RUN_TEST(test_copy_to_zero_terminated);
   RUN_TEST(test_copy_to_zero_terminated_error);
   RUN_TEST(test_str_copy);
   RUN_TEST(test_str_concat);

   UnityEnd();

   return 0;
}
