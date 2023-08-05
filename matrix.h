#ifndef SYMMETRICTRIANGULARMATRIX_MATRIX_H
#define SYMMETRICTRIANGULARMATRIX_MATRIX_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include "symmetrictriangularmatrix.h"

template <class T>
class SymmetricTriangularMatrix;

template <class T>
class Matrix {
private:
    unsigned int rows;
    unsigned int columns;
    std::vector<std::vector<T>> data;

public:
    // constructor
    Matrix(unsigned int rows, unsigned int columns);
    Matrix(unsigned int rows);

    // getter and setter
    unsigned int getRows() const { return rows; }
    unsigned int getColumns() const { return columns; }
    std::vector<std::vector<T>> getData() const { return data; }

    // overloaded operators
    T& operator()(unsigned int row, unsigned int column); // allows to modify certain element
    const T& operator()(unsigned int row, unsigned int column) const; // allows just to read the element
    Matrix<T> operator*(const Matrix<T>& other) const;
    template <class U>
    Matrix<T> operator*(const SymmetricTriangularMatrix<U>& symMatrix) const;
    Matrix<T> operator+(const SymmetricTriangularMatrix<T>& symMatrix) const;
    Matrix<T> operator-(const SymmetricTriangularMatrix<T>& symMatrix) const;

    // print matrix
    void print() const;
};

#endif //SYMMETRICTRIANGULARMATRIX_MATRIX_H
