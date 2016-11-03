#include "./ej2.h"

using namespace std;

/*
**  Exercise 2
**  Problem solver
*/

int maxAparitions(Trie& emails, list<string>& nicknames) {
    int max = 0;
    for(list<string>::iterator it = nicknames.begin(); it != nicknames.end(); it++) {
        int aparitions = emails.aparitions(*it);
        if(aparitions > max)
            max = aparitions;
    }

    return max;
}

void run_solver() {

    Trie emails;
    list<string> nicknames;

    int alumns;
    cin >> alumns;

    for(int a = 0; a < alumns; a++) {
        string email;
        int nickname;
        cin >> email >> nickname;

        emails.insert(email);
        nicknames.push_back(email.substr(0, nickname));
    }

    int max = maxAparitions(emails, nicknames);
    cout << max << endl;
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
