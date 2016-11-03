#include "./ej1.h"
#include "../mini_test.h"

/*
**  Exercise 1
**  Unit tests
*/

void run_unit_tests() {
	vector<pbl_case> pbl_cases = {
		{"abcabdab", {-1,0,0,0,1,2,0,1,2}},
		{"abcaby", {-1,0,0,0,1,2,0}},
		{"abcdabd", {-1,0,0,0,0,1,2,0}},
		{"participate in parachute", {-1,0,0,0,0,0,0,0,1,2,0,0,0,0,0,0,1,2,3,0,0,0,0,0,0}},
		{"aaaaa", {-1,0,1,2,3,4}},
		{"abcabax", {-1,0,0,0,1,2,1,0}},
		{"abacabadabacabac", {-1,0,0,1,0,1,2,3,0,1,2,3,4,5,6,7,4}},
		{"abcdabcd", {-1,0,0,0,0,1,2,3,4}},
		{"potatopotato", {-1,0,0,0,0,0,0,1,2,3,4,5,6}}
	};

	vector<substr_case> substr_cases = {
		{"TOTE", "ARISTOTELES", true},
		{"Tote", "Aristoteles", false},
		{"ritmo" ,"Algoritmo", true},
		{"holmund", "holamundo", false},
		{"tato", "potato", true},
		{"potato", "potato", true},
		{"aba", "babc", false}, // caso en el que aba+babc tiene el prefijo ababa que tiene un borde igual que |aba| pero es cruzado
	};

	cout << "prefix border lengths tests:" << endl;
	for (size_t i = 0; i < pbl_cases.size(); ++i) {
		auto c = pbl_cases[i];
		vector<int> T = prefix_border_lengths(c.t);
		if (T == c.expected) {
			cout << "case " << i << ": ok" << endl;
		} else {
			cout << "case " << i << ": fail" << endl;
		}
	}

	cout << endl;
	cout << "substring tests:" << endl;
	for (size_t i = 0; i < substr_cases.size(); ++i) {
		auto c = substr_cases[i];
		if (substring(c.t, c.s) == c.expected) {
			cout << "case " << i << ": ok" << endl;
		} else {
			cout << "case " << i << ": fail" << endl;
		}
	}
}
