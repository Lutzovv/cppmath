#include "../include/Matrix.hpp"

//template<typename Type, unsigned long long Coll, unsigned long long Row>
//Matrix<Type, Coll, Row>::Matrix() {
//	/*for (size_t i = 0; i < Coll; i++) {
//		for (size_t j = 0; j < Row; j++) {
//			data_[i][j] = Type{1};
//		}
//	}*/
//	data_[Coll][Row];
//}


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
Type& Matrix<Type, Coll, Row>::operator()(unsigned long long i, unsigned long long j) {
	return data_[i][j];
}


template<typename Type, unsigned long long Coll, unsigned long long Row>
const Type& Matrix<Type, Coll, Row>::operator()(unsigned long long i, unsigned long long j) const {
	return data_[i][j];
}



//template<typename Type, unsigned long long Coll, unsigned long long Row>
//Type* Matrix<Type, Coll, Row>::operator[](unsigned long long i) {
//	if (i >= Coll) {
//		throw std::out_of_range("Row index out of range");
//	}
//	return data_[i];
//}
//
//
//template<typename Type, unsigned long long Coll, unsigned long long Row>
//const Type* Matrix<Type, Coll, Row>::operator[](unsigned long long i) const {
//	if (i >= Coll) {
//		throw std::out_of_range("Row index out of range");
//	}
//	return data_[i];
//}


template<typename Type, unsigned long long Coll, unsigned long long Row>
Type& Matrix<Type, Coll, Row>::at(unsigned long long i, unsigned long long j) {
	if (i >= Coll || j >= Row) {
		throw std::out_of_range("Index out of range");
	}
	return data_[i][j];
}


template<typename Type, unsigned long long Coll, unsigned long long Row>
const Type& Matrix<Type, Coll, Row>::at(unsigned long long i, unsigned long long j) const {
	if (i >= Coll || j >= Row) {
		throw std::out_of_range("Index out of range");
	}
	return data_[i][j];
}


//template<typename Type, unsigned long long Coll, unsigned long long Row>
//std::ostream& operator<< (std::ostream& out, const Matrix<Type, Coll, Row>& obj) {
//	for (int i = 0; i < Coll; i++) {
//		for (int j = 0; j < Row; j++) {
//			out << obj[i][j] << " ";
//		}
//		out << "\n";
//	}
//	return out;
//}