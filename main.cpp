#include "symmetrictriangularmatrix.cpp"
#include "matrix.cpp"

using namespace std;

int main()
{
    // creates a 3*3 integer matrix initialized to zero
    SymmetricTriangularMatrix<double> matrix1(3);
    SymmetricTriangularMatrix<double> matrix2(3);
    SymmetricTriangularMatrix<double> matrix3(4);
    SymmetricTriangularMatrix<double> matrix4(3);

    matrix1(0,0,1);
    matrix1(0,1,2);
    matrix1(0,2,3);
    matrix1(1,1,4);
    matrix1(1,2,5);
    matrix1(2,2,6);

    matrix2(0,0,10);
    matrix2(0,1,10);
    matrix2(0,2,10);
    matrix2(1,1,10);
    matrix2(1,2,10);
    matrix2(2,2,10);

    matrix4(0,0,1);
    matrix4(0,1,2);
    matrix4(0,2,3);
    matrix4(1,1,4);
    matrix4(1,2,5);
    matrix4(2,2,6);


    Matrix<double> matrixA(3, 3);
    matrixA(0, 0) = 15;
    matrixA(0, 1) = 15;
    matrixA(0, 2) = 15;
    matrixA(1, 0) = 15;
    matrixA(1, 1) = 15;
    matrixA(1, 2) = 15;
    matrixA(2, 0) = 15;
    matrixA(2, 1) = 15;
    matrixA(2, 2) = 15;

//    std::cout << "lower triangular matrix:" << std::endl;
//    matrix1.printTriangularMatrix();

//    std::cout << std::endl << "full symmetric matrix:" << std::endl;
//    matrix1.printFullMatrix();

//    SymmetricTriangularMatrix<double> resultPlus = matrix1 + matrix2;
//    std::cout << "result matrix plus matrix:" << std::endl;
//    resultPlus.printFullMatrix();

//    SymmetricTriangularMatrix<double> resultMinus = matrix2 - matrix1;
//    std::cout << "result matrix minus matrix:" << std::endl;
//    resultMinus.printFullMatrix();

//    Matrix<double> resultMultiply = matrix2 * matrix1;
//    std::cout << "full symmetric matrix:" << std::endl;
//    matrix2.printFullMatrix();
//    std::cout << "result symmetric matrix multiply symmetric matrix:" << std::endl;
//    resultMultiply.print();

//    SymmetricTriangularMatrix<double> resultPl = matrix1 + 1;
//    std::cout << "result matrix plus number:" << std::endl;
//    resultPl.printFullMatrix();

//    SymmetricTriangularMatrix<double> resultMin = matrix1 - 1;
//    std::cout << "result matrix minus number:" << std::endl;
//    resultMin.printFullMatrix();

//    SymmetricTriangularMatrix<double> resultMult = matrix1 * 2;
//    std::cout << "result matrix multiply by number:" << std::endl;
//    resultMult.printFullMatrix();

//    SymmetricTriangularMatrix<double> resultDiv = matrix1 / 5;
//    std::cout << "result matrix divide by number:" << std::endl;
//    resultDiv.printFullMatrix();

//    matrix1 = 5;
//    std::cout << "changed the whole matrix to one number matrix:" << std::endl;
//    matrix1.printFullMatrix();

//    matrix1 = matrix2;
//    std::cout << "changed the whole matrix to other matrix:" << std::endl;
//    matrix1.printFullMatrix();

//    if (matrix1 == matrix2) {
//        std::cout << "true" << std::endl;
//    }
//    else
//    {
//        std::cout << "false" << std::endl;
//    }

//    if (matrix1 != matrix2) {
//        std::cout << "true" << std::endl;
//    }
//    else
//    {
//        std::cout << "false" << std::endl;
//    }

//    if (matrix1 == matrix4) {
//        std::cout << "true" << std::endl;
//    }
//    else
//    {
//        std::cout << "false" << std::endl;
//    }
//
//    if (matrix1 != matrix4) {
//        std::cout << "true" << std::endl;
//    }
//    else
//    {
//        std::cout << "false" << std::endl;
//    }

//    std::cout << "usual matrix:" << std::endl;
//    matrixA.print();
//
//    std::cout << "multiply usual and usual matrix:" << std::endl;
//    Matrix<int> resultUsual = matrixA * matrixA;
//    resultUsual.print();
//
//    std::cout << "multiply usual and sym matrix:" << std::endl;
//    Matrix<int> resultSym1 = matrixA * matrix1;
//    resultSym1.print();
//
//    std::cout << "multiply matrices with different dimension:" << std::endl;
//    Matrix<int> resultSym2 = matrixA * matrix3;
//    resultSym2.print();

//    std::cout << "usual matrix + symmetric matrix" << std::endl;
//    Matrix<double> resultSum = matrixA + matrix2;
//    resultSum.print();
//
//    std::cout << "usual matrix - symmetric matrix" << std::endl;
//    Matrix<double> resultMin = matrixA - matrix2;
//    resultMin.print();

    return 0;
}
