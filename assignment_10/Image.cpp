#include "Image.h"

/*****************************************************
 * You _should_ change the functions in this file.   *
 * The following functions are provided so that      *
 * the code will compile, note however that the      *
 * program will not run before you have implemented  *
 * all the functions in this file.                   *
 *****************************************************/

Image::Image( unsigned int width, unsigned int height ) 
	: width(width)
	, height(height)
{
	data = new Pixel[width*height];
	for (int i = 0; i < width*height; i++)
	{
		data[i].red = 255;
		data[i].blue = 255;
		data[i].green = 255;
	}
}

Image::~Image()  {
	delete[] data;
	data = nullptr;
	width = 0;
	height = 0;
}

unsigned int Image::getWidth() const {
	return this->width;
}
unsigned int Image::getHeight() const  { 
	return this->height;
}

const Pixel * Image::getScanLine(unsigned int line) const  {
	return data+line*width;
}
Pixel * Image::getScanLine(unsigned int line) {
	return data+line*width;
}

Color Image::getPixelColor( unsigned int x, unsigned int y ) const {
	const Pixel *line;
	line = this->getScanLine(y);
	Pixel pixel = line[x];
	return pixel;
}
void Image::setPixelColor( unsigned int x, unsigned int y, const Color &color ) {
	Pixel *line;
	line = this->getScanLine(y);
	line[x] = color;
}

void Image::fill( const Color &color ) {
	for (int i = 0; i < width*height; i++)
	{
		data[i] = color;
	}
}