#ifndef SRC_MYCLASSMATRIX_S21MATRIX_H
#define SRC_MYCLASSMATRIX_S21MATRIX_H

#include <algorithm>
#include <iostream>
#include <valarray>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

  /**
   * \brief Функция ClearMatrix() освобождает занятую матрицей память и
   * сбрасывает ее размеры.
   */
  void ClearMatrix();
  /**
   * \brief MemoryAllocationMatrix() - выделяет память под матрицу и
   * инициализирует ее нулями. \param - нет входных данных. \throws
   * std::out_of_range Если количество строк или столбцов меньше или равно нулю.
   * \return нет возвращаемого значения.
   */
  void MemoryAllocationMatrix();
  /**
   * \brief Функция TestBool() проверяет, являются ли текущая матрица и другая
   * матрица корректными для выполнения операций. \param other Ссылка на другой
   * объект S21Matrix, который будет проверяться. \return Возвращает значение
   * типа bool: true, если матрицы корректны, и false в противном случае.
   */
  bool TestBool(const S21Matrix& other) const;

  /**
   * \brief Функция ArithmeticMatrix() является дополнительной функцией для
   * сокращения кода. \param other Ссылка на другой объект S21Matrix, с которым
   * будет выполнена операция. \param symbol Параметр +/-.
   */
  void ArithmeticMatrix(const S21Matrix& other, char symbol);

 public:
  /**
   * \brief S21Matrix::S21Matrix() - конструктор по умолчанию. Создает пустую
   * матрицу S21Matrix. \param - нет входных данных. \return нет возвращаемого
   * значения.
   */
  S21Matrix();
  /**
   * \brief S21Matrix::S21Matrix(int rows, int cols) - конструктор класса
   * S21Matrix, инициализирует объект с заданным числом строк и столбцов. \param
   * rows - количество строк в матрице. \param cols - количество столбцов в
   * матрице. \return нет возвращаемого значения.
   */
  S21Matrix(int rows, int cols);
  /**
   * \brief S21Matrix::S21Matrix(const S21Matrix& other) - конструктор
   * копирования класса S21Matrix. \param other - ссылка на другой объект класса
   * S21Matrix, который будет скопирован. \return нет возвращаемого значения.
   */
  S21Matrix(const S21Matrix& other);
  /**
   * \brief S21Matrix::S21Matrix(S21Matrix&& other) - конструктор перемещения
   * класса S21Matrix. \param other - ссылка на другой объект класса S21Matrix,
   * который будет перемещен. \return нет возвращаемого значения.
   */
  S21Matrix(S21Matrix&& other);
  /**
   * \brief S21Matrix::~S21Matrix() - деструктор класса S21Matrix.
   * \return нет возвращаемого значения.
   */
  ~S21Matrix();

  /**
   * \brief bool S21Matrix::EqMatrix(const S21Matrix& other) const - функция
   * проверяет, равна ли текущая матрица матрице other. \param other - другая
   * матрица, с которой происходит сравнение. \throws std::out_of_range Если
   * матрицы имеют разные размеры. \return Значение true, если матрицы равны, и
   * false в противном случае.
   */
  bool EqMatrix(const S21Matrix& other) const;
  /**
   * \brief void S21Matrix::SumMatrix(const S21Matrix& other) const - функция
   * выполняет сложение текущей матрицы с матрицей other. \param other -
   * матрица, с которой происходит сложение. \throws std::out_of_range Если
   * матрицы имеют разные размеры. \return нет возвращаемого значения.
   */
  void SumMatrix(const S21Matrix& other);
  /**
   * \brief void S21Matrix::SubMatrix(const S21Matrix& other) const - функция
   * выполняет вычитание матрицы other из текущей матрицы. \param other -
   * матрица, которую нужно вычесть. \throws std::out_of_range Если матрицы
   * имеют разные размеры. \return нет возвращаемого значения.
   */
  void SubMatrix(const S21Matrix& other);
  /**
   * \brief void S21Matrix::MulNumber(const double num) - функция умножает
   * текущую матрицу на число. \param num - число, на которое происходит
   * умножение. \return нет возвращаемого значения.
   */
  void MulNumber(const double num);
  /**
   * \brief void S21Matrix::MulMatrix(const S21Matrix& other) - функция
   * выполняет умножение текущей матрицы на матрицу other. \param other -
   * матрица, на которую происходит умножение. \throws std::out_of_range Если
   * матрицы имеют некорректные размеры для умножения. \return нет возвращаемого
   * значения.
   */
  void MulMatrix(const S21Matrix& other);

  /**
   * \brief S21Matrix S21Matrix::Transpose() - функция выполняет
   * транспонирование текущей матрицы. \param - нет входных данных. \throws
   * std::out_of_range Если текущая матрица не является прямоугольной. \return
   * Возвращает новую матрицу, полученную путем транспонирования текущей
   * матрицы.
   */
  S21Matrix Transpose() const;
  /**
   * \brief S21Matrix S21Matrix::CalcComplements() - функция вычисляет матрицу
   * алгебраического дополнения текущей матрицы. \param - нет входных данных.
   * \throws std::out_of_range Если текущая матрица не является квадратной.
   * \return Возвращает новую матрицу, представляющую матрицу алгебраического
   * дополнения текущей матрицы.
   */
  S21Matrix CalcComplements();
  /**
   * \brief double S21Matrix::Determinant() - функция вычисляет определитель
   * текущей матрицы. \param - нет входных данных. \throws std::out_of_range
   * Если текущая матрица не является квадратной. \return Возвращает значение
   * типа double, представляющее определитель матрицы.
   */
  double Determinant();
  /**
   * \brief S21Matrix S21Matrix::InverseMatrix() - функция вычисляет обратную
   * матрицу для текущей матрицы. \param - нет входных данных. \throws
   * std::out_of_range Если текущая матрица не является квадратной или ее
   * определитель равен 0. \return Возвращает новую матрицу, представляющую
   * обратную матрицу текущей матрицы.
   */
  S21Matrix InverseMatrix();
  /**
   * \brief void S21Matrix::СalculateMinor(int row, int col, S21Matrix* minor) -
   * функция вычисляет минор матрицы для заданного элемента. \param row - индекс
   * строки элемента, для которого вычисляется минор. \param col - индекс
   * столбца элемента, для которого вычисляется минор. \param minor - указатель
   * на матрицу, в которую будет записан вычисленный минор. \return нет
   * возвращаемого значения.
   */
  void CalculateMinor(int row, int col, S21Matrix* minor);

  /**
   * \brief Оператор сложения "+" складывает текущую матрицу с другой матрицей.
   * \param other Ссылка на другой объект S21Matrix, который будет сложен с
   * текущей матрицей. \throws std::out_of_range Если текущая матрица или другая
   * матрица некорректны (невозможно выполнить операцию сложения). \return Новый
   * объект S21Matrix, являющийся результатом сложения матриц.
   */
  S21Matrix operator+(const S21Matrix& other);
  /**
   * \brief Оператор вычитания "-" вычитает другую матрицу из текущей матрицы.
   * \param other Ссылка на другой объект S21Matrix, который будет вычтен из
   * текущей матрицы. \throws std::out_of_range Если текущая матрица или другая
   * матрица некорректны (невозможно выполнить операцию вычитания). \return
   * Новый объект S21Matrix, являющийся результатом вычитания матриц.
   */
  S21Matrix operator-(const S21Matrix& other);
  /**
   * \brief Оператор умножения на число "*" умножает текущую матрицу на заданное
   * число.
   *
   * \param num Значение типа double, на которое будет умножена матрица.
   * \return Новый объект S21Matrix, являющийся результатом умножения матрицы на
   * число.
   */
  S21Matrix operator*(double num);
  /**
   * \brief Оператор умножения "*" перемножает текущую матрицу на другую
   * матрицу.
   *
   * \param other Ссылка на другой объект S21Matrix, на который будет умножена
   * текущая матрица. \return Новый объект S21Matrix, являющийся результатом
   * умножения матриц.
   */
  S21Matrix operator*(const S21Matrix& other);
  /**
   * \brief Оператор "*=" умножает текущую матрицу на другую матрицу.
   *
   * \param other Ссылка на другой объект S21Matrix, на который будет умножена
   * текущая матрица.
   */
  void operator*=(const S21Matrix& other);
  /**
   * \brief Оператор сравнения "==" сравнивает текущую матрицу с другой
   * матрицей. \param other Ссылка на другой объект S21Matrix, с которым будет
   * выполнено сравнение. \return Возвращает значение типа bool: true, если
   * матрицы равны, и false в противном случае.
   */
  bool operator==(const S21Matrix& other) const;
  /**
   * \brief Оператор присваивания "=" копирует значения из другой матрицы в
   * текущую матрицу.
   *
   * \param other Ссылка на другой объект S21Matrix, значения которой будут
   * присвоены текущей матрице. \return Ссылка на текущий объект S21Matrix после
   * присваивания.
   */
  S21Matrix& operator=(const S21Matrix& other);

  /**
   * \brief Оператор присваивания "=" перемещает значения из другой матрицы в
   * текущую матрицу.
   *
   * \param other Ссылка на другой объект S21Matrix, значения которой будут
   * перемещены в текущую матрицу. \return Ссылка на текущий объект S21Matrix
   * после перемещения.
   */

  S21Matrix& operator=(S21Matrix&& other);
  /**
   * \brief Оператор "+=" складывает текущую матрицу с другой матрицей.
   *
   * \param other Ссылка на другой объект S21Matrix, который будет сложен с
   * текущей матрицей.
   */
  void operator+=(const S21Matrix& other);
  /**
   * \brief Оператор "-=" вычитает другую матрицу из текущей матрицы.
   *
   * \param other Ссылка на другой объект S21Matrix, который будет вычтен из
   * текущей матрицы.
   */
  void operator-=(const S21Matrix& other);
  /**
   * \brief Оператор "*=" умножает текущую матрицу на число.
   *
   * \param num Значение типа double, на которое будет умножена матрица.
   */
  void operator*=(const double num);
  /**
   * \brief Оператор "()" возвращает ссылку на элемент матрицы по заданным
   * координатам.
   *
   * \param row Индекс строки.
   * \param col Индекс столбца.
   * \throws std::out_of_range Если индексы строки или столбца некорректны.
   * \return Ссылка на значение элемента матрицы.
   */
  double& operator()(int i, int j);
  double& operator()(int i, int j) const;

  /**
   * \brief GetNumRows() - возвращает количество строк в матрице.
   * \return Количество строк в матрице.
   */
  int GetNumRows() const;
  /**
   * \brief Функция GetNumCols() возвращает количество столбцов в матрице.
   * \return Количество столбцов в матрице.
   */
  int GetNumCols() const;
  /**
   * \brief Функция SetNumRows() изменяет количество строк в матрице, сохраняя
   * значения существующих элементов. \param rows Новое количество строк.
   * \throws std::out_of_range Если новое количество строк или столбцов
   * некорректно.
   */
  void SetNumRows(int rows);
  /**
   * \brief Функция SetNumCols() изменяет количество столбцов в матрице,
   * сохраняя значения существующих элементов.
   *
   * \param cols Новое количество столбцов.
   * \throws std::out_of_range Если новое количество столбцов или строк
   * некорректно.
   */
  void SetNumCols(int cols);
  /**
   * \brief Оператор индексирования "[]" возвращает указатель на заданную строку
   * матрицы. \param index Индекс строки матрицы. \throws std::out_of_range Если
   * количество столбцов или строк меньше или равно нулю, или индекс
   * отрицателен. \return Указатель на массив значений строки матрицы.
   */
  double* operator[](int index);

  /**
   * \brief Оператор индексирования "[]" возвращает указатель на заданную строку
   * матрицы. \param index Индекс строки матрицы. \throws std::out_of_range Если
   * количество столбцов или строк меньше или равно нулю, или индекс
   * отрицателен. \return Указатель на массив значений строки матрицы.
   */
  void Set(int rows, int cols);
};

#endif