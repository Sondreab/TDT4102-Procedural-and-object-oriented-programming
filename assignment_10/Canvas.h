#pragma once
#include <vector>
#include "Shape.h"

class Canvas {
private:
	std::vector<const Shape*> shapes;
public:
	void addShape(const Shape *shape);
	void rasterizeTo(Image &img);


};