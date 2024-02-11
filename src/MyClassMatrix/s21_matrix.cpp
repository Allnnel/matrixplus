#include "s21_matrix.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  MemoryAllocationMatrix();
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  this->MemoryAllocationMatrix();
  *this = other;
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() { ClearMatrix(); }

void S21Matrix::ClearMatrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) delete[] matrix_[i];
    delete[] matrix_;
  }
  matrix_ = nullptr;
  rows_ = 0;
  cols_ = 0;
}

void S21Matrix::MemoryAllocationMatrix() {
  if (rows_ <= 0 || cols_ <= 0) throw std::out_of_range("No memory allocated");
  matrix_ = new double*[rows_];
  if (matrix_ == nullptr) {
    delete[] matrix_;
    throw std::bad_alloc();
  }
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    if (matrix_[i] == nullptr) {
      for (int j = 0; j < i; j++) delete[] matrix_[j];
      delete[] matrix_;
      throw std::bad_alloc();
    }
    for (int j = 0; j < cols_; j++) matrix_[i][j] = 0.0;
  }
}

bool S21Matrix::TestBool(const S21Matrix& other) const {
  return matrix_ && other.matrix_ && other.cols_ >= 0 && other.rows_ >= 0;
}