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
	unsigned long long size_coll() const { return Coll; };
	unsigned long long size_row() const { return Row; };

	template<unsigned long long CollB, unsigned long long RowB>
	friend const Matrix& operator+(const Matrix<Type, Coll, Row>& a, const Matrix<Type, CollB, RowB>& b) {
		if ((a.size_coll() == b.size_coll()) && (a.size_row() == b.size_row())) {
			Matrix<Type, std::min(Coll, CollB), std::min(Row, RowB)> res;
			
			for (size_t i{}; i < a.size_coll(); i++) {
				for (size_t j{}; j < a.size_row(); j++) {
					res[i][j] = a[i][j] + b[i][j];
				}
			}
			return res;
		}
		else {
			std::cout << "ћатрицы должны быть одинакового размера!";
			::exit(-1);
		}
	}


	template<unsigned long long CollB, unsigned long long RowB>
	friend const Matrix& operator-(const Matrix<Type, Coll, Row>& a, const Matrix<Type, CollB, RowB>& b) {
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
			std::cout << "ћатрицы должны быть одинакового размера!";
			::exit(-1);
		}
	}


	template<unsigned long long CollB, unsigned long long RowB>
	friend const Matrix& operator*(const Matrix<Type, Coll, Row>& a, const Matrix<Type, CollB, RowB>& b) {
		Matrix<Type, Coll, Row> res;

		for (size_t i = 0; i < Coll; i++) {
			for (size_t j = 0; j < Row; j++) {
				res[i][j] = 0;
				for (size_t k = 0; k < Row; k++) {
					res[i][j] = res[i][j] + (a[i][k] * b[k][j]);
				}
			}
		}
		return res;
	}


	template<unsigned long long CollB, unsigned long long RowB>
	friend const Matrix& operator/(const Matrix<Type, Coll, Row>& a, const Matrix<Type, CollB, RowB>& b) {
		
	}


	template<unsigned long long CollB, unsigned long long RowB>
	friend const Matrix& operator+=(Matrix<Type, Coll, Row>& a, const Matrix<Type, CollB, RowB>& b) {
		return a = a + b;
	}


	template<unsigned long long CollB, unsigned long long RowB>
	friend const Matrix& operator-=(Matrix<Type, Coll, Row>& a, const Matrix<Type, CollB, RowB>& b) {
		return a = a - b;
	}


	template<unsigned long long CollB, unsigned long long RowB>
	friend const Matrix& operator*=(const Matrix<Type, Coll, Row>& a, const Matrix<Type, CollB, RowB>& b) {
		return a = a * b;
	}


	template<unsigned long long CollB, unsigned long long RowB>
	friend const Matrix& operator/=(Matrix<Type, Coll, Row>& a, const Matrix<Type, CollB, RowB>& b) {
		return a = a / b;
	}


	template<unsigned long long CollB, unsigned long long RowB>
	friend bool operator==(const Matrix<Type, Coll, Row>& a, const Matrix<Type, CollB, RowB>& b) {
		if (a.size_coll() == b.size_coll() && a.size_row() == b.size_row()) {
			for (size_t i{}; i < a.size_coll(); i++) {
				for (size_t j{}; j < a.size_row(); j++) {
					if (a[i][j] != b[i][j]) {
						return false;
					}
				}
			}
			return true;
		}
		return false;
	}


	template<unsigned long long CollB, unsigned long long RowB>
	friend bool operator!=(const Matrix<Type, Coll, Row>& a, const Matrix<Type, CollB, RowB>& b) {
		return !(a == b);
	}


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
	}


	friend std::istream& operator>> (std::istream & in, const Matrix & obj);


	Type begin() { return data_[0][0]; }
	Type end() { return data_[Row][Coll]; }


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