#include "matrix.h"
#include "symmetrictriangularmatrix.h"
#include <iostream>

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int columns)
    : rows(rows), columns(columns), data(rows, std::vector<T>(columns))
{ }

template <class T>
Matrix<T>::Matrix(unsigned int rows)
    : rows(rows), columns(rows), data(rows, std::vector<T>(rows))
{ }

template <class T>
T& Matrix<T>::operator()(unsigned int row, unsigned int column)
{
    if (row >= rows || column >= columns)
    {
        throw std::out_of_range("index out of range.");
    }
    return data[row][column];
}

template <class T>
const T& Matrix<T>::operator()(unsigned int row, unsigned int column) const
{
    if (row >= rows || column >= columns)
    {
        throw std::out_of_range("index out of range.");
    }
    return data[row][column];
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) const
{
    if (columns != other.rows)
    {
        throw std::invalid_argument("matrix sizes do not match.");
    }

    unsigned int resultRows = rows;
    unsigned int resultColumns = other.columns;
    Matrix<T> result(resultRows, resultColumns);

    for (unsigned int i = 0; i < resultRows; ++i)
    {
        for (unsigned int j = 0; j < resultColumns; ++j)
        {
            T sum = 0;
            for (unsigned int k = 0; k < columns; ++k)
            {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }

    return result;
}

template <class T>
void Matrix<T>::print() const
{
    for (unsigned int i = 0; i < rows; ++i)
    {
        for (unsigned int j = 0; j < columns; ++j)
        {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <class T>
template <class U>
Matrix<T> Matrix<T>::operator*(const SymmetricTriangularMatrix<U> &symMatrix) const
{
    unsigned int N = symMatrix.getSize();

    if (columns != N)
    {
        throw std::invalid_argument("matrix sizes do not match.");
    }

    unsigned int resultRows = rows;
    unsigned int resultColumns = N;
    Matrix<T> result(resultRows, resultColumns);

    for (unsigned int i = 0; i < resultRows; ++i)
    {
        for (unsigned int j = 0; j < resultColumns; ++j)
        {
            T sum = 0;
            for (unsigned int k = 0; k < columns; ++k)
            {
                sum += (*this)(i, k) * symMatrix.get(k, j);
            }
            result(i, j) = sum;
        }
    }

    return result;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const SymmetricTriangularMatrix<T> &symMatrix) const
{
    if (columns != symMatrix.getSize())
    {
        throw std::invalid_argument("matrix sizes do not match.");
    }

    Matrix<T> result(rows, columns);

    for (unsigned int i = 0; i < rows; ++i)
    {
        for (unsigned int j = 0; j < columns; ++j)
        {
            result(i, j) = (*this)(i, j) + symMatrix.get(i, j);
        }
    }
    return result;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const SymmetricTriangularMatrix<T> &symMatrix) const
{
    if (columns != symMatrix.getSize())
    {
        throw std::invalid_argument("matrix sizes do not match.");
    }

    Matrix<T> result(rows, columns);

    for (unsigned int i = 0; i < rows; ++i)
    {
        for (unsigned int j = 0; j < columns; ++j)
        {
            result(i, j) = (*this)(i, j) - symMatrix.get(i, j);
        }
    }
    return result;
}