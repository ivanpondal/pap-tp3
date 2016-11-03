#include "./ej1.h"

using namespace std;

/*
**  Exercise 1
**  Problem solver
*/

vector<int> prefix_border_lengths(const string& s) {
    vector<int> T(s.size()+1);

    T[0] = -1;

    if (s.size() == 1) {
        return T;
    }

    T[1] = 0;

    size_t j = 2;
    int k = 0;

    while (j < s.size()+1) {
        if (k > -1 && s[j-1] != s[k]) {
            k = T[k];
        } else {
            k++;
            T[j] = k;
            j++;
        }
    }
    return T;
}

bool substring(const string& t, const string& s) {
    int m = t.size();

    string ts = t + s;
    vector<int> pbl = prefix_border_lengths(ts);

    // start at 2*m to avoid crossing-borders. 
    // given a prefix of ts of size <2*m, any of its borders of size >=m will be crossing-borders
    // cout << "pbl " << pbl << endl;
    for (size_t i = 2*m; i < pbl.size(); ++i) {
        if (pbl[i] == m) {
            return true;
        }
    }
    return false;
}

void run_solver() {
    string nombre, apodo;
    cin >> nombre >> apodo;

    if (substring(apodo, nombre)) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
}

// MAIN

enum mode {solver, test};

int main (int argc, char* argv[]) {
    // Configuración de la ejecución
    mode exec_mode = solver;

    // Parsea las opciones recibidas
    char opt;
    while ((opt = getopt(argc, argv, "ht")) != -1) {
        switch (opt) {
            case 'h': { // mostrar ayuda
                show_help(argv[0]);
                exit(0);
                break;
            }
            case 't': { // correr tests unitarios
                exec_mode = test;
                break;
            }
            default: { // si las opciones son inválidas
                show_help(argv[0]);
                exit(1);
                break;
            }
        }
    }

    if (exec_mode == solver) {
        run_solver();
    }
    else if (exec_mode == test) {
        run_unit_tests();
    }
}

// Imprime por pantalla un texto de ayuda
void show_help(char* bin_path) {
    cout << "  Modo de uso: " << setw(12) << bin_path << endl;
    cout << endl;
    cout << "  Los parámetros se reciben a través de la entrada estándar." << endl;
    cout << endl;
    cout << "  Opciones:" << endl;
    cout << "    -h          Muestra este texto de ayuda" << endl;
    cout << "    -t          Ejecuta los tests unitarios provistos para el algoritmo" << endl;
}
