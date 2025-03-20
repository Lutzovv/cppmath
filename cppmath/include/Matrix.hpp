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
	Matrix() {}
	Matrix(const Matrix& other) {
		for (size_t i = 0; i < Coll; i++) {
			for (size_t j = 0; j < Row; j++) {
				data_[i][j] = other.data_[i][j];
			}
		}
	}
	Matrix(Matrix&& obj);
	~Matrix() = default;


	unsigned long long size_coll() const { return Coll; };
	unsigned long long size_row() const { return Row; };


	const Matrix& operator=(const Matrix& other) {
		if (this == &other) {
			return *this;
		}
		for (size_t i = 0; i < Coll; i++) {
			for (size_t j = 0; j < Row; j++) {
				data_[i][j] = other.data_[i][j];
			}
		}
		return *this;
	}


	const Matrix& operator=(Matrix&& other) {
		for (size_t i = 0; i < Coll; i++) {
			for (size_t j = 0; j < Row; j++) {
				data_[i][j] = other.data_[i][j];
			}
		}
		return *this;
	}

	friend const Matrix<Type, Coll, Row> operator+(const Matrix& a, const Matrix& b) {
		if ((a.size_coll() == b.size_coll()) && (a.size_row() == b.size_row())) {
			Matrix<Type, Coll, Row> res;
			
			for (size_t i{}; i < a.size_coll(); i++) {
				for (size_t j{}; j < a.size_row(); j++) {
					res[i][j] = a[i][j] + b[i][j];
				}
			}
			return res;
		}
		else
		{
			std::cout << "������� ������ ���� ����������� �������!";
			::exit(-1);
		}
	}

	friend const Matrix<Type, Coll, Row> operator-(const Matrix& a, const Matrix& b) {
		if ((a.size_coll() == b.size_coll()) && (a.size_row() == b.size_row())) {
			Matrix<Type, Coll, Row> res;

			for (size_t i{}; i < a.size_coll(); i++) {
				for (size_t j{}; j < a.size_row(); j++) {
					res[i][j] = a[i][j] - b[i][j];
				}
			}
			return res;
		}
		else
		{
			std::cout << "������� ������ ���� ����������� �������!";
			::exit(-1);
		}
	}


	friend const Matrix<Type, Coll, Row> operator*(const Matrix& a, const Matrix& b) {
		Matrix<Type, Coll, Row> res;

		for (size_t i = 0; i < Coll; i++) {
			for (size_t j = 0; j < Row; j++) {
				res[i][j] = 0;
				for (size_t k = 0; k < Row; k++) {
					res[i][j] += data_[i][k] * b[k][j];
				}
			}
		}
		return res;
	}


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
	friend bool operator<=(const Matrix&, const Matrix&);

	Type& operator()(unsigned long long i, unsigned long long j) {
		return data_[i][j];
	}


	const Type& operator()(unsigned long long i, unsigned long long j) const {
		return data_[i][j];
	}

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

	Type& at(unsigned long long i, unsigned long long j) {
		if (i >= Coll || j >= Row) {
			throw std::out_of_range("Index out of range");
		}
		return data_[i][j];
	}


	const Type& at(unsigned long long i, unsigned long long j) const {
		if (i >= Coll || j >= Row) {
			throw std::out_of_range("Index out of range");
		}
		return data_[i][j];
	}


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