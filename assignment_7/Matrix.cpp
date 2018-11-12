#include <iostream>
#include "Matrix.h"
#include "utilities.h"

Matrix::Matrix() {
	data = nullptr;
}


Matrix::Matrix(unsigned int nRows, unsigned int nColumns) :rows(nRows), columns(nColumns) {
	data = new double[nRows*nColumns];
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nColumns; j++) {
			data[index(i, j)] = 0.0;
		}
	}
}

Matrix::Matrix(unsigned int nRows):Matrix(nRows, nRows) {
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nRows; j++) {
			if (i == j) {
				data[index(i, j)] = 1.0;
			}
		}
	}
}

Matrix::~Matrix() {
	delete[] this->data;
	this->data = nullptr;
}

Matrix::Matrix(const Matrix & rhs) :rows(rhs.getHeight()), columns(rhs.getWidth()), data(nullptr) {
	if (rhs.isValid() == false) { return; }
	this->data = new double[rhs.getHeight()*rhs.getWidth()] {};
	for (int i = 0; i < rhs.getHeight(); i++) {
		for (int j = 0; j < rhs.getWidth(); j++) {
			this->data[index(i, j)] = rhs.get(i, j);
		}
	}
}

int Matrix::index(unsigned int row, unsigned int column) const {
	return row*rows + column;
}

void Matrix::print() {
	if (!isValid()) { std::cout << "Invalid matrix!" << std::endl; }
	for (int i = 0; i < rows; i++) {
		std::cout << std::endl;
		for (int j = 0; j < columns; j++) {
			std::cout << doubleToString(data[index(i,j)]) + "\t";
		}
	}
	std::cout << std::endl;
}

double Matrix::get(unsigned int row, unsigned int col) const {
	return data[index(row, col)];
}

void Matrix::set(unsigned int row, unsigned int col, double value) const {
	data[index(row, col)] = value;
}

int Matrix::getHeight() const {
	return rows;
}

int Matrix::getWidth() const {
	return columns;
}

bool Matrix::isValid() const {
	if (data == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

Matrix Matrix::operator =(Matrix rhs) {
	std::swap(rows, rhs.rows);
	std::swap(columns, rhs.columns);
	std::swap(data, rhs.data);
	return *this;
}

Matrix& Matrix::operator +=(Matrix &rhs) {
	if (this->rows != rhs.rows || this->columns != rhs.columns) {
		*this = Matrix();
	}
	else {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->columns; j++) {
				this->data[index(i, j)] += rhs.data[index(i, j)];
			}
		}
	}
	return *this;
}

Matrix Matrix::operator +(Matrix &rhs) {
	Matrix result(*this);
	result += rhs;
	return result;
}

Matrix& Matrix::operator -=(Matrix &rhs) {
	if (this->rows != rhs.rows || this->columns != rhs.columns) {
		*this = Matrix();
	}
	else {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->columns; j++) {
				this->data[index(i, j)] -= rhs.data[index(i, j)];
			}
		}
	}
	return *this;
}


Matrix Matrix::operator -(Matrix &rhs) {
		Matrix result(*this);
		result -= rhs;
		return result;
}







std::ostream& operator <<(std::ostream &os, const Matrix & matrix) {
	if (!matrix.isValid()) { 
		os << "Invalid matrix!";
	}
	else {
		for (int i = 0; i < matrix.getHeight(); i++) {
			for (int j = 0; j < matrix.getWidth(); j++) {
				os << matrix.get(i, j);
				os << "\t";
			}
			os << "\n";
		}
	}
	return os;
}