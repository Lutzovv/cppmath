#include "./include/real.hpp"
#include "./include/Matrix.hpp"

int main() {
    system("chcp 1251>NUL");

    Integer c = 1;
    Rational a = "1/2";
    //Real c{ a, b };

    Matrix<Integer, 2, 2> mat1;
    mat1[0][0] = c; mat1[0][1] = c;
    mat1[1][0] = c; mat1[1][1] = c;

    Matrix<Integer, 2, 2> mat2;
    mat2[0][0] = c; mat2[0][1] = c;
    mat2[1][0] = c; mat2[1][1] = c;

    Matrix<Integer, 2, 2> mat3 = mat1 - mat2;

    std::cout << mat1 - mat2 << "\n";
}