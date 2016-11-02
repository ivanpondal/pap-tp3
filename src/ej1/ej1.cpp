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
        while (k > -1 && s[j-1] != s[k]) {
            k = T[k];
        }
        // if (t[j-1] == t[k]) {
        //     k++;
        // } else {
        //     k = 0;
        // }
        k++;
        T[j] = k;
        j++;
    }

    // while (j < t.size()) {
    //     while (t[j-1] == t[k]) {
    //         k = T[k];
    //     }
    //     k++;
    //     T[j] = k;
    //     j++;
    // }
// }
    return T;
}

//B es borde de S
//C es borde de B
//C es prefijo de B && B es prefijo de S => C es prefijo de S (i.e C == B[0..long(C)] == S[0..long(C)])
//C es prefijo de B && B es prefijo de S => C es prefijo de S
//Ocurre lo mismo con los sufijos
//Entonces C va a ser borde de S

//Tomemos los bordes b1, b2, b3, ..., bs de S ordenados por longitud (b1 == "", long(b2) < long(b3) < long(b4) ...)
//Entonces, bi es borde de b(i+1) b(i+1)[0..|bi|] = S[0..|bi|] = bi entonces bi es prefijo de b(i+1) y por lo mismo es sufijo
//Si tenemos el borde maximo de S (bs) entonces tenemos todos, porque el segundo borde mas grande
//de S es b(s-1) que es el borde mas grande de bs

//la forma de obtener todos los bordes de mayor a menor, es borde[S], borde[borde[S]].... siendo borde[si] el borde mas grande de si

//Supongamos que tenemos Tc, su borde va a ser Sc (ambos terminan en la misma letra), entonces, S es borde de T
//Sc va a ser extender un borde de T con la letra c, entonces probemos todos los borde, de mayor a menor
//hasta que podamos extender alguno y ahi cortamos
// abac abadabac abac
//.0010123012345670
//k = 0

bool substring(const string& t, const string& s) {
    int m = t.size();

    string ts = t + s;
    vector<int> pbl = prefix_border_lengths(ts);

    for (size_t i = 0; i < ts.size(); ++i) {
        if (i >= m && pbl[i] >= m) {
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
