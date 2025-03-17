#pragma once
#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <iostream>
#include <type_traits>
#include <numeric>
#include <initializer_list>

template<typename Type, unsigned long long Coll, unsigned long long Row>
class Matrix {
public:
	Matrix();
	Matrix(const Matrix& other);
	Matrix(Matrix&& obj);
	~Matrix() = default;


	unsigned long long size_coll() const { return Coll };
	unsigned long long size_row() const { return Row };


	const Matrix& operator=(const Matrix& other);
	const Matrix& operator=(Matrix&& other);

	friend const Matrix& operator+(const Matrix&, const Matrx&);
	friend const Matrix& operator-(const Matrix&, const Matrx&);
	friend const Matrix& operator*(const Matrix&, const Matrx&);
	friend const Matrix& operator/(const Matrix&, const Matrx&);
	friend const Matrix& operator^(const Matrix&, const Matrx&);

	friend const Matrix& operator+=(const Matrix&, const Matrx&);
	friend const Matrix& operator-=(const Matrix&, const Matrx&);
	friend const Matrix& operator*=(const Matrix&, const Matrx&);
	friend const Matrix& operator/=(const Matrix&, const Matrx&);

	friend bool operator==(const Matrix&, const Matrix&) const;
	friend bool operator!=(const Matrix&, const Matrix&) const;
	friend bool operator>(const Matrix&, const Matrix&) const;
	friend bool operator<(const Matrix&, const Matrix&) const;
	friend bool operator>=(const Matrix&, const Matrix&) const;
	friend bool operator<=(const Matrix&, const Matrix&) const;

	Type& operator[](unsigned long long, unsigned long long);
	const Type& operator[](unsigned long long, unsigned long long) const;

	Type& at(unsigned long long, unsigned long long);
	const Type& at(unsigned long long, unsigned long long) const;

	friend std::ostream& operator<< (std::ostream & out, const Matrix & obj);
	friend std::istream& operator>> (std::istream & in, const Matrix & obj);

private:
	Type data_[Coll][Row];
};

namespace std {
	template<typename Type, unsigned long long Coll, unsigned long long Row>
	struct hash<Matrix<Type, Coll, Row>>
	{
		size_t operator()(Matrix<Type, unsigned long long, unsigned long long>& obj) {
			size_t result{};
			for (size_t i = 0; i < obj.rows(); i++) {
				for (size_t j = 0; j < obj.columns(); j++) {
					result <<= 1;
					result ^= hash<Type>()(obj[i][j]);
				}
			}
			return result;
		}
	};
}

#endif // !_MATRIX_HPP_
