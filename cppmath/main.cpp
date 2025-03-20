#include "./include/real.hpp"
#include "./include/Matrix.hpp"

int main() {
    Matrix<Integer, 2, 2> mat1;
    mat1[0][0] = 2; mat1[0][1] = 2;
    mat1[1][0] = 2; mat1[1][1] = 2;

    Matrix<Integer, 2, 2> mat2;
    mat2[0][0] = 2; mat2[0][1] = 2;
    mat2[1][0] = 2; mat2[1][1] = 2;

    Matrix<Integer, 2, 2> mat3 = mat1 + mat2;

    // 2 4
    // 2 4

    std::cout << mat1 + mat2;
}