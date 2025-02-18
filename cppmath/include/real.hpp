#ifndef _REAL_HPP_
#define _REAL_HPP_

#include "rational.hpp"

class Real {
public:
    Real() : Real(0, 0) {}
    Real(Integer whole, Rational fractional);
    Real(const Rational& obj);
    Real(const char*);
    Real(double);
    Real( // doesn't work
        int whole,
        int fractional) :
        whole_(whole),
        fractional_(fractional) {};
    Real( // doesn't work
        unsigned whole,
        unsigned fractional) :
        whole_(whole),
        fractional_(fractional) {};


    //input/output

    friend std::ostream& operator<<(std::ostream& out, const Real& obj);
    friend std::istream& operator>>(std::istream& in, Real& obj);

private:
	Integer whole_;
    Rational fractional_;
};

#endif // !_REAL_HPP_
