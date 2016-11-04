#include "./ej1.h"

using namespace std;

/*
**  Exercise 1
**  Problem solver
*/

// return a an array F of flags where F[i] indicates
// whether prefix of length i has a border of length m
vector<bool> prefix_borders_of_length(const string& s, int m) {
    vector<int> T(s.size()+1);
    vector<bool> F(s.size()+1, false);

    T[0] = -1;
    T[1] = 0;

    size_t j = 2;
    int k = 0;

    while (j < s.size()+1) {
        while (k > -1 && s[j-1] != s[k]) {
            k = T[k];
        }
        k++;
        T[j] = k;
        F[j] = k == m || F[k];
        j++;
    }
    
    return F;
}

bool substring(const string& t, const string& s) {
    int m = t.size();

    string ts = t + s;
    vector<bool> f = prefix_borders_of_length(ts, m);

    // start at 2*m to avoid crossing-borders. 
    for (size_t i = 2*m; i < f.size(); ++i) {
        if (f[i]) {
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
