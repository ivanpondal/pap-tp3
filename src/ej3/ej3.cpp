#include "./ej3.h"

/*
**  Exercise 3
**  Problem solver
*/

void run_solver() {
    // Data input
    int C, A, Q;
    cin >> C >> A >> Q;

    // M input
    vector< vector<int> > M = vector< vector<int> >(C, vector<int>(A, 0));
    for (int i = 0; i < C; ++i)
        for (int j = 0; j < A; ++j)
            cin >> M[i][j];

    // Queries input
    vector<Query> queries = vector<Query>(Q, Query());
    for (int i = 0; i < Q; ++i)
        cin >> queries[i];

    // Calculate solutions
    vector<int> solutions = vector<int>(Q, 0);
    calculate_salary_difference(C, A, Q, M, queries, solutions);

    // Print solutions
    for (int i = 0; i < Q; ++i)
        cout << solutions[i] << endl;
    
    return;
}

void calculate_salary_difference(int C, int A, int Q, vector< vector<int> >& M, vector<Query>& queries, vector<int>& solutions) {
    // Border case
    if (C == 0 || A == 0) {
        for (int i = 0; i < Q; ++i)
            cout << 0 << endl;
        return;
    }
    
    // Calculate additive table
    vector< vector<int> > S = vector< vector<int> >(C, vector<int>(A, 0));
    S[0][0] = M[0][0];
    for (int i = 1; i < C; ++i)
        S[i][0] = S[i-1][0] + M[i][0];
    for (int i = 1; i < A; ++i)
        S[0][i] = S[0][i-1] + M[0][i];
    for (int i = 1; i < C; ++i)
        for (int j = 1; j < A; ++j)
            S[i][j] = M[i][j] + S[i-1][j] + S[i][j-1] - S[i-1][j-1];

    // Solve queries
    for (int i = 0; i < Q; ++i) {
        Query q = queries[i];
        solutions[i] = S[q.c2][q.a2] - S[q.c1][q.a2] - S[q.c2][q.a1] + S[q.c1][q.a1];
    }

    return;
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
