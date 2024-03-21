#include <iostream>
#include <iomanip>

using namespace std;

const int MATRIX_ROWS = 2;
const int MATRIX_COLS = 2;
const int RESULT_COLS = 1;

float calculateDeterminant(float [][MATRIX_COLS]);
float** computeAdjoint(float [][MATRIX_COLS]);
float** computeInverse(float [][MATRIX_COLS]);
void multiply(float [][RESULT_COLS], float**, float [][RESULT_COLS]);

void input_2_2(float [][MATRIX_COLS]);
void input_2_1(float [][RESULT_COLS]);
void print_2_2(float matrix[][MATRIX_COLS]);
void print_2_1(float matrix[][RESULT_COLS]);

void calculateX(float [][RESULT_COLS], float [][MATRIX_COLS], float [][RESULT_COLS]);
void deallocate(float** );

int main() {

    float matrixA [MATRIX_ROWS][MATRIX_COLS];
    float matrixB [MATRIX_COLS][RESULT_COLS];
    float result [MATRIX_ROWS][RESULT_COLS] = {{0},{0}};

    cout << "Enter matrix A (2x2):\n";
    input_2_2(matrixA);
    cout << "Enter matrix B (2x1):\n";
    input_2_1(matrixB);

    calculateX(result, matrixA, matrixB);

    return 0;
}


void print_2_2(float matrix[][MATRIX_COLS]) {

    cout << fixed << setprecision(1);
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++)
            cout << setw(4) << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void print_2_1(float matrix[][RESULT_COLS]) {

    cout << fixed << setprecision(1);
    for (int i = 0; i < MATRIX_COLS; i++) {
        for (int j = 0; j < RESULT_COLS; j++)
            cout << setw(4) << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void input_2_2(float matrix[][MATRIX_COLS]){

    for (int i=0;i<MATRIX_ROWS;i++){
        for (int j=0;j<MATRIX_COLS;j++){
            cout << "[" << i << "][" << j << "]=";
            cin >> matrix[i][j];
        }
    }

    cout << "\nThe matrix you entered is:\n";
    print_2_2(matrix);
}

void input_2_1(float matrix[][RESULT_COLS]){

    for (int i=0;i<MATRIX_COLS;i++){
        for (int j=0;j<RESULT_COLS;j++){
            cout << "[" << i << "][" << j << "]=";
            cin >> matrix[i][j];
        }
    }

    cout << "\nThe matrix you entered is:\n";
    print_2_1(matrix);
}

void calculateX(float result[][RESULT_COLS], float matrixA[][MATRIX_COLS], float matrixB[][RESULT_COLS]) {
    
    float det = calculateDeterminant(matrixA);
    if (det == 0) {
        cout << "Determinant is zero. No unique solution exists.\n";
        return;
    }

    float **inverse = computeInverse(matrixA);
    multiply(result, inverse, matrixB);
    deallocate(inverse);

    cout << "Matrix X:\n";
    print_2_1(result);
}

void multiply(float result[][RESULT_COLS], float** matrixAInverse, float matrixB[][RESULT_COLS]) {
    
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < RESULT_COLS; j++) {
            for (int k = 0; k < MATRIX_COLS; k++)
                result[i][j] += matrixAInverse[i][k] * matrixB[k][j];
        }
    }
}

float calculateDeterminant(float matrix[][MATRIX_COLS]) {
    return (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);
}

float** computeAdjoint(float matrix[][MATRIX_COLS]) {
    
    float** adj = new float* [MATRIX_ROWS];
    for (int i = 0; i < MATRIX_ROWS; i++)
        adj[i] = new float [MATRIX_COLS];

    float temp = matrix[0][0];
    adj[0][0] = matrix[1][1];
    adj[0][1] = -matrix[0][1];
    adj[1][0] = -matrix[1][0];
    adj[1][1] = temp;

    return adj;
}

float** computeInverse(float matrix[][MATRIX_COLS]) {
    
    float det = calculateDeterminant(matrix);
    float** adj = computeAdjoint(matrix);

    float** inverse = new float*[MATRIX_ROWS];
    for (int i = 0; i < MATRIX_ROWS; ++i) {
        inverse[i] = new float[MATRIX_COLS];
        for (int j = 0; j < MATRIX_COLS; ++j) {
            inverse[i][j] = adj[i][j] / det;
        }
    }

    deallocate(adj);
    return inverse;
}

void deallocate(float** matrix){

    for (int i=0;i<MATRIX_ROWS;i++)
        delete [] matrix[i];
    delete [] matrix;
}