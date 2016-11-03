#include "./ej3.h"
#include "../mini_test.h"

/*
**  Exercise 3
**  Unit tests
*/

void solve_with_input(string file_name, vector<int>& solutions) {
	ifstream input_file;
	input_file.open(file_name);

    int C, A, Q;
    input_file >> C >> A >> Q;
    vector< vector<int> > M = vector< vector<int> >(C, vector<int>(A, 0));
    for (int i = 0; i < C; ++i)
        for (int j = 0; j < A; ++j)
            input_file >> M[i][j];
    vector<Query> queries = vector<Query>(Q, Query());
    for (int i = 0; i < Q; ++i)
        input_file >> queries[i];
    calculate_salary_difference(C, A, Q, M, queries, solutions);

	input_file.close();
}

void test_1(){
    vector<int> solutions = vector<int>(4, 0);
    vector<int> real_sols = {24, 0, 96, 20};

	solve_with_input("cases/case1.dat", solutions);

    for (int i = 0; i < solutions.size(); ++i)
        ASSERT_EQ(solutions[i], real_sols[i]);
}

void test_2(){
    vector<int> solutions = vector<int>(1, 0);
    vector<int> real_sols = {0};

	solve_with_input("cases/case2.dat", solutions);

    for (int i = 0; i < solutions.size(); ++i)
        ASSERT_EQ(solutions[i], real_sols[i]);
}

void test_3(){
    vector<int> solutions = vector<int>(1, 0);
	solve_with_input("cases/case3.dat", solutions);
}

void test_4(){
	vector<int> solutions = vector<int>(100000, 0);
	solve_with_input("cases/case4.dat", solutions);
}

void test_5(){
	vector<int> solutions = vector<int>(5, 0);
    vector<int> real_sols = {0,0,0,0,81};
	solve_with_input("cases/case5.dat", solutions);
    for (int i = 0; i < solutions.size(); ++i)
        ASSERT_EQ(solutions[i], real_sols[i]);
}

void run_unit_tests() {
	RUN_TEST(test_1);
	RUN_TEST(test_2);
	RUN_TEST(test_3);
	RUN_TEST(test_4);
	RUN_TEST(test_5);
}
