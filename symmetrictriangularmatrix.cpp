#include "symmetrictriangularmatrix.h"
#include "matrix.h"
#include <iostream>

// constructors
template <class T>
SymmetricTriangularMatrix<T>::SymmetricTriangularMatrix(unsigned int N)
{
    this->N=N;
    matrix = new T[computeSize()];
}

template <class T>
SymmetricTriangularMatrix<T>::~SymmetricTriangularMatrix()
{
    delete [] matrix;
}

// computes actual size of the matrix
template <class T>
unsigned int SymmetricTriangularMatrix<T>::computeSize()
{
    return (N * N + N) / 2 ;
}

template <class T>
T SymmetricTriangularMatrix<T>::getSize() const
{
    return N;
}

// computes place on the triangular matrix using the coordinates in full matrix
template <class T>
unsigned int SymmetricTriangularMatrix<T>::computePosition(unsigned int x, unsigned int y) const
{
    if (x >= N || y >= N)
    {
        throw std::out_of_range("index out of range.");
    }

    if (y > x)
    {
        // swapping the elements
        unsigned int temp = x;
        x=y;
        y=temp;
    }
    unsigned int position = ((x * (x + 1)) / 2) + y;
    return position;
}

// getter
template <class T>
T SymmetricTriangularMatrix<T>::get(unsigned int x, unsigned int y) const
{
    return matrix[computePosition(x,y)];
}

// setter
template <class T>
void SymmetricTriangularMatrix<T>::set(unsigned int x, unsigned int y, T value)
{
    matrix[computePosition(x,y)] = value;
}

// prints the full square matrix
template <class T>
void SymmetricTriangularMatrix<T>::printFullMatrix()
{
    for (unsigned int i = 0; i < N; i++)
    {
        for (unsigned int j = 0; j < N; j++)
        {
            std::cout << get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

// prints triangular matrix
template <class T>
void SymmetricTriangularMatrix<T>::printTriangularMatrix()
{
    for (unsigned int i = 0; i < N; i++)
    {
        for (unsigned int j = 0; j <= i; j++)
        {
            std::cout << get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

// overloaded operators
template <class T>
SymmetricTriangularMatrix<T> SymmetricTriangularMatrix<T>::operator+(const SymmetricTriangularMatrix<T> &other)
{
    if (N != other.N)
    {
        throw std::invalid_argument("matrix sizes do not match.");
    }
    SymmetricTriangularMatrix<T> result(N);
    for (unsigned int i = 0; i < N; i++)
    {
        for (unsigned int j = 0; j <= i; j++)
        {
            T sum = get(i, j) + other.get(i, j);
            result.set(i, j, sum);
        }
    }
    return result;
}

template <class T>
SymmetricTriangularMatrix<T> SymmetricTriangularMatrix<T>::operator-(const SymmetricTriangularMatrix<T> &other)
{
    if (N != other.N)
    {
        throw std::invalid_argument("matrix sizes do not match.");
    }
    SymmetricTriangularMatrix<T> result(N);
    for (unsigned int i = 0; i < N; i++)
    {
        for (unsigned int j = 0; j <= i; j++)
        {
            T sum = get(i, j) - other.get(i, j);
            result.set(i, j, sum);
        }
    }
    return result;
}

template <class T>
Matrix<T> SymmetricTriangularMatrix<T>::operator*(const SymmetricTriangularMatrix<T> &other)
{
    if (this->getSize() != other.getSize())
    {
        throw std::invalid_argument("matrix sizes do not match.");
    }

    unsigned int rows = this->getSize();
    Matrix<T> result(rows);

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < rows; j++)
        {
            T sum = 0;
            for (unsigned int k = 0; k < rows; k++)
            {
                sum += (*this)(i, k) * other(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}

template <class T>
SymmetricTriangularMatrix<T> SymmetricTriangularMatrix<T>::operator+(T n)
{
    SymmetricTriangularMatrix<T> result(N);
    for (unsigned int i = 0; i < N; i++)
    {
        for (unsigned int j = 0; j <= i; j++)
        {
            T sum = get(i, j) + n;
            result.set(i, j, sum);
        }
    }
    return result;
}

template <class T>
SymmetricTriangularMatrix<T> SymmetricTriangularMatrix<T>::operator-(T n)
{
    SymmetricTriangularMatrix<T> result(N);
    for (unsigned int i = 0; i < N; i++)
    {
        for (unsigned int j = 0; j <= i; j++)
        {
            T sum = get(i, j) - n;
            result.set(i, j, sum);
        }
    }
    return result;
}

template <class T>
SymmetricTriangularMatrix<T> SymmetricTriangularMatrix<T>::operator*(T n)
{
    SymmetricTriangularMatrix<T> result(N);
    for (unsigned int i = 0; i < N; i++)
    {
        for (unsigned int j = 0; j <= i; j++)
        {
            T sum = get(i, j) * n;
            result.set(i, j, sum);
        }
    }
    return result;
}

template <class T>
SymmetricTriangularMatrix<T> SymmetricTriangularMatrix<T>::operator/(T n)
{
    SymmetricTriangularMatrix<T> result(N);
    for (unsigned int i = 0; i < N; i++)
    {
        for (unsigned int j = 0; j <= i; j++)
        {
            T sum = get(i, j) / n;
            result.set(i, j,sum);
        }
    }
    return result;
}

template <class T>
bool SymmetricTriangularMatrix<T>::operator==(const SymmetricTriangularMatrix<T> &other) const
{
    if (N != other.N)
    {
        return false;
    }
    for (unsigned int i = 0; i < N; i++)
    {
        for (unsigned int j = 0; j <= i; j++)
        {
            if (get(i, j) != other.get(i, j))
            {
                return false;
            }
        }
    }
    return true;
}

template <class T>
bool SymmetricTriangularMatrix<T>::operator!=(const SymmetricTriangularMatrix<T> &other)
{
    return !(*this == other);
}

template <class T>
SymmetricTriangularMatrix<T>& SymmetricTriangularMatrix<T>::operator=(const SymmetricTriangularMatrix<T> &other)
{
    if (this == &other)
    {
        return *this;
    }
    if (N != other.N)
    {
        delete[] matrix;
        N = other.N;
        matrix = new T[computeSize()];
    }
    std::copy(other.matrix, other.matrix + computeSize(), matrix);
    return *this;
}

template <class T>
SymmetricTriangularMatrix<T>& SymmetricTriangularMatrix<T>::operator=(T n)
{
    for (unsigned int i = 0; i < N; i++)
    {
        for (unsigned int j = 0; j <= i; j++)
        {
            set(i, j, n);
        }
    }
    return *this;
}

template <class T>
T SymmetricTriangularMatrix<T>::operator[](unsigned int index) const
{
    if (index >= N)
    {
        throw std::out_of_range("index out of range.");
    }
    return matrix[index];
}