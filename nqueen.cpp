#include <iostream>
#include <cmath>
using namespace std;

bool isSafe(int row, int col, int placement[], int n) {
    for (int i = 0; i < row; ++i) {
        if (placement[i] == col || abs(placement[i] - col) == row - i) {
            return false;
        }
    }
    return true;
}

bool solveNQueensUtil(int row, int n, int placement[], int solutions[][100], int& count) {
    if (row == n) {
        for (int i = 0; i < n; ++i) {
            solutions[count][i] = placement[i];
        }
        count++;
        return true;
    }

    bool foundSolution = false;
    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, placement, n)) {
            placement[row] = col;
            foundSolution = solveNQueensUtil(row + 1, n, placement, solutions, count) || foundSolution;
        }
    }
    return foundSolution;
}

int solveNQueens(int n, int solutions[][100]) {
    int placement[n];
    for (int i = 0; i < n; ++i) {
        placement[i] = -1;
    }
    int count = 0;
    bool foundSolution = solveNQueensUtil(0, n, placement, solutions, count);
    return foundSolution ? count : 0;
}

void printSolutions(int n, int solutions[][100], int count) {
    cout << "Number of solutions: " << count << endl;
    for (int k = 0; k < count; ++k) {
        cout << "Solution " << k + 1 << ":\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (solutions[k][i] == j) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    int solutions[100][100];
    int count = solveNQueens(n, solutions);

    printSolutions(n, solutions, count);

    return 0;
}