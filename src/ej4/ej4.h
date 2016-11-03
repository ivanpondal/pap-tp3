#ifndef PAP_TP3_EJ4_H
#define PAP_TP3_EJ4_H

#include "../main.h"

/*
**  Exercise 4
*/

// Here go declarations of functions which are exported by the problem solver,
// global variables, etc.

int sum_two_max_fun_interval(std::vector<std::pair<int, int>>& segment_tree, int i, int j);

std::vector<std::pair<int, int>> build_segment_tree(std::vector<int>& day_fun, int day_count);

#endif // PAP_TP3_EJ4_H
