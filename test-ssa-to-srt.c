#include <stdbool.h>
#include <stdlib.h>
#include "minunit.h"
#include "ssa-to-srt.h"

MU_TEST(test_lineStartsWith) {
	mu_check(lineStartsWith("[Events]", "[Events]") == 1);
	mu_check(lineStartsWith("Dialogue: 0,0:00:06.30,0:00:08.34,s1,,0,0,0,,Good evening", "[Events]") == 0);
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_lineStartsWith);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return minunit_status;
}
