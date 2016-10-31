#include "./ej4.h"

using namespace std;

/*
**  Exercise 4
**  Problem solver
*/

int max(int a, int b) {
    return (a > b) ? a : b;
}

void build_segment_tree(vector<int>& segment_tree, vector<int>& segment_tree_pos, int segment_tree_size) {
    for (unsigned int i = 2 * segment_tree_size - 2; i > 0; i -= 2) {
        segment_tree[i / 2] = max(segment_tree[i], segment_tree[i + 1]);
        segment_tree_pos[i / 2] = (segment_tree[i / 2] == segment_tree[i]) ?
            segment_tree_pos[i] : segment_tree_pos[i + 1];
    }
}

int max_fun_interval(vector<int>& segment_tree, int k, int l, int r, int i, int j) {
    if (i <= l && r <= j) {
        return segment_tree[k];
    }
    else {
        if (r <= i || l >= j) {
            return 0;
        }
        else {
            return max(max_fun_interval(segment_tree, 2 * k, l, (l + r) / 2, i, j),
                max_fun_interval(segment_tree, 2 * k + 1, (l + r) / 2, r, i, j));
        }
    }
}

int max_fun_interval_pos(vector<int>& segment_tree, vector<int>& segment_tree_pos,
        int segment_tree_size, int max_fun, int k, int l, int r, int i, int j) {

    if (i <= l && r <= j) {
        return segment_tree[segment_tree_pos[k]] == max_fun ? segment_tree_pos[k] : -1;
    }
    else {
        if (r <= i || l >= j) {
            return -1;
        }
        else {
            int left_pos = max_fun_interval_pos(segment_tree, segment_tree_pos,
                    segment_tree_size, max_fun, 2 * k, l, (l + r) / 2, i, j);
            int right_pos = max_fun_interval_pos(segment_tree, segment_tree_pos,
                    segment_tree_size, max_fun, 2 * k + 1, (l + r) / 2, r, i, j);
            if (left_pos != -1) {
                return left_pos;
            }
            else {
                return right_pos;
            }
        }
    }
}

void run_solver() {
    int day_count, query_count;

    cin >> day_count;
    cin >> query_count;

    bool is_power_of_two = (__builtin_clz(day_count) + __builtin_ctz(day_count) == 31);

    int segment_tree_size = 1 << (31 - __builtin_clz(day_count));

    if (!is_power_of_two) {
        segment_tree_size <<= 1;
    }

    vector<int> segment_tree(2 * segment_tree_size, 0);
    vector<int> segment_tree_pos(2 * segment_tree_size, 0);

    for (int i = segment_tree_size; i < segment_tree_size + day_count; i++) {
        cin >> segment_tree[i];
    }

    for (int i = segment_tree_size; i < 2 * segment_tree_size; i++) {
        segment_tree_pos[i] = i - segment_tree_size;
    }

    build_segment_tree(segment_tree, segment_tree_pos, segment_tree_size);
    cout << segment_tree << endl;
    cout << segment_tree_pos << endl;

    for (int q = 0; q < query_count; q++) {
        int i, j;
        cin >> i;
        cin >> j;
        cout << "[" << i << ", " << j << ")" << endl;
        int max_fun = max_fun_interval(segment_tree, 1, 0, segment_tree_size, i, j);
        cout << max_fun << endl;
        cout << max_fun_interval_pos(segment_tree, segment_tree_pos, segment_tree_size, max_fun,
                1, 0, segment_tree_size, i, j) << endl;
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
