#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

vector<int> c;
vector<vector<int>> solutions;

bool isSafe(int i, int row) {
    for (int j = 1; j <= i - 1; j++) {
        if (c[j] == row) {
            return false;
        }

        if (abs(c[j] - row) == abs(j - i)) {
            return false;
        }
    }

    return true;
}

void backtrack(int i, int n) {
    if (i > n) {
        solutions.push_back(c);
        return;
    }

    for (int row = 1; row <= n; row++) {
        if (isSafe(i, row)) {
            c[i] = row;
            backtrack(i + 1, n);
            c[i] = 0;
        }
    }
}

void printSolution(const vector<int>& sol) {
    cout << "[";
    for (int i = 1; i < (int)sol.size(); i++) {
        cout << sol[i];
        if (i != (int)sol.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

void printBoard(const vector<int>& sol) {
    int n = sol.size() - 1;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            if (sol[col] == row) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << "\n";
    }
}

void solveNQueens(int n) {
    c.assign(n + 1, 0);
    solutions.clear();

    backtrack(1, n);

    cout << "n = " << n << "\n";
    cout << "Total solutions = " << solutions.size() << "\n";

    if (!solutions.empty()) {
        cout << "First solution: ";
        printSolution(solutions[0]);
        cout << "\n";
    }

    if (solutions.size() >= 2) {
        cout << "Second solution: ";
        printSolution(solutions[1]);
        cout << "\n";
    }

    if (n == 8 && !solutions.empty()) {
        cout << "\nOne board for n = 8:\n";
        printBoard(solutions[0]);
    }

    cout << "\n";
}

int main() {
    solveNQueens(6);
    solveNQueens(7);
    solveNQueens(8);

    return 0;
}
