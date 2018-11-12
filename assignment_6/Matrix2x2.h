#pragma once
#include "Vector2.h"

class Matrix2x2 {
private:
	double matrix[2][2];

public:
	double get(int row, int col) const;
	void set(int row, int col, double value);
	void print();

	Matrix2x2();
	Matrix2x2(double e1, double e2, double e3, double e4);

	Matrix2x2& operator +=(const Matrix2x2& rhs);
	Matrix2x2& operator -=(const Matrix2x2& rhs);

	Matrix2x2& operator +(const Matrix2x2& rhs);
	Matrix2x2& operator -(const Matrix2x2& rhs);
	Matrix2x2 operator *(const Matrix2x2& rhs);
	Matrix2x2& operator *=(const Matrix2x2& rhs);

	double det() const;
	Matrix2x2 inv() const;

	Vector2 operator *(const Vector2& rhs);

};

std::ostream& operator <<(std::ostream &os, const Matrix2x2 &matrix);