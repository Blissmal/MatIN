#include <stdio.h>

/// Function to input a matrix from the user
void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

/// Function to display a matrix
void displayMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

/// Function to add two matrices
void addMatrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

/// Function to subtract two matrices
void subtractMatrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

/// Function to multiply two matrices
void multiplyMatrices(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input dimensions of the first matrix
    printf("Enter dimensions of the first matrix:\n");
    printf("Rows: ");
    scanf("%d", &rows1);
    printf("Columns: ");
    scanf("%d", &cols1);

    // Input the first matrix
    int matrix1[rows1][cols1];
    inputMatrix(rows1, cols1, matrix1);

    // Input dimensions of the second matrix
    printf("Enter dimensions of the second matrix:\n");
    printf("Rows: ");
    scanf("%d", &rows2);
    printf("Columns: ");
    scanf("%d", &cols2);

    // Input the second matrix
    int matrix2[rows2][cols2];
    inputMatrix(rows2, cols2, matrix2);

    // Check if matrices can be added and subtracted
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrices cannot be added or subtracted due to different dimensions.\n");
    } else {
        // Perform addition
        int sumMatrix[rows1][cols1];
        addMatrices(rows1, cols1, matrix1, matrix2, sumMatrix);
        printf("\nSum of Matrices:\n");
        displayMatrix(rows1, cols1, sumMatrix);

        // Perform subtraction
        int diffMatrix[rows1][cols1];
        subtractMatrices(rows1, cols1, matrix1, matrix2, diffMatrix);
        printf("\nDifference of Matrices:\n");
        displayMatrix(rows1, cols1, diffMatrix);
    }

    // Check if matrices can be multiplied
    if (cols1 != rows2) {
        printf("Matrices cannot be multiplied due to incompatible dimensions.\n");
    } else {
        // Perform multiplication
        int productMatrix[rows1][cols2];
        multiplyMatrices(rows1, cols1, matrix1, rows2, cols2, matrix2, productMatrix);
        printf("\nProduct of Matrices:\n");
        displayMatrix(rows1, cols2, productMatrix);
    }

    return 0;
}
