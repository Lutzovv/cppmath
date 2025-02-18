#include "./include/rational.hpp"

int main() {
    Rational a = "-1/2";
    Rational b = "2/2";

    std::cout << a + b << "\n";
    std::cout << b - a << "\n";
}