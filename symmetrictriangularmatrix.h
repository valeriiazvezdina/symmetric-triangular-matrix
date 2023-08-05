#ifndef SYMMETRICTRIANGULARMATRIX_H
#define SYMMETRICTRIANGULARMATRIX_H

#include <ostream>
#include <vector>
#include "matrix.h"

template <class T>
class Matrix;

template <class T>
class SymmetricTriangularMatrix
{
private:
    // attributes
    unsigned int N = 0;
    T* matrix;
    unsigned int computeSize();
    unsigned int computePosition(unsigned int x, unsigned int y) const;

public:
    // constructors
    SymmetricTriangularMatrix() = default;
    SymmetricTriangularMatrix(unsigned int N);
    SymmetricTriangularMatrix(const SymmetricTriangularMatrix&) = default;
    ~SymmetricTriangularMatrix();

    // getter and setter
    T get(unsigned int x, unsigned int y) const;
    void set(unsigned int x, unsigned int y, T value);
    T getSize() const;

    // overloading operators
    T operator()(unsigned int x, unsigned int y) const { return get(x,y); }
    void operator()(unsigned int x, unsigned int y, T value) { set(x,y,value); }
    T operator[](unsigned int index) const;

    SymmetricTriangularMatrix<T> operator+(const SymmetricTriangularMatrix<T>& other);
    SymmetricTriangularMatrix<T> operator-(const SymmetricTriangularMatrix<T>& other);
    Matrix<T> operator*(const SymmetricTriangularMatrix<T>& other);

    SymmetricTriangularMatrix<T> operator+(T n);
    SymmetricTriangularMatrix<T> operator-(T n);
    SymmetricTriangularMatrix<T> operator*(T n);
    SymmetricTriangularMatrix<T> operator/(T n);

    SymmetricTriangularMatrix<T>& operator=(const SymmetricTriangularMatrix<T>& other);
    SymmetricTriangularMatrix<T>& operator=(T n);

    bool operator==(const SymmetricTriangularMatrix<T>& other) const;
    bool operator!=(const SymmetricTriangularMatrix<T>& other);

    // print full matrix
    void printFullMatrix();

    //print low triangular matrix
    void printTriangularMatrix();
};

#endif // SYMMETRICTRIANGULARMATRIX_H
