#include "../include/integer.hpp"

Integer::Integer(int number) {
    if (number < 0) {
        sign_ = true;
        units_ = std::abs(number);
    }
    else {
        sign_ = false;
        units_ = static_cast<unsigned>(number);
    }
}

Integer::Integer(const std::string& str) : Integer(std::stoi(str)) {}

Integer::Integer(const char* char_arr) : Integer(std::stoi(char_arr)) {}


void Integer::setSign(bool sign) {
    this->sign_ = sign;
}


void Integer::setUnits(unsigned units) {
    this->units_ = units;
}


bool Integer::getSign() const {
    return sign_;
}


unsigned Integer::getUnits() const {
    return units_;
}


bool Integer::isOdd() const {
    return bool(units_ % 2);
}


bool Integer::isPositive() const {
    return !sign_;
}


bool Integer::isSimple() const {
    if (units_ < 2) return false;
    for (int i = 2; i <= sqrt(getUnits()); i++) {
        if (getUnits() % i == 0) {
            return false;
        }
    }
    return true;
}


unsigned Integer::findGCD(Integer other) const {
    unsigned a = getUnits();
    unsigned b = other.getUnits();

    while (b != 0) {
        unsigned temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


unsigned Integer::findLCM(Integer other) const {
    return (getUnits() * other.getUnits()) / findGCD(other);
}


bool Integer::isCoprime(Integer other) const {
    return findGCD(other) == 1 ? true : false;
}


Integer operator+(const Integer& a, const Integer& b) {
    if (a.sign_ == b.sign_) {
        return Integer(a.sign_, a.units_ + b.units_);
    }
    else {
        if (a.units_ >= b.units_) {
            return Integer(a.sign_, a.units_ - b.units_);
        }
        else {
            return Integer(b.sign_, b.units_ - a.units_);
        }
    }
}


Integer operator-(const Integer& a, const Integer& b) {
    return a + Integer(!b.sign_, b.units_);
}


Integer operator*(const Integer& a, const Integer& b) {
    if (b.units_ == 0) {
        return 0;
    }

    if (a.sign_ == b.sign_) {
        return a.units_ * b.units_;
    }
    return (a.units_ * b.units_) * -1;
}


Integer operator/(const Integer& a, const Integer& b) {
    if (b.units_ == 0) {
        return 0;
    }

    if (a.sign_ == b.sign_) {
        return a.units_ / b.units_;
    }
    return (a.units_ / b.units_) * -1;
}


Integer operator%(const Integer& a, const Integer& b) {
    if (b.units_ == 0) {
        return 0;
    }

    return Integer(((b * (a / b)) - a) * -1);
}


void Integer::operator+=(Integer& other) {
    *this = *this + other;
}


void Integer::operator-=(Integer& other) {
    *this = *this - other;
}


void Integer::operator*=(Integer& other) {
    *this = *this * other;
}


void Integer::operator/=(Integer& other) {
    *this = *this / other;
}


void Integer::operator%=(Integer& other) {
    *this = *this % other;
}


bool operator==(const Integer& a, const Integer& b) {
    if (a.sign_ && b.sign_) {
        return a.units_ == b.units_;
    }
    else if (a.sign_ == true && b.sign_ == false) {
        return false;
    }
    else if (a.sign_ == false && b.sign_ == true) {
        return true;
    }
}


bool operator!=(const Integer& a, const Integer& b) {
    if (!(a.sign_ && b.sign_)) {
        return !(a.units_ == b.units_);
    }
    else if (a.sign_ == true && b.sign_ == false) {
        return true;
    }
    else if (a.sign_ == false && b.sign_ == true) {
        return false;
    }
}


bool operator>=(const Integer& a, const Integer& b) {
    if (!(a.sign_ && b.sign_)) {
        return a.units_ >= b.units_;
    }
    else if (a.sign_ == true && b.sign_ == false) {
        return false;
    }
    else if (a.sign_ == false && b.sign_ == true) {
        return true;
    }
}


bool operator<=(const Integer& a, const Integer& b) {
    if (!(a.sign_ && b.sign_)) {
        return a.units_ <= b.units_;
    }
    else if (a.sign_ == true && b.sign_ == false) {
        return true;
    }
    else if (a.sign_ == false && b.sign_ == true) {
        return false;
    }
}


bool operator>(const Integer& a, const Integer& b) {
    if (!(a.sign_ && b.sign_)) {
        return a.units_ > b.units_;
    }
    else if (a.sign_ == true && b.sign_ == false) {
        return false;
    }
    else if (a.sign_ == false && b.sign_ == true) {
        return true;
    }
}


bool operator<(const Integer& a, const Integer& b) {
    if (!(a.sign_ && b.sign_)) {
        return !(a.units_ < b.units_);
    }
    else if (a.sign_ == true && b.sign_ == false) {
        return true;
    }
    else if (a.sign_ == false && b.sign_ == true) {
        return false;
    }
}


Integer Integer::operator++() {
    if (sign_) {
        if (units_ == 1 || units_ == 0) {
            sign_ = false;
            units_ -= 1;
        }
        else {
            units_ += 1;
        }
    }
    else {
        units_ += 1;
    }
    return *this;
}


Integer Integer::operator++(int) {
    Integer copy{ *this };
    if (sign_) {
        if (units_ == 1 || units_ == 0) {
            sign_ = false;
            units_ -= 1;
        }
        else {
            units_ += 1;
        }
    }
    else {
        units_ += 1;
    }
    return copy;
}


Integer Integer::operator--() {
    if (!sign_) {
        if (units_ == 1 || units_ == 0) {
            sign_ = true;
            units_ += 1;
        }
        else {
            units_ += 1;
        }
    }
    else {
        units_ += 1;
    }
    return *this;
}


Integer Integer::operator--(int) {
    Integer copy{ *this };
    if (!sign_) {
        if (units_ == 1 || units_ == 0) {
            sign_ = true;
            units_ += 1;
        }
        else {
            units_ += 1;
        }
    }
    else {
        units_ += 1;
    }
    return copy;
}


Integer Integer::operator+() const {
    return Integer(false, units_);
}


Integer Integer::operator-() const {
    return Integer(true, units_);
}



std::ostream& operator<<(std::ostream& out, const Integer& obj) {
    if (obj.sign_ == true) {
        return out << '-' << obj.units_;
    }
    return out << obj.units_;
}


std::istream& operator>>(std::istream& in, Integer& obj) {
    std::string str;

    in >> str;
    if (std::stoi(str) < 0) {
        obj.sign_ = true;
    }
    obj.units_ = ::abs(std::stoi(str));

    return in;
}
