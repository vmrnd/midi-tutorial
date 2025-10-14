
#include "unity.h"
#include "pico/stdlib.h"

void setUp(void) {}
void tearDown(void) {}

void test_unity_basic(void) { TEST_ASSERT_EQUAL_INT(1, 1); }

int main(void) {
  stdio_init_all();
  printf("Starting Unity tests on Pico...\n");
  UNITY_BEGIN();
  RUN_TEST(test_unity_basic);
  return UNITY_END();
}