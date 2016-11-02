#include "./ej4.h"
#include "../mini_test.h"

using namespace std;

/*
**  Exercise 4
**  Unit tests
*/

void test_input_file(string input_file_name, string expected_file_name) {
    ifstream input_file;
    ifstream expected_file;

    input_file.open(input_file_name);
    expected_file.open(expected_file_name);

    int day_count;
    int query_count;

    input_file >> day_count;
    input_file >> query_count;

    vector<int> day_fun(day_count);

    for (int i = 0; i < day_count; i++) {
        input_file >> day_fun[i];
    }

    vector<pair<int, int>> segment_tree = build_segment_tree(day_fun, day_count);

    int i, j, expected_max_fun;
    while (query_count > 0) {
        input_file >> i;
        input_file >> j;
        expected_file >> expected_max_fun;

        ASSERT_EQ(sum_two_max_fun_interval(segment_tree, i, j), expected_max_fun);

        query_count--;
    }

    input_file.close();
    expected_file.close();
}

void test_sample_input_1() {
    test_input_file("test_cases/input_1", "test_cases/expected_1");
}

void test_sample_input_2() {
    test_input_file("test_cases/input_2", "test_cases/expected_2");
}

void test_sample_input_3() {
    test_input_file("test_cases/input_3", "test_cases/expected_3");
}

void run_unit_tests() {
    RUN_TEST(test_sample_input_1);
    RUN_TEST(test_sample_input_2);
    RUN_TEST(test_sample_input_3);
}
