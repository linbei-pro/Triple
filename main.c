#include <stdio.h>
#include <stdlib.h>

// 定义三元组结构体
struct Triple {
    int row;
    int col;
    int value;
};

// 定义稀疏矩阵的三元组顺序表结构体
struct SparseMatrix {
    int rows;
    int cols;
    int count;
    struct Triple *data;
};

// 创建稀疏矩阵的三元组顺序表
struct SparseMatrix* createSparseMatrix(int rows, int cols, int count) {
    struct SparseMatrix *matrix = (struct SparseMatrix*)malloc(sizeof(struct SparseMatrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->count = count;
    matrix->data = (struct Triple*)malloc(count * sizeof(struct Triple));
    return matrix;
}

// 矩阵转置操作
struct SparseMatrix* transpose(struct SparseMatrix* matrix) {
    struct SparseMatrix* result = createSparseMatrix(matrix->cols, matrix->rows, matrix->count);
    for (int i = 0; i < matrix->count; ++i) {
        result->data[i].row = matrix->data[i].col;
        result->data[i].col = matrix->data[i].row;
        result->data[i].value = matrix->data[i].value;
    }
    return result;
}

// 释放稀疏矩阵的三元组顺序表所占用的内存空间
void freeSparseMatrix(struct SparseMatrix* matrix) {
    free(matrix->data);
    free(matrix);
}

int main() {
    // 创建稀疏矩阵的三元组顺序表
    struct SparseMatrix *matrix = createSparseMatrix(3, 3, 3);
    matrix->data[0].row = 0;
    matrix->data[0].col = 1;
    matrix->data[0].value = 3;
    matrix->data[1].row = 1;
    matrix->data[1].col = 0;
    matrix->data[1].value = 2;
    matrix->data[2].row = 2;
    matrix->data[2].col = 1;
    matrix->data[2].value = 1;

    // 转置稀疏矩阵
    struct SparseMatrix* transposedMatrix = transpose(matrix);

    // 释放内存
    freeSparseMatrix(matrix);
    freeSparseMatrix(transposedMatrix);

    return 0;
}
