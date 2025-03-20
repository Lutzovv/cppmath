#include "../include/real.hpp"

Real::Real(Integer whole, Rational fractional) {
	whole_ = whole;
	if (fractional.isFractionProper()) {
		whole_ = whole_ + (fractional.getNumerator() / fractional.getDenominator());
		Integer newNumerator = fractional.getNumerator() % fractional.getDenominator();
		fractional_ = Rational(newNumerator, fractional.getDenominator());
	}
	else {
		fractional_ = fractional;
	}
}


Real::Real(const Rational& obj) {
	if (obj.isFractionProper()) {
		if (obj.isFractionProper()) {
			whole_ = whole_ + (obj.getNumerator() / obj.getDenominator());
			Integer newNumerator = obj.getNumerator() % obj.getDenominator();
			fractional_ = Rational(newNumerator, obj.getDenominator());
		}
		else {
			fractional_ = obj;
		}
	}
	else {
		whole_ = obj.getNumerator() / obj.getDenominator();
		Integer newNumerator = obj.getNumerator() % obj.getDenominator();
		if (newNumerator == 0) {
			fractional_ = Rational(0, 0);
		}
		else
		{
			fractional_ = Rational(newNumerator, obj.getDenominator());
		}
	}
}


//Real::Real(const char* char_arr) {
//	std::string str = static_cast<std::string>(char_arr);
//	size_t del_pos = str.find('.');
//
//	whole_ = Integer(str.substr(0, del_pos));
//	fractional_ = Integer(str.substr(del_pos + 1));
//}


// get

Integer Real::getWhole() const {
	return whole_;
}


Rational Real::getFractional() const {
	return fractional_;
}


// set

void Real::setWhole(const Integer obj) {
	whole_ = obj;
}


void Real::setFractional(const Rational obj) {
	fractional_ = obj;
}


// is

bool Real::isDecimal() const {
	Rational fractional = this->getFractional();

	if (fractional.getNumerator() == 0) {
		return true;
	}

	Integer denominator = fractional.getDenominator();

	while (denominator % Integer(2) == Integer(0)) {
		denominator = denominator / Integer(2);
	}
	while (denominator % Integer(5) == Integer(0)) {
		denominator = denominator / Integer(5);
	}

	return denominator == 1;
}


//is

bool Real::isSame(const Real& obj) const {
	return this == &obj;
}

bool Real::isNegative() const {
	return whole_.getSign() || fractional_.getNumeratorSign();
}

bool Real::isPositive() const {
	return !isNegative();
}


//operators

Real operator+(const Real& a, const Real& b) {
	Integer whole = a.getWhole() + b.getWhole();
	Rational fractional = a.getFractional() + b.getFractional();
	return Real(whole, fractional);
}


Real operator-(const Real& a, const Real& b) {
	Integer whole = a.getWhole() - b.getWhole();
	Rational fractional = a.getFractional() - b.getFractional();
	return Real(whole, fractional);
}


Real operator*(const Real& a, const Real& b) {
	Integer whole = a.getWhole() * b.getWhole();
	Rational fractional = a.getFractional() * b.getFractional();
	return Real(whole, fractional);
}


Real operator/(const Real& a, const Real& b) {
	Integer whole = a.getWhole() / b.getWhole();
	Rational fractional = a.getFractional() / b.getFractional();
	return Real(whole, fractional);
}


void Real::operator+=(const Real& other) {
	*this = *this + other;
}


void Real::operator-=(const Real& other) {
	*this = *this - other;
}


void Real::operator*=(const Real& other) {
	*this = *this * other;
}


void Real::operator/=(const Real& other) {
	*this = *this / other;
}


bool operator==(const Real& a, const Real& b) {
	return a.getWhole() == b.getWhole() && a.getFractional() == b.getFractional();
}


bool operator!=(const Real& a, const Real& b) {
	return !(a == b);
}


bool operator>(const Real& a, const Real& b) {
	if (a.getWhole() > b.getWhole()) {
		return true;
	}

	if (a.getWhole() == b.getWhole() &&
		a.getFractional() > b.getFractional()) {
		return true;
	}
	return false;
}


bool operator<(const Real& a, const Real& b) {
	return b > a;
}

bool operator>=(const Real& a, const Real& b) {
	return a > b || a == b;
}


bool operator<=(const Real& a, const Real& b) {
	return a < b || a == b;
}


Real Real::operator+() const {
	return *this;
}


Real Real::operator-() const {
	return Real(-whole_, -fractional_);
}

// input/output

std::ostream& operator<<(std::ostream& out, const Real& obj) {
	if (obj.fractional_.getNumerator() == 0)
	{
		return out << obj.whole_ << ".0";
	}
	return out << obj.whole_ << " (" << obj.fractional_ << ")";
}


//std::istream& operator>>(std::istream& in, Real& obj) {
//	std::string str;
//	in >> str;
//	obj = Real(str.c_str());
//	return in;
//}