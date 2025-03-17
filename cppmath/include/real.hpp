#ifndef _REAL_HPP_
#define _REAL_HPP_

#include "rational.hpp"

class Real {
public:
    Real() : Real(0, 0) {}
    Real(Integer whole, Rational fractional);
    Real(const Rational& obj);
    //Real(const char*);
    //Real(Integer obj) : whole_(obj), fractional_(Integer(1)) {};
    Real(
        int whole,
        Rational fractional) :
        whole_(whole),
        fractional_(fractional) {};
    Real(
        unsigned whole,
        Rational fractional) :
        whole_(whole),
        fractional_(fractional) {};


    // get
    Integer getWhole() const;
    Rational getFractional() const;


    // set
    void setWhole(const Integer);
    void setFractional(const Rational);


    // is
    bool isDecimal() const;
    bool isSame(const Real& obj) const;
    bool isNegative() const;
    bool isPositive() const;


    //operators
    friend Real operator+(const Real&, const Real&);
    friend Real operator-(const Real&, const Real&);
    friend Real operator*(const Real&, const Real&);
    friend Real operator/(const Real&, const Real&);

    void operator+=(const Real& other);
    void operator-=(const Real& other);
    void operator*=(const Real& other);
    void operator/=(const Real& other);

    friend bool operator==(const Real&, const Real&);
    friend bool operator!=(const Real&, const Real&);
    friend bool operator>(const Real&, const Real&);
    friend bool operator<(const Real&, const Real&);
    friend bool operator>=(const Real&, const Real&);
    friend bool operator<=(const Real&, const Real&);

    Real operator+() const;
    Real operator-() const;


    // input/output
    friend std::ostream& operator<<(std::ostream& out, const Real& obj);
    friend std::istream& operator>>(std::istream& in, Real& obj);

private:
	Integer whole_;
    Rational fractional_;
};

#endif // !_REAL_HPP_
