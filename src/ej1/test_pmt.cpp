#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream& operator<<(ostream& o, const vector<int>& v) {
	o << "[ ";
	for (auto it = v.cbegin(); it != v.cend(); ++it) {
		o << *it << " ";
	}
	o << "]";
	return o;
}

void PartialMatchTable(const string& w, vector<int>& T) {

	T[0] = -1;

	if (w.size() == 1) {
		return;
	}

	T[1] = 0;

	size_t j = 2;
	size_t k = 0;

	while (j < w.size()) {
		if (w[j-1] == w[k]) {
			k++;
		} else {
			k = 0;
		}
		T[j] = k;
		j++;
	}
}

struct pmt_case {
	string w;
	vector<int> expected;
};

int main(int argc, char* argv[]) {

	// if (argc == 1) {
	// 	cout << "potato" << endl;
	// 	return 1;
	// }

	// string w(argv[1]);

	// vector<int> T(w.size());
	// PartialMatchTable(w, T);

	vector<pmt_case> cases = {
		{"abcabdab", {-1,0,0,0,1,2,0,1}},
		{"abcaby", {-1,0,0,0,1,2}},
		{"abcdabd", {-1,0,0,0,0,1,2}},
		{"participate in parachute", {-1,0,0,0,0,0,0,0,1,2,0,0,0,0,0,0,1,2,3,0,0,0,0,0}},
		{"aaaaa", {-1,0,1,2,3}}
	};

	for (size_t i = 0; i < cases.size(); ++i) {
		auto c = cases[i];
		vector<int> T((c.w).size());
		PartialMatchTable(c.w, T);
		if (T == c.expected) {
			cout << "ok" << endl;
		} else {
			cout << "fail" << endl;
		}
	}

	return 0;
}
