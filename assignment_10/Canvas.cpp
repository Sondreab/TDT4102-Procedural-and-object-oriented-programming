#include "Canvas.h"

void Canvas::addShape(const Shape *shape) {
	this->shapes.push_back(shape);
}

void Canvas::rasterizeTo(Image &img) {
	for (int i = 0; i < shapes.size(); i++) {
		shapes[i]->draw(img);
	}
}