#ifndef _INTEGER_HPP_
#define _INTEGER_HPP_

#include "iostream"
#include "string"
#include "cmath"

class Integer {
public:

    //constructor

    Integer() : Integer(false, 0u) {}
    Integer(bool sign, unsigned units) : sign_(sign), units_(units) {};
    Integer(bool sign, int units) : sign_(sign), units_(units) {};
    Integer(int number);
    Integer(std::string str);
    Integer(const char* char_arr);


    //set

    void setSign(bool sign);
    void setUnits(unsigned units);

    
    //get

    bool getSign() const;
    unsigned getUnits() const;

    
    //is

    bool isOdd() const;
    bool isPositive() const;
    bool isSimple() const;
    bool isCoprime(Integer other) const;


    //get value

    unsigned findGCD(Integer other) const;
    unsigned findLCM(Integer other) const;

    
    //operators

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
    Integer operator+() const;
    Integer operator-() const;


    //input/output

    friend std::ostream& operator<<(std::ostream& out, const Integer& obj);
    friend std::istream& operator>>(std::istream& in, Integer& obj);

private:
    bool sign_;
    unsigned units_;
};

#endif // _INTEGER_HPP_
