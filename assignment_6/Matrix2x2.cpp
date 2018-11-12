#include <iostream>
#include "utilities.h"
#include "Matrix2x2.h"

double Matrix2x2::get(int row, int col) const {
	return matrix[row][col];
}

void Matrix2x2::set(int row, int col, double value) {
	matrix[row][col] = value;
}

void Matrix2x2::print() {
	for (int i = 0; i < 2; i++) {
		std::cout << std::endl;
		for (int j = 0; j < 2; j++) {
			std::cout << doubleToString(matrix[i][j]) + "\t";
		}
	}
	std::cout << std::endl;
}

Matrix2x2::Matrix2x2() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (i == j) {
				matrix[i][j] = 1.0;
			}
			else {
				matrix[i][j] = 0.0;
			}
		}
	}
}

Matrix2x2::Matrix2x2(double e1, double e2, double e3, double e4) {
	matrix[0][0] = e1;
	matrix[0][1] = e2;
	matrix[1][0] = e3;
	matrix[1][1] = e4;
}

std::ostream& operator <<(std::ostream &os, const Matrix2x2 & matrix) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			os << matrix.get(i, j);
			os << "\t";
		}
		os << "\n";
	}
	return os;
}

Matrix2x2& Matrix2x2::operator +=(const Matrix2x2 &rhs) {
	double temp = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			temp = get(i,j) + rhs.get(i,j);
			set(i, j, temp);
		}
	}
	return *this;
}

Matrix2x2& Matrix2x2::operator -=(const Matrix2x2 &rhs) {
	double temp = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			temp = get(i, j) - rhs.get(i, j);
			set(i, j, temp);
		}
	}
	return *this;
}

Matrix2x2& Matrix2x2::operator +(const Matrix2x2& rhs) {
	Matrix2x2 returnMatrix(*this);
	returnMatrix += rhs;
	return returnMatrix;
}

Matrix2x2& Matrix2x2::operator -(const Matrix2x2& rhs) {
	Matrix2x2 returnMatrix(*this);
	returnMatrix -= rhs;
	return returnMatrix;
}

Matrix2x2 Matrix2x2::operator *(const Matrix2x2& rhs) {
	Matrix2x2 temp(0, 0, 0, 0);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				temp.matrix[i][j] += (matrix[i][k] * rhs.get(k, j));
			}
		}
	}
	return temp;
}

Matrix2x2& Matrix2x2::operator *=(const Matrix2x2& rhs) {
	Matrix2x2 temp = (*this) * rhs;
	*this = temp;
	return *this;
}

double Matrix2x2::det() const {
	double determinant = get(0,0) * get(1,1);
	determinant -= (get(0,1) * get(1,0));
	return determinant;
}

Matrix2x2 Matrix2x2::inv() const {
	Matrix2x2 inverse(0,0,0,0);
	if (det() == 0) {
		return inverse;
	}
	else {
		inverse.set(0, 0, (1/det())*get(1, 1));
		inverse.set(1, 1, (1/det())*get(0, 0));
		inverse.set(0, 1, (-1/det())*get(0, 1));
		inverse.set(1, 0, (-1/det())*get(1, 0));
		return inverse;
	}
}

Vector2 Matrix2x2::operator *(const Vector2& rhs) {
	double elem1 = get(0, 0)*rhs.get(0) + get(0, 1)*rhs.get(1);
	double elem2 = get(1, 0)*rhs.get(0) + get(1, 1)*rhs.get(1);
	Vector2 result(elem1, elem2);
	return result;
}

