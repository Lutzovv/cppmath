#include "./include/real.hpp"

int main() {
    Integer aa = 1;
    Rational a = "2/2";
    Rational b = "2/2";
    Real c(a);
    Real d(b);

    if (c == d) {
        std::cout << "true\n";
    }
    std::cout << c - d;
}