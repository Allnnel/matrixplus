#include "s21_matrix.h"

bool S21Matrix::operator==(const S21Matrix& other) const {
  return this->EqMatrix(other);
}

double* S21Matrix::operator[](int index) {
  if (cols_ <= 0 || rows_ <= 0 || index <= -1)
    throw std::out_of_range("Wrong data");
  return matrix_[index];
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix res(*this);
  res.SumMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix res(*this);
  res.SubMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(double num) {
  S21Matrix res(*this);
  res.MulNumber(num);
  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix res(*this);
  res.MulMatrix(other);
  return res;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this == &other) return *this;

  this->ClearMatrix();
  rows_ = other.rows_;
  cols_ = other.cols_;

  MemoryAllocationMatrix();

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = other.matrix_[i][j];

  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  if (this == &other) return *this;

  this->ClearMatrix();
  rows_ = other.rows_;
  cols_ = other.cols_;

  MemoryAllocationMatrix();

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = other.matrix_[i][j];

  return *this;
}

void S21Matrix::operator+=(const S21Matrix& other) { SumMatrix(other); }

void S21Matrix::operator-=(const S21Matrix& other) { SubMatrix(other); }

void S21Matrix::operator*=(const S21Matrix& other) { MulMatrix(other); }

void S21Matrix::operator*=(const double num) { MulNumber(num); }

double& S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || row < 0 || col >= cols_ || col < 0)
    throw std::out_of_range("Wrong data");
  return matrix_[row][col];
}

double& S21Matrix::operator()(int row, int col) const {
  if (row >= rows_ || row < 0 || col >= cols_ || col < 0)
    throw std::out_of_range("Wrong data");
  return matrix_[row][col];
}

int S21Matrix::GetNumRows() const { return rows_; }

int S21Matrix::GetNumCols() const { return cols_; }

void S21Matrix::SetNumRows(int rows) {
  if (rows <= 0) throw std::out_of_range("Wrong data");
  S21Matrix new_matrix(rows, cols_);
  for (int i = 0; i < (rows_ < rows ? rows_ : rows); i++)
    std::copy(matrix_[i], matrix_[i] + cols_, new_matrix.matrix_[i]);
  *this = std::move(new_matrix);
}

void S21Matrix::SetNumCols(int cols) {
  if (cols <= 0) throw std::out_of_range("Wrong data");
  S21Matrix new_matrix(rows_, cols);
  for (int i = 0; i < rows_; i++)
    std::copy(matrix_[i], matrix_[i] + (cols_ < cols ? cols_ : cols),
              new_matrix.matrix_[i]);
  *this = std::move(new_matrix);
}

void S21Matrix::Set(int rows, int cols) {
  S21Matrix new_matrix(rows, cols);
  for (int i = 0; i < (rows_ < rows ? rows_ : rows); i++)
    std::copy(matrix_[i], matrix_[i] + (cols_ < cols ? cols_ : cols),
              new_matrix.matrix_[i]);
  *this = std::move(new_matrix);
}