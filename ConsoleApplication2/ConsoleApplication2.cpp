#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int* GetMatrixCol(const int* const* Matrix, unsigned rows, unsigned colNum)
{
    int* col = new int[rows];
    for (size_t j = 0; j < rows; j++)
    {
        col[j] = Matrix[j][colNum];
    }
    return col;
}

int** Transpose(const int* const* Matrix, unsigned rows, unsigned cols)
{
    int** TMatrix = new int* [rows];
    TMatrix[0] = new int[rows * cols];
    for (size_t i = 1; i < cols; i++)
        TMatrix[i] = TMatrix[i - 1] + cols;
    for (size_t i = 0; i < cols; i++)
    TMatrix[i] = GetMatrixCol(Matrix, rows, i);
    return TMatrix;
}

int** CreateIncMatrix(unsigned rows, unsigned cols)
{
    int temp = 1;
    int** Matrix = new int* [rows];
    Matrix[0] = new int[rows * cols];
    for (size_t i = 1; i < rows; i++)
        Matrix[i] = Matrix[i - 1] + cols;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            Matrix[i][j] = temp++;
        }
    }

    return Matrix;
}

void PrintMatrix(const int* const* Matrix, unsigned rows, unsigned cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << setw(4) << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    unsigned rows, cols;
    cin >> rows >> cols;

    int** Matrix = CreateIncMatrix(rows, cols);

    PrintMatrix(Matrix, rows, cols);

    cout << endl;

    int** TMatrix = Transpose(Matrix, rows, cols);

    PrintMatrix(TMatrix, cols, rows);

    system("pause");

    return 0;
}

