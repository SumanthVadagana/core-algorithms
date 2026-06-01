#include <bits/stdc++.h>
using namespace std;

// Function to generate a single row of Pascal's Triangle
vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;

    ansRow.push_back(1);

    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }

    return ansRow;
}

// Function to generate Pascal's Triangle
vector<vector<int>> generatePascalTriangle(int numRows) {
    vector<vector<int>> triangle;

    for (int row = 1; row <= numRows; row++) {
        triangle.push_back(generateRow(row));
    }

    return triangle;
}

int main() {
    int numRows;

    cout << "Enter number of rows: ";
    cin >> numRows;

    vector<vector<int>> triangle = generatePascalTriangle(numRows);

    cout << "\nPascal's Triangle:\n";

    for (auto row : triangle) {
        for (auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}