#include "../include/Matrix.hpp"

template<typename Type, unsigned long long Coll, unsigned long long Row>
Matrix<Type, Coll, Row>::Matrix() {
	for (size_t i = 0; i < Coll; i++) {
		for (size_t j = 0; j < Row; j++) {
			data_[i][j] = Type{};
		}
	}
}


template<typename Type, unsigned long long Coll, unsigned long long Row>
Matrix<Type, Coll, Row>::Matrix(const Matrix& other) {
	for (size_t i = 0; i < Coll; i++) {
		for (size_t j = 0; j < Row; j++) {
			data_[i][j] = other.data_[i][j];
		}
	}
}


template<typename Type, unsigned long long Coll, unsigned long long Row>
Matrix<Type, Coll, Row>::Matrix(Matrix&& other) {

}


template<typename Type, unsigned long long Coll, unsigned long long Row>
Type& Matrix::operator[](unsigned long long index) {
	return data_[index / Row][index % Row];
}


template<typename Type, unsigned long long Coll, unsigned long long Row>
const Type& operator[](unsigned long long index) const {
	return data_[index / Row][index % Row];
}


template<typename Type, unsigned long long Coll, unsigned long long Row>
Type& Matrix::at(unsigned long long i, unsigned long long j) {
	if (i >= Coll || j >= Row) {
		throw std::out_of_range("Index out of range");
	}
	return data_[i][j];
}


template<typename Type, unsigned long long Coll, unsigned long long Row>
const Type& at(unsigned long long i, unsigned long long j) const {
	if (i >= Coll || j >= Row) {
		throw std::out_of_range("Index out of range");
	}
	return data_[i][j];
}


template<typename Type, unsigned long long Coll, unsigned long long Row>
std::ostream& operator<< (std::ostream& out, const Matrix<Type, Coll, Row>& obj) {
	for (int i = 0; i < Coll; i++) {
		for (int j = 0; j < Row; j++) {
			out << obj[i][j] << " ";
		}
		out << "\n";
	}
	return out;
}