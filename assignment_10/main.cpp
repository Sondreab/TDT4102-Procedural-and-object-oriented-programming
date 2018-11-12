#include <iostream>
#include "Image.h"
#include "Matrix.h"
#include "Shape.h"
//inkluder andre headerfiler du lager

int main(){

	Color crayolaFuchsia(193, 84, 193);
	Color white(255, 255, 255);
	Color red(255, 0, 0);
	Color green(0, 255, 0);
	Color blue(0, 0, 255);


	Image test(1001, 1001);
	test.fill(white);
	Circle A(blue, 500, 500, 400);
	Circle eye1(blue, 350, 700, 50);
	Circle eye2(blue, 650, 700, 50);
	Line leftCorner(blue, 300, 450, 400, 250);
	Line rightCorner(blue, 600, 250, 700, 450);
	Line left(blue, 400, 250, 450, 200);
	Line middle(blue, 450, 200, 550, 200);
	Line right(blue, 550, 200, 600, 250);
	A.draw(test);
	eye1.draw(test);
	eye2.draw(test);
	leftCorner.draw(test);
	rightCorner.draw(test);
	left.draw(test);
	right.draw(test);
	middle.draw(test);
	saveImage(test, "smiley.bmp");





return 0;
}
