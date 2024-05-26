#include <iostream>
#include <cstdlib>

using namespace std;

const int row = 2, col = 12;

void SelectionSort(int matrix[row][col], int total_elements) {
  int min_index, min_value;
  for (int i = 0; i < total_elements; i++) {
    min_index = i;
    min_value = matrix[i / col][i % col];

    for (int j = i + 1; j < total_elements; j++) {
      int current_row = j / col;
      int current_col = j % col;

      if (matrix[current_row][current_col] < min_value) {
        min_index = j;
        min_value = matrix[current_row][current_col];
      }
    }

    if (min_index != i) {
      swap(matrix[i / col][i % col], matrix[min_index / col][min_index % col]);
    }
  }
}


void fillMatrix(int matrix[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

static void printMatrix(int matrix[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[row][col];
    fillMatrix(matrix);

    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    SelectionSort(matrix, row * col);

    cout << "Sorted matrix:" << endl;
    printMatrix(matrix);

    return 0;
}