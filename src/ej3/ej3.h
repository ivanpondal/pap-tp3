#ifndef PAP_TP3_EJ3_H
#define PAP_TP3_EJ3_H

#include "../main.h"

using namespace std;

/*
**  Exercise 3
*/

class Query {
public:
    // Constructors
    Query() {}
    ~Query() {}

    // Properties
    int c1, a1, c2, a2;

    // Methods
    friend istream& operator >>(istream& i, Query& query) {
        i >> query.c1; query.c1 --;
        i >> query.a1; query.a1 --;
        i >> query.c2; query.c2 --;
        i >> query.a2; query.a2 --;
        return i;
    }
};

void calculate_salary_difference(int C, int A, int Q, vector< vector<int> >& M, vector<Query>& queries, vector<int>& solutions);

#endif // PAP_TP3_EJ3_H
