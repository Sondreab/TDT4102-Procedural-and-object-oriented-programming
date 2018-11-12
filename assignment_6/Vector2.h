#pragma once

class Vector2 {
private:

	double vector[2];

public:

	double get(int elem) const;
	void set(int elem, double value);

	double dot(const Vector2& rhs) const;
	double lengthSquared() const;
	double length() const;

	Vector2();
	Vector2(double e1, double e2);

	Vector2& operator +=(const Vector2& rhs);
	Vector2& operator -=(const Vector2& rhs);

	Vector2& operator +(const Vector2& rhs);
	Vector2& operator -(const Vector2& rhs);
};

std::ostream& operator <<(std::ostream &os, const Vector2 &vector);