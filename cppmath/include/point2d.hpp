#pragma once
#ifndef _POINT2D_HPP_
#define _POINT2D_HPP_

#include <cmath>
#include "real.hpp"

class point2d {
public:
	point2d() : point2d(Real("0/0"), Real("0/0")) {}
	point2d(Real x, Real y) : x_(x), y_(y) {}
	virtual ~point2d() = default;


	//set

	void setX(const Real& x);
	void setY(const Real& y);


	//get

	Real getX() const;
	Real getY() const;


	//operators

	friend bool operator==(const point2d&, const point2d&);
	friend bool operator!=(const point2d&, const point2d&);


	//is

	bool isIdenticalPoints(const point2d&);


	//get

	Real distanceBetweenPoints(const point2d&, const point2d&);


	//input/output

	friend std::istream& operator>>(std::istream& in, point2d& obj);
	friend std::ostream& operator<<(std::ostream& out, const point2d& obj);

private:
	Real x_;
	Real y_;
};

#endif // !_POIND2D_HPP_
