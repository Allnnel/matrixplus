#include "s21_matrix.h"

S21Matrix S21Matrix::Transpose() const {
  S21Matrix transposedMatrix(cols_, rows_);
  if (TestBool(*this))
    for (int i = 0; i < cols_; ++i)
      for (int j = 0; j < rows_; ++j)
        transposedMatrix.matrix_[i][j] = matrix_[j][i];

  return transposedMatrix;
}

S21Matrix S21Matrix::CalcComplements() {
  if (!TestBool(*this) || rows_ != cols_) throw std::out_of_range("Wrong data");
  if (rows_ == 1) return *this;
  S21Matrix complements(rows_, cols_);
  S21Matrix minor(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) {
      CalculateMinor(i, j, &minor);
      double minorDeterminant = minor.Determinant();
      complements.matrix_[i][j] = minorDeterminant * pow(-1, i + j);
    }
  return complements;
}

double S21Matrix::Determinant() {
  if (!TestBool(*this) || rows_ != cols_) throw std::out_of_range("Wrong data");
  double determinant = 0.0;
  if (rows_ == 1)
    determinant =
        matrix_[0][0];  
  else {
    S21Matrix minor(rows_ - 1, cols_ - 1);
    for (int i = 0; i < rows_; ++i) {
      CalculateMinor(0, i, &minor);
      double minorDeterminant = minor.Determinant();
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
  for (int i = 0; i < rows_; ++i) {
    if (i == row) continue;
    int minorCols = 0;
    for (int j = 0; j < cols_; ++j) {
      if (j == col) continue;
      minor->matrix_[minorRows][minorCols++] = matrix_[i][j];
    }
    minorRows++;
  }
}
