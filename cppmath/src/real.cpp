#include "../include/real.hpp"

Real::Real(Integer whole, Rational fractional) { // doesn't work
	whole_ = whole;
	if (fractional.isFractionProper()) {
		whole_ = fractional.getNumerator() / fractional.getDenominator();
	}
	fractional_ = fractional;
}


Real::Real(const Rational& obj) { // doesn't work
	if (obj.isFractionProper()) {
		whole_ = 0;
		fractional_ = obj.getNumerator() / obj.getDenominator();
	}
}


Real::Real(const char* char_arr) { // doesn't work
	std::string str = static_cast<std::string>(char_arr);
	size_t del_pos = str.find('.');

	whole_ = Integer(str.substr(0, del_pos));
	fractional_ = Integer(str.substr(del_pos + 1));
}


Real::Real(double value) {

}


std::ostream& operator<<(std::ostream& out, const Real& obj) {
	return out << obj.whole_ << '.' << obj.fractional_;
}


std::istream& operator>>(std::istream& in, Real& obj) {
	std::string str;
	in >> str;
	obj = Real(str.c_str());
	return in;
}