#include "./include/real.hpp"

int main() {
    Integer aa = 1;
    Rational a = "5/3";
    Real b(a);

    std::cout << b;
}