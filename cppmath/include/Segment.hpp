#pragma once
#ifndef _SEGMENT_HPP_
#define _SEGMENT_HPP_

#include "point2d.hpp"

class Segment {
public:
	Segment() : Segment(point2d(), point2d()) {}
	Segment(point2d p1, point2d p2);
    Segment(const Segment& other) : p1_(new point2d(*other.p1_)), p2_(new point2d(*other.p2_)) {}
    Segment(Segment&& other) noexcept : p1_(other.p1_), p2_(other.p2_) {
        other.p1_ = nullptr;
        other.p2_ = nullptr;
    }


private:
	point2d* p1_;
	point2d* p2_;
};

#endif // !_SEGMENT_HPP_
