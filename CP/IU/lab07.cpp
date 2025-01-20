#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<vector<int>> generateRandomMatrix(int m, int n, int a, int b) {
    srand(time(0));
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = rand() % (b - a + 1) + a;
    return matrix;
}

void printMatrix(const vector<vector<int>> &matrix) {
    for (const auto &row : matrix) {
        for (int value : row)
            cout << value << " ";
        cout << "\n";
    }
}

bool areMatricesIdentical(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2) {
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size())
        return false;

    for (int i = 0; i < matrix1.size(); i++)
        for (int j = 0; j < matrix2.size(); j++)
            if (matrix1[i][j] != matrix2[i][j])
                return false;

    return true;
}

void sortDiagonals(vector<vector<int>> &matrix, int m, int n) {
    // Sort main diagonal in increasing order
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < n; j++)
            if (matrix[i][i] > matrix[j][j])
                swap(matrix[i][i], matrix[j][j]);

    // Sort secondary diagonal in decreasing order
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; ++j)
            if (i + j == m - 1 && matrix[i][j] > matrix[m - 1 - i][m - 1 - j])
                swap(matrix[i][j], matrix[m - 1 - i][m - 1 - j]);
}

bool isSymmetricMainDiagonal(const vector<vector<int>> &matrix, int m, int n) {
    for (int i = 0; i < m; ++i)
        for (int j = i + 1; j < n; ++j)
            if (matrix[i][j] != matrix[j][i])
                return false;

    return true;
}

bool isSymmetricSecondaryDiagonal(const vector<vector<int>> &matrix, int m, int n) {
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] != matrix[m - 1 - j][n - 1 - i])
                return false;

    return true;
}

vector<vector<int>> transposeMatrix(const vector<vector<int>> &matrix, int m, int n) {
    vector<vector<int>> transposed(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            transposed[i][j] = matrix[j][i];
    return transposed;
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2,
                                     int m1, int n1, int m2, int n2) {
    if (n1 != m2) {
        cout << "Error: Matrix dimensions are not compatible for multiplication.\n";
        return {};
    }

    vector<vector<int>> result(m1, vector<int>(n2, 0));
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n2; j++)
            for (int k = 0; k < m2; k++)
                result[i][j] += matrix1[i][k] * matrix2[k][j];

    return result;
}

int main() {
    cout << "1. Random 2D array with values in a range [a, b]\n";
    cout << "2. Print out the 2D array\n";
    cout << "3. Check if two matrices are identical\n";
    cout << "4. Sort the main diagonal in increasing order and the secondary diagonal in decreasing order.\n";
    cout << "5. Check symmetry with respect to the main diagonal\n";
    cout << "6. Check symmetry with respect to the secondary diagonal\n";
    cout << "7. Transpose a given matrix\n";
    cout << "8. Multiply two matrices\n";
    cout << "0. Exit\n";
    
    while (true) {
        int op, m, n, a, b;
        cout << "Enter your choice: ";
        cin >> op;

        if (!op) {
            break;
        } else if (op == 1) {
            cin >> m >> n >> a >> b;
            vector<vector<int>> matrix = generateRandomMatrix(m, n, a, b);
            printMatrix(matrix);
        } else if (op == 2) {
            cin >> m >> n;
            vector<vector<int>> inputMatrix(m, vector<int>(n));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    cin >> inputMatrix[i][j];
            printMatrix(inputMatrix);
        } else if (op == 3) {
            cin >> m >> n;
            vector<vector<int>> matrix1(m, vector<int>(n));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    cin >> matrix1[i][j];

            cin >> m >> n;
            vector<vector<int>> matrix2(m, vector<int>(n));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    cin >> matrix2[i][j];

            cout << (areMatricesIdentical(matrix1, matrix2) ? "Identical\n" : "Not identical\n");
        } else if (op == 4) {
            cin >> m >> n;
            vector<vector<int>> diagonalMatrix(m, vector<int>(n));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    cin >> diagonalMatrix[i][j];

            sortDiagonals(diagonalMatrix, m, n);
            printMatrix(diagonalMatrix);
        } else if (op == 5) {
            cin >> m >> n;
            vector<vector<int>> symmetricMatrix(m, vector<int>(n));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    cin >> symmetricMatrix[i][j];

            cout << (isSymmetricMainDiagonal(symmetricMatrix, m, n) ? "Symmetric\n" : "Not symmetric\n");
        } else if (op == 6) {
            cin >> m >> n;
            vector<vector<int>> symmetricMatrix2(m, vector<int>(n));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    cin >> symmetricMatrix2[i][j];

            cout << (isSymmetricSecondaryDiagonal(symmetricMatrix2, m, n) ? "Symmetric\n" : "Not symmetric\n");
        } else if (op == 7) {
            cin >> m >> n;
            vector<vector<int>> transposedMatrix(m, vector<int>(n));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    cin >> transposedMatrix[i][j];

            vector<vector<int>> resultTransposed = transposeMatrix(transposedMatrix, m, n);
            printMatrix(resultTransposed);
        } else if (op == 8) {
            cin >> m >> n;
            vector<vector<int>> matrixA(m, vector<int>(n));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    cin >> matrixA[i][j];

            int m1, n1;
            cin >> m1 >> n1;
            vector<vector<int>> matrixB(m1, vector<int>(n1));
            for (int i = 0; i < m1; i++)
                for (int j = 0; j < n1; j++)
                    cin >> matrixB[i][j];

            vector<vector<int>> resultMultiply = multiplyMatrices(matrixA, matrixB, m, n, m1, n1);
            printMatrix(resultMultiply);
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
