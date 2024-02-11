#include "s21_matrix.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  bool isTestPassed = true;
  if (!TestBool(other) || other.cols_ != cols_ || other.rows_ != rows_)
    isTestPassed = false;
  for (int i = 0; i != other.rows_ && isTestPassed; ++i)
    for (int ii = 0; ii != other.cols_ && isTestPassed; ++ii)
      if (matrix_[i][ii] != other.matrix_[i][ii]) isTestPassed = false;

  return isTestPassed;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  ArithmeticMatrix(other, '+');
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  ArithmeticMatrix(other, '-');
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; ++i)
    for (int ii = 0; ii < cols_; ++ii) matrix_[i][ii] *= num;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (!TestBool(other) || cols_ != other.rows_)
    throw std::out_of_range("Wrong data");
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < rows_; i++)
    for (int m = 0; m < other.cols_; m++)
      for (int k = 0; k < other.rows_; k++)
        result.matrix_[i][m] += (matrix_[i][k] * other.matrix_[k][m]);
  *this = result;
}

void S21Matrix::ArithmeticMatrix(const S21Matrix& other, char symbol) {
  if (!TestBool(other) || other.cols_ != cols_ || other.rows_ != rows_)
    throw std::out_of_range("Wrong data");
  for (int i = 0; i != other.rows_; ++i)
    for (int ii = 0; ii != other.cols_; ++ii) {
      if (symbol == '-') matrix_[i][ii] -= other.matrix_[i][ii];
      if (symbol == '+') matrix_[i][ii] += other.matrix_[i][ii];
    }
}