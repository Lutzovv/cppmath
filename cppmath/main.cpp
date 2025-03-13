#include "./include/real.hpp"

int main() {
    Integer aa = 1;
    Rational a = "5/3";
    Rational b = "1/2";
    Real c(a);
    Real d(b);

    std::cout << c * d;
}