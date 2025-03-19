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
	Matrix() {
		for (size_t i = 0; i < Coll; i++) {
			for (size_t j = 0; j < Row; j++) {
				data_[i][j] = Type{};
			}
		}
	}
	Matrix(const Matrix& other);
	Matrix(Matrix&& obj);
	~Matrix() = default;


	unsigned long long size_coll() const { return Coll; };
	unsigned long long size_row() const { return Row; };


	/*const Matrix& operator=(const Matrix& other);
	const Matrix& operator=(Matrix&& other);*/

	friend const Matrix& operator+(const Matrix& a, const Matrix& b) {
		if ((a.size_coll == b.size_coll) && (a.size_row == b.size_row)) {
			unsigned long long c = a.size_coll();
			Matrix<Type, c, a.size_row()> res;

			for (int i{}; i < a.size_coll(); i++) {
				for (int j{}; j < a.size_row(); j++) {
					res[i][j] = a[i][j] + b[i][j];
				}
			}
			return res;
		}
		else
		{
			throw "ћатрицы должны быть одинакового размера!";
		}
	}
	/*friend const Matrix& operator-(const Matrix&, const Matrix&);
	friend const Matrix& operator*(const Matrix&, const Matrix&);
	friend const Matrix& operator/(const Matrix&, const Matrix&);
	friend const Matrix& operator^(const Matrix&, const Matrix&);

	friend const Matrix& operator+=(const Matrix&, const Matrix&);
	friend const Matrix& operator-=(const Matrix&, const Matrix&);
	friend const Matrix& operator*=(const Matrix&, const Matrix&);
	friend const Matrix& operator/=(const Matrix&, const Matrix&);

	friend bool operator==(const Matrix&, const Matrix&);
	friend bool operator!=(const Matrix&, const Matrix&);
	friend bool operator>(const Matrix&, const Matrix&);
	friend bool operator<(const Matrix&, const Matrix&);
	friend bool operator>=(const Matrix&, const Matrix&);
	friend bool operator<=(const Matrix&, const Matrix&);*/

	Type& operator()(unsigned long long, unsigned long long);
	const Type& operator()(unsigned long long, unsigned long long) const;

	Type* operator[](unsigned long long i) {
		if (i >= Coll) {
			throw std::out_of_range("Row index out of range");
		}
		return data_[i];
	}
	const Type* operator[](unsigned long long i) const {
		if (i >= Coll) {
			throw std::out_of_range("Row index out of range");
		}
		return data_[i];
	}

	Type& at(unsigned long long, unsigned long long);
	const Type& at(unsigned long long, unsigned long long) const;

	friend std::ostream& operator<< (std::ostream& out, const Matrix& obj) {
		for (int i = 0; i < Coll; i++) {
			for (int j = 0; j < Row; j++) {
				out << obj[i][j] << " ";
			}
			out << "\n";
		}
		return out;
	};
	friend std::istream& operator>> (std::istream & in, const Matrix & obj);

private:
	Type data_[Coll][Row];
};

namespace std {
	template<typename Type, unsigned long long Coll, unsigned long long Row>
	struct hash<Matrix<Type, Coll, Row>>
	{
		size_t operator()(const Matrix<Type, Coll, Row>& obj) {
			size_t result{};
			for (size_t i = 0; i < obj.size_row(); i++) {
				for (size_t j = 0; j < obj.size_coll(); j++) {
					result <<= 1;
					result ^= hash<Type>()(obj[i][j]);
				}
			}
			return result;
		}
	};
}

#endif // !_MATRIX_HPP_