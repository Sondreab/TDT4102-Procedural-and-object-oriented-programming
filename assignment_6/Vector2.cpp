#include <iostream>
#include <cmath>
#include "utilities.h"
#include "Matrix2x2.h"
#include "Vector2.h"


double Vector2::get(int elem) const {
	return vector[elem];
}

void Vector2::set(int elem, double value) {
	vector[elem] = value;
}

double Vector2::dot(const Vector2& rhs) const {
	return (vector[0] * rhs.vector[0]) + (vector[1] * rhs.vector[1]);
}

double Vector2::lengthSquared() const {
	return dot(*this);
}

double Vector2::length() const {
	return sqrt(lengthSquared());
}

Vector2::Vector2() {
	vector[0] = 0;
	vector[1] = 0;
}

Vector2::Vector2(double e1, double e2) {
	vector[0] = e1;
	vector[1] = e2;
}

std::ostream& operator <<(std::ostream &os, const Vector2 &vector) {
	os << "[";
	os << vector.get(0);
	os << ",";
	os << "\t";
	os << vector.get(1);
	os << "]";
	return os;
}

Vector2& Vector2::operator +=(const Vector2& rhs) {
	double temp1 = get(0) + rhs.get(0);
	double temp2 = get(1) + rhs.get(1);
	set(0, temp1); set(1, temp2);
	return *this;
}

Vector2& Vector2::operator -=(const Vector2& rhs) {
	double temp1 = get(0) - rhs.get(0);
	double temp2 = get(1) - rhs.get(1);
	set(0, temp1); set(1, temp2);
	return *this;
}

Vector2& Vector2::operator +(const Vector2& rhs) {
	Vector2 returnVector(*this);
	returnVector += rhs;
	return returnVector;
}

Vector2& Vector2::operator -(const Vector2& rhs) {
	Vector2 returnVector(*this);
	returnVector -= rhs;
	return returnVector;
}
