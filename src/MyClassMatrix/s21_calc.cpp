#include "s21_matrix.h"

S21Matrix S21Matrix::Transpose() const {
  // Создаем новую матрицу с количеством строк равным количеству столбцов
  // текущей матрицы и наоборот
  S21Matrix transposedMatrix(cols_, rows_);
  // Проходим по каждому элементу текущей матрицы и помещаем его в
  // соответствующую позицию в транспонированной матрице
  if (TestBool(*this))
    for (int i = 0; i < cols_; ++i)
      for (int j = 0; j < rows_; ++j)
        transposedMatrix.matrix_[i][j] = matrix_[j][i];

  return transposedMatrix;
}

S21Matrix S21Matrix::CalcComplements() {
  if (!TestBool(*this) || rows_ != cols_) throw std::out_of_range("Wrong data");
  // Создаем матрицу алгебраического дополнения
  if (rows_ == 1) return *this;
  S21Matrix complements(rows_, cols_);
  // Создаем матрицу минора
  S21Matrix minor(rows_ - 1, cols_ - 1);
  // Проходим по каждому элементу текущей матрицы
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) {
      // Вычисляем минор для текущего элемента
      CalculateMinor(i, j, &minor);
      // Вычисляем определитель минора
      double minorDeterminant = minor.Determinant();
      // Вычисляем значение алгебраического дополнения и помещаем его в
      // соответствующую позицию в матрице алгебраического дополнения
      complements.matrix_[i][j] = minorDeterminant * pow(-1, i + j);
    }
  return complements;
}

double S21Matrix::Determinant() {
  if (!TestBool(*this) || rows_ != cols_) throw std::out_of_range("Wrong data");
  double determinant = 0.0;
  if (rows_ == 1)
    determinant =
        matrix_[0][0];  // Если размер матрицы равен 1, то определитель равен
                        // значению единственного элемента
  else {
    S21Matrix minor(rows_ - 1, cols_ - 1);
    // Вычисляем определитель методом разложения по первой строке
    for (int i = 0; i < rows_; ++i) {
      // Вычисляем минор для текущего элемента в первой строке
      CalculateMinor(0, i, &minor);
      // Вычисляем определитель минора
      double minorDeterminant = minor.Determinant();
      // Добавляем к общему определителю значение текущего элемента,
      // определитель минора и множитель (-1)^(i)
      determinant += pow(-1, i) * matrix_[0][i] * minorDeterminant;
    }
  }

  return determinant;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (!TestBool(*this) || cols_ != rows_) throw std::out_of_range("Wrong data");
  double determinant = Determinant();
  if (determinant == 0) throw std::out_of_range("Wrong determonant");
  S21Matrix result(rows_, cols_);
  if (rows_ == 1)
    result.matrix_[0][0] = 1.0 / this->matrix_[0][0];
  else {
    S21Matrix tmp = CalcComplements();
    result = tmp.Transpose();
    result.MulNumber(1 / determinant);
  }
  return result;
}

void S21Matrix::CalculateMinor(int row, int col, S21Matrix* minor) {
  int minorRows = 0;
  // Проходим по каждой строке текущей матрицы, кроме строки с индексом row
  for (int i = 0; i < rows_; ++i) {
    if (i == row) continue;
    int minorCols = 0;
    // Проходим по каждому столбцу текущей матрицы, кроме столбца с индексом col
    for (int j = 0; j < cols_; ++j) {
      if (j == col) continue;
      // Помещаем элемент текущей матрицы в соответствующую позицию матрицы
      // минора
      minor->matrix_[minorRows][minorCols++] = matrix_[i][j];
    }
    minorRows++;
  }
}
