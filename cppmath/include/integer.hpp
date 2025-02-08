#ifndef _INTEGER_HPP_
#define _INTEGER_HPP_

#include "iostream"
#include "string"

class Integer {
public:
    Integer() : Integer(false, 0u) {}
    Integer(bool sign, unsigned units) : sign_(sign), units_(units) {};
    Integer(bool sign, int units) : sign_(sign), units_(units) {};
    Integer(int number);
    Integer(std::string str);

    void setSign(bool sign);
    void setUnits(unsigned units);


    bool getSign() const;
    unsigned getUnits() const;


    bool isOdd() const;
    bool isPositive() const;
    bool isSimple() const;


    unsigned findGCD(Integer other) const;
    unsigned findLCM(Integer other) const;

    bool isCoprime(Integer other) const;


    Integer operator+() const;
    Integer operator-() const;
    Integer operator+(const Integer other) const;
    Integer operator-(const Integer other) const;
    Integer operator*(const Integer other) const;
    Integer operator/(const Integer other) const;
    Integer operator%(const Integer other) const;
    void operator+=(Integer other);
    void operator-=(Integer other);
    void operator*=(Integer other);
    void operator/=(Integer other);
    bool operator==(const Integer other) const;
    bool operator!=(const Integer other) const;
    bool operator>(const Integer other) const;
    bool operator<(const Integer other) const;
    bool operator>=(const Integer other) const;
    bool operator<=(const Integer other) const;
    Integer operator++();
    Integer operator++(int);
    Integer operator--();
    Integer operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Integer& obj);
    friend std::istream& operator>>(std::istream& in, Integer& obj);

private:
    bool sign_;
    unsigned units_;
};

#endif // _INTEGER_HPP_
