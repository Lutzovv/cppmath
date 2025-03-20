#include "./include/real.hpp"
#include "./include/Matrix.hpp"

int main() {
    Integer a = 1;
    Rational c = "1/2";

    Matrix<Rational, 2, 2> mat1;
    mat1[0][0] = c; mat1[0][1] = c;
    mat1[1][0] = c; mat1[1][1] = c;

    Matrix<Rational, 2, 2> mat2;
    mat2[0][0] = c; mat2[0][1] = c;
    mat2[1][0] = c; mat2[1][1] = c;

    Matrix<Rational, 2, 2> mat3 = mat1 + mat2;

    std::cout << mat3;
}