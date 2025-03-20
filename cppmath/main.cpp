#include "./include/real.hpp"
#include "./include/Matrix.hpp"

int main() {
    Integer a = 1;
    Rational b = "1/2";
    Real c = {a, b};



    Matrix<Integer, 2, 2> mat1;
    mat1[0][0] = 2; mat1[0][1] = 2;
    mat1[1][0] = 2; mat1[1][1] = 2;

    Matrix<Integer, 2, 2> mat2;
    mat2[0][0] = 2; mat2[0][1] = 2;
    mat2[1][0] = 2; mat2[1][1] = 2;

    Matrix<Integer, 2, 2> mat3 = mat1 * mat2;

    std::cout << mat3;
}