#include "../include/rational.hpp"

//constructor

Rational::Rational(const char* char_arr) {
	std::string str = static_cast<std::string>(char_arr);
	size_t del_pos = str.find('/');

	numerator_ = Integer(str.substr(0, del_pos));
	denominator_ = Integer(str.substr(del_pos + 1));
}


Rational::Rational(Integer numerator, Integer denominator) {
	numerator_ = numerator;
	denominator_ = denominator;
}


//set

void Rational::setNumerator(Integer numerator) {
	numerator_ = numerator;
}


void Rational::setDenominator(Integer denominator) {
	denominator_ = denominator;
}


void Rational::setNumeratorSign(const bool sign) {
	numerator_.setSign(sign);
}


void Rational::setDenominatorSign(const bool sign) {
	numerator_.setSign(sign);
}


//get

Integer Rational::getNumerator() const {
	return numerator_;
}


Integer Rational::getDenominator() const {
	return denominator_;
}


bool Rational::getNumeratorSign() const {
	return numerator_.getSign();
}


bool Rational::getDenominatorSing() const {
	return denominator_.getSign();
}


//is

bool Rational::isFractionProper() const {
	return !(numerator_ > denominator_);
}


bool Rational::isFractionPositive() const {
	if (numerator_.getSign() == denominator_.getSign()) {
		return true;
	}
	else {
		return false;
	}
}


//get modified

Rational Rational::getReducingRational() const {
	Integer gcd = numerator_.findGCD(denominator_);
	return Rational(numerator_ / gcd, denominator_ / gcd);
}


Rational Rational::ractoinReplacement() const {
	Rational temp;
	temp.numerator_ = this->denominator_;
	temp.denominator_ = this->numerator_;
	return temp;
}


//modify

void Rational::reducingRational() {
	Integer gcd = numerator_.findGCD(denominator_);
	numerator_ /= gcd;
	denominator_ /= gcd;
}


//operators

Rational Rational::operator+(const Rational& other) const {
	Rational num1 = *this;
	Rational num2 = other;
	Integer temp;

	Integer lcm = denominator_.findLCM(num2.denominator_);

	num1.numerator_ = (lcm / num1.denominator_) * num1.numerator_;
	num2.numerator_ = (lcm / num2.denominator_) * num2.numerator_;

	temp = num1.numerator_ + num2.numerator_;
	if (num2.isFractionPositive()) {
		temp.setSign(true);
	}

	return Rational(temp, lcm);
}


Rational Rational::operator-(const Rational& other) const {
	Rational num1 = *this;
	Rational num2 = other;

	Integer lcm = denominator_.findLCM(num2.denominator_);

	num1.numerator_ = (lcm / num1.denominator_) * num1.numerator_;
	num2.numerator_ = (lcm / num2.denominator_) * num2.numerator_;

	Integer temp = num1.numerator_ - num2.numerator_;

	return Rational(temp, lcm);
}


Rational Rational::operator*(const Rational& other) const {
	Rational result;

	result.numerator_ = this->numerator_ * other.numerator_;
	result.denominator_ = this->denominator_ * other.denominator_;

	return result;
}


Rational Rational::operator/(const Rational& other) const {
	Rational result = *this * other.ractoinReplacement();

	return result;
}


void Rational::operator+=(const Rational other) {
	*this = *this + other;
}


void Rational::operator-=(const Rational other) {
	*this = *this - other;
}


void Rational::operator*=(const Rational other) {
	*this = *this * other;
}


void Rational::operator/=(const Rational other) {
	*this = *this / other;
}


bool Rational::operator==(const Rational other) const {

	Rational num1 = *this;
	Rational num2 = other;

	Integer lcm = denominator_.findLCM(num2.denominator_);

	num1.numerator_ = (lcm / num1.denominator_) * num1.numerator_;
	num2.numerator_ = (lcm / num2.denominator_) * num2.numerator_;

	return num1.numerator_ == num2.numerator_;
}


bool Rational::operator!=(const Rational other) const {
	return !(*this == other);
}


bool Rational::operator>(const Rational other) const {

	Rational num1 = *this;
	Rational num2 = other;

	Integer lcm = denominator_.findLCM(num2.denominator_);

	num1.numerator_ = (lcm / num1.denominator_) * num1.numerator_;
	num2.numerator_ = (lcm / num2.denominator_) * num2.numerator_;

	return num1.numerator_ > num2.numerator_;
}


bool Rational::operator<(const Rational other) const {
	return !(*this > other);
}


bool Rational::operator>=(const Rational other) const {

	Rational num1 = *this;
	Rational num2 = other;

	Integer lcm = denominator_.findLCM(num2.denominator_);

	num1.numerator_ = (lcm / num1.denominator_) * num1.numerator_;
	num2.numerator_ = (lcm / num2.denominator_) * num2.numerator_;

	return num1.numerator_ >= num2.numerator_;
}


bool Rational::operator<=(const Rational other) const {

	Rational num1 = *this;
	Rational num2 = other;

	Integer lcm = denominator_.findLCM(num2.denominator_);

	num1.numerator_ = (lcm / num1.denominator_) * num1.numerator_;
	num2.numerator_ = (lcm / num2.denominator_) * num2.numerator_;

	return num1.numerator_ <= num2.numerator_;
}


Rational Rational::operator++() {
	this->numerator_++;
	return *this;
}


Rational Rational::operator++(int) {
	Rational temp = *this;
	this->numerator_++;
	return temp;
}


Rational Rational::operator--() {
	this->numerator_--;
	return *this;
}


Rational Rational::operator--(int) {
	Rational temp = *this;
	this->numerator_--;
	return temp;
}


Rational Rational::operator+() const {
	if (denominator_.getSign() == false) {
		return Rational(numerator_, denominator_);
	}
	return Rational(+numerator_, denominator_);
}


Rational Rational::operator-() const {
	if (denominator_.getSign() == true) {
		return Rational(numerator_, denominator_);
	}
	return Rational(-numerator_, denominator_);
}


std::istream& operator>>(std::istream& in, Rational& obj) {
	std::string str;
	in >> str;
	obj = Rational(str.c_str());
	return in;
}


std::ostream& operator<<(std::ostream& out, const Rational& obj) {
	return out << obj.numerator_ << "/" << obj.denominator_;
}
