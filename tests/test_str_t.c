#include <stddef.h>

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

void test_str_new_from_raw_parts(void)
{
  char *input_string = "Sandwich";
  int input_length = 8;
  str_t *output = str_new_from_raw_parts(input_string, input_length);
  TEST_ASSERT_EQUAL_UINT(8, output->len);
  TEST_ASSERT_EQUAL_STRING("Sandwich", output->ptr);
  str_free(output);
}

void test_str_new_from_zero_terminated(void)
{
  char *input_string = "Wrap";
  str_t *output = str_new_from_zero_terminated(input_string);
  TEST_ASSERT_EQUAL_UINT(4, output->len);
  TEST_ASSERT_EQUAL_STRING("Wrap", output->ptr);
  str_free(output);
}

void test_str_copy(void)
{
  str_t *input = str_new_from_zero_terminated("Banana");
  str_t output;
  str_copy(input, &output);
  TEST_ASSERT_EQUAL_STRING("Banana", output.ptr);
  TEST_ASSERT_EQUAL_UINT(6, output.len);
}

int main(void)
{
   UnityBegin("tests/test_str_t.c");

   RUN_TEST(test_hello);
   RUN_TEST(test_str_new_from_raw_parts);
   RUN_TEST(test_str_new_from_zero_terminated);
   RUN_TEST(test_str_copy);

   UnityEnd();

   return 0;
}
