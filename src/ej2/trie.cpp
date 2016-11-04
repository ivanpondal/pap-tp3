#include <iostream>


using namespace std;

class Trie{
	Trie* hijos[256];
	bool final;
	int apariciones;
public:
	Trie() {
		final = false;
		apariciones = 0;
		for(int i = 0; i < 256; i++)
			hijos[i] = NULL;
	}
	Trie(string &s, int pos) {
		for(int i = 0; i < 256; i++)
			hijos[i] = NULL;

		apariciones = 1;

		if(pos == s.size()) {
			final = true;
		} else {
			final = false;
			hijos[s[pos]] = new Trie(s,pos+1);
		}
	}
	~Trie() {
		for(int i = 0; i < 256; i++) {
			if(hijos[i] != NULL){
				delete hijos[i];
			}
		}
	}
	void insert(string &s, int pos = 0) {
		apariciones++;
		if(pos == s.size()) {
			final = true;
		} else if(hijos[s[pos]] == NULL) {
			hijos[s[pos]] = new Trie(s,pos+1);
		} else {
			hijos[s[pos]]->insert(s,pos+1);
		}
	}
	int apparitions(string &s, int pos = 0) {
		if(pos == s.size()) {
			return apariciones;
		} else if(hijos[s[pos]] == NULL) {
			return 0;
		} else {
			return hijos[s[pos]]->apparitions(s,pos+1);
		}
	}
};

// int main() {
// 	int n;
// 	cin >> n;
// 	Trie t;
// 	char c;
// 	string s;
// 	for(int i=0;i<n;i++) {
// 		cin >> c >> s;
// 		if(c == 'i') {
// 			//insertar
// 			t.insert(s);
// 		} else {
// 			//buscar
// 			int f = t.apparitions(s);
// 			cout << f << endl;
// 		}
// 	}
// }