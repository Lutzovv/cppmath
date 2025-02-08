#ifndef _RATIONAL_HPP_
#define _RATIONAL_HPP_

#include "integer.hpp"
#include "sstream"

class Rational {
public:
	//constructor

	Rational() : Rational(0, 0) {}
	Rational(Integer numerator, Integer denominator);
	Rational(
		int numerator,
		int denominator) :
		numerator_(numerator),
		denominator_(denominator) {};
	Rational(
		unsigned numerator,
		unsigned denominator) :
		numerator_(numerator),
		denominator_(denominator) {};
	Rational(const char* str);

	//set

	void setNumerator(Integer numerator);
	void setDenominator(Integer denominator);
	void setNumeratorSign(const bool sign);
	void setDenominatorSign(const bool sign);


	//get

	Integer getNumerator() const;
	Integer getDenominator() const;
	bool getNumeratorSign() const;
	bool getDenominatorSing() const;

	//is

	bool isFractionProper() const;
	bool isFractionPositive() const;

	//get modified

	Rational getReducingRational() const;
	Rational ractoinReplacement() const;

	//modify

	void reducingRational();

	//operators

	Rational operator+(const Rational& other) const;
	Rational operator-(const Rational& other) const;
	Rational operator*(const Rational& other) const;
	Rational operator/(const Rational& other) const;
	void operator+=(const Rational other);
	void operator-=(const Rational other);
	void operator*=(const Rational other);
	void operator/=(const Rational other);
	bool operator==(const Rational other) const;
	bool operator!=(const Rational other) const;
	bool operator>(const Rational other) const;
	bool operator<(const Rational other) const;
	bool operator>=(const Rational other) const;
	bool operator<=(const Rational other) const;
	Rational operator++();
	Rational operator++(int);
	Rational operator--();
	Rational operator--(int);


	friend std::istream& operator>>(std::istream& in, Rational& obj);
	friend std::ostream& operator<<(std::ostream& out, const Rational& obj);

private:
	Integer numerator_;
	Integer denominator_;
};

#endif // _RATIONAL_HPP_
