#pragma once
#include <vector>
#include "Image.h"

class Shape {
private:
	Color shapeColor;

public:
	Shape();
	Shape(const Color &color);

	Color getColor() {
		return this->shapeColor;
	}

	virtual void draw(Image &image) = 0;
};

class Line : public Shape {
private:
	unsigned int x1, y1, x2, y2;
public:
	Line();
	Line(const Color &color, unsigned int x1, unsigned int y1, unsigned int x2,
		unsigned int y2);

	virtual void draw(Image &image);
};

class Rectangle : public Shape {
private:
	unsigned int x1, y1, x2, y2;
public:
	Rectangle();
	Rectangle(const Color &color, unsigned int x1, unsigned int y1, unsigned int x2,
		unsigned int y2);

	virtual void draw(Image &image);
};

class Circle : public Shape {
private:
	int x0, y0, r;
public:
	Circle();
	Circle(const Color &color, int x0, int y0, int r);

	virtual void draw(Image &image);
};

