#include <cmath>
#include "Shape.h"

Shape::Shape(){
}

Shape::Shape(const Color &color) : shapeColor(color){
}

Line::Line() : Shape() {
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
}

Line::Line(const Color &color, unsigned int x1, unsigned int y1, unsigned int x2,
	unsigned int y2)
	: Shape(color)
	, x1(x1)
	, y1(y1)
	, x2(x2)
	, y2(y2){
}

void Line::draw(Image &image)
{
	double rate = (static_cast<double>(y2 - y1)) / (x2 - x1);

	
	if (abs(rate) <= 1)
	{
		unsigned int x = x1;
		while (x <= x2)
		{
			unsigned int y = ((static_cast<double>(y2-y1))/(x2-x1))*(x - x1) + y1;
			image.setPixelColor(x, y, getColor());
			x++;
		}
	}
	else if(abs(rate) > 1){
		unsigned int y = y1;
		while (y <= y2)
		{
			unsigned int x = ((static_cast<double>(x2-x1))/(y2-y1))*(y - y1) + x1;
			image.setPixelColor(x, y, getColor());
			y++;
		}
	}
}

Rectangle::Rectangle() : Shape(){

}

Rectangle::Rectangle(const Color &color, unsigned int x1, unsigned int y1, unsigned int x2, 
	unsigned int y2) 
	: Shape(color)
	, x1(x1)
	, y1(y1)
	, x2(x2)
	, y2(y2){
}

void Rectangle::draw(Image &image)
{
	Color color = getColor();
	for (int b = x1; b <= x2; b++)
	{
		image.setPixelColor(b, y1, color);
	}

	for (int t = x1; t <= x2; t++)
	{
		image.setPixelColor(t, y2, color);
	}

	for (int l = y1; l <= y2; l++)
	{
		image.setPixelColor(x1, l, color);
	}

	for (int r = y1; r <= y2; r++)
	{
		image.setPixelColor(x2, r, color);
	}
}

Circle::Circle() : Shape(){}

Circle::Circle(const Color &color, int x0, int y0, int r)
	: Shape(color)
	, x0(x0)
	, y0(y0)
	, r(r) {
}

void Circle::draw(Image &image) {
	for (int i = x0 - r; i <= r + x0; i++)
	{
		double y1 = std::sqrt(std::pow(r, 2) - pow((i - x0), 2)) + y0;
		double y2 = -(std::sqrt(std::pow(r, 2) - pow((i - x0), 2))) + y0;
		image.setPixelColor(i, y1, getColor());
		image.setPixelColor(i, y2, getColor());
	}

	for (int j = y0 - r; j <= r + y0; j++)
	{
		double x1 = std::sqrt(std::pow(r, 2) - pow((j - y0), 2)) + x0;
		double x2 = -(std::sqrt(std::pow(r, 2) - pow((j - y0), 2))) + x0;
		image.setPixelColor(x1, j, getColor());
		image.setPixelColor(x2, j, getColor());
	}
}