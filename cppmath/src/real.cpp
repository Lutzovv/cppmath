#include "../include/real.hpp"

Real::Real(Integer whole, Integer fractional) {
	whole_ = whole;
	fractional.setSign(false);
	fractional_ = fractional;
}


Real::Real(Rational obj) {
	
}


Real::Real(const char* char_arr) {
	std::string str = static_cast<std::string>(char_arr);
	int del_pos = str.find('.');

	whole_ = std::stoi(str.substr(0, del_pos));
	fractional_ = std::stoi(str.substr(del_pos + 1));
}


std::ostream& operator<<(std::ostream& out, const Real& obj) {
	std::cout << obj.whole_ << '.' << obj.fractional_;
}


std::istream& operator>>(std::istream& in, Real& obj) {
	std::string str;
	in >> str;
	obj = Real(str.c_str());
	return in;
}