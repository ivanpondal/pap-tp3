#include "./ej4.h"

using namespace std;

/*
**  Exercise 4
**  Problem solver
*/

pair<int, int> max(pair<int, int> a, pair<int, int> b) {
    return (a.first > b.first) ? a : b;
}

vector<pair<int, int>> build_segment_tree(vector<int>& day_fun, int day_count) {
    bool is_power_of_two = (__builtin_clz(day_count) + __builtin_ctz(day_count) == 31);

    int segment_tree_size = 1 << (31 - __builtin_clz(day_count));

    if (!is_power_of_two) {
        segment_tree_size <<= 1;
    }

    vector<pair<int, int>> segment_tree(2 * segment_tree_size, make_pair(0, -1));

    for (int i = 0; i < day_count; i++) {
        segment_tree[i + segment_tree_size].first = day_fun[i];
        segment_tree[i + segment_tree_size].second = i;
    }

    for (unsigned int i = 2 * segment_tree_size - 2; i > 0; i -= 2) {
        segment_tree[i / 2] = max(segment_tree[i], segment_tree[i + 1]);
    }

    return segment_tree;
}

pair<int, int> max_fun_interval(vector<pair<int, int>>& segment_tree, int k, int l, int r, int i, int j) {
    if (i <= l && r <= j) {
        return segment_tree[k];
    }
    else {
        if (r <= i || l >= j) {
            return make_pair(0, -1);
        }
        else {
            return max(max_fun_interval(segment_tree, 2 * k, l, (l + r) / 2, i, j),
                max_fun_interval(segment_tree, 2 * k + 1, (l + r) / 2, r, i, j));
        }
    }
}

int sum_two_max_fun_interval(vector<pair<int, int>>& segment_tree, int i, int j) {
    int segment_tree_size = segment_tree.size() / 2;
    pair<int, int> max_fun = max_fun_interval(segment_tree, 1, 0, segment_tree_size, i, j);
    pair<int, int> second_max_fun =
        max(max_fun_interval(segment_tree, 1, 0, segment_tree_size, i, max_fun.second),
                max_fun_interval(segment_tree, 1, 0, segment_tree_size, max_fun.second + 1, j));
    return max_fun.first + second_max_fun.first;
}

void run_solver() {
    int day_count, query_count;

    cin >> day_count;
    cin >> query_count;

    vector<int> day_fun(day_count);

    for (int i = 0; i < day_count; i++) {
        cin >> day_fun[i];
    }

    vector<pair<int, int>> segment_tree = build_segment_tree(day_fun, day_count);

    int i, j;
    while (query_count > 0) {
        cin >> i;
        cin >> j;
        cout << sum_two_max_fun_interval(segment_tree, i, j) << endl;
        query_count--;
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
