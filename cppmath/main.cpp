#include "./include/real.hpp"
#include "./include/Matrix.hpp"

int main() {
    Matrix<int, 2, 2> mat1;
    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 1; mat1[1][1] = 2;

    Matrix<int, 2, 2> mat2;
    mat2[0][0] = 1; mat2[0][1] = 2;
    mat2[1][0] = 1; mat2[1][1] = 2;

    // 2 0
    // 0 0

    std::cout << mat1;
}