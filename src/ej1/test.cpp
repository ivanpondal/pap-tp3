#include "./ej1.h"
#include "../mini_test.h"

/*
**  Exercise 1
**  Unit tests
*/

void run_unit_tests() {
	vector<substr_case> substr_cases = { // tests del algoritmo completo
		{"tato", "potatous", true}, // substring enteramente contenido
		{"pota", "potato", true}, // prefijo
		{"tato", "potato", true}, // sufijo
		{"potato", "potato", true}, // palabra entera
		{"a", "abc", true}, // patrón de tamaño 1
		{"b", "abc", true}, // patrón de tamaño 1
		{"c", "abc", true}, // patrón de tamaño 1
		{"bla", "abl", false}, // negativo
		{"bla", "ablba", false}, // negativo
		{"holmund", "holamundo", false}, // negativo
		{"abac", "abadabacabac", true}, // TS tiene prefijos con sucesión de bordes no trivial
		{"aba", "babc", false}, // El prefijo "ababa" de TS = abababc tiene un borde de tamaño |T| = 3 que es cruzado, el string "aba"
		{
			"abab",
			"abab",
			true
		}, // caso ad-hoc del tamaño máximo sugerido por el enunciado para load testing.
	};

	for (size_t i = 0; i < substr_cases.size(); ++i) {
		auto c = substr_cases[i];
		if (substring(c.t, c.s) == c.expected) {
			cout << "case " << i << ": ok" << endl;
		} else {
			cout << "case " << i << ": fail" << endl;
		}
	}
}
