#ifndef PAP_TP3_EJ1_H
#define PAP_TP3_EJ1_H

#include "../main.h"
#include <string>

using namespace std;

/*
**  Exercise 1
*/

// Here go declarations of functions which are exported by the problem solver,
// global variables, etc.

#define MAX_EJ1_INPUT_SIZE 100000

bool substring(const string& apodo, const string& nombre);
vector<bool> prefix_borders_of_length(const string& pattern);

struct pbl_case {
	string t;
	vector<int> expected;
};

struct substr_case {
	string t;
	string s;
	bool expected;
};

#endif // PAP_TP3_EJ1_H
