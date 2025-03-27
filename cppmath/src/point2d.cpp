#include "../include/point2d.hpp"

//set

void point2d::setX(const Real& x) {
	x_ = x;
}


void point2d::setY(const Real& y) {
	y_ = y;
}


//get

Real point2d::getX() const {
	return x_;
}


Real point2d::getY() const {
	return y_;
}


//operators

bool operator==(const point2d& a, const point2d& b) {
	return (a.x_ == b.x_) && (a.y_ == b.y_);
}


bool operator!=(const point2d& a, const point2d& b) {
	return !(a == b);
}


//is

bool point2d::isIdenticalPoints(const point2d& obj) {
	return *this == obj;
}


//get

Real point2d::distanceBetweenPoints(const point2d& a, const point2d& b) {
	Real x = b.x_ - a.x_;
	Real y = b.y_ - a.y_;
	return Real::sqrt((x * x) + (y * y));
}


//input/output

std::ostream& operator<<(std::ostream& out, const point2d& obj) {
	return out << obj.x_ << " " << obj.y_;
}