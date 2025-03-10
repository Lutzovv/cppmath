#include "../include/real.hpp"

Real::Real(Integer whole, Rational fractional) {
	whole_ = whole;
	if (!fractional.isFractionProper()) {
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
		whole_ = 0;
		fractional_ = obj;
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


Real::Real(double value) {

}


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


// input/output

std::ostream& operator<<(std::ostream& out, const Real& obj) {
	if (obj.fractional_.getNumerator() == 0)
	{
		return out << obj.whole_ << ".0";
	}
	return out << obj.whole_ << '.' << obj.fractional_;
}


//std::istream& operator>>(std::istream& in, Real& obj) {
//	std::string str;
//	in >> str;
//	obj = Real(str.c_str());
//	return in;
//}