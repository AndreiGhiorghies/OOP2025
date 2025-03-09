#include "Canvas.h"
#include <stdio.h>
#include <cstdarg>

Canvas::Canvas(int lines, int columns)
{
	this->lines = lines;
	this->columns = columns;
	canvas = new char* [lines];

	for (int i = 0; i < lines; i++) {
		canvas[i] = new char[columns];

		for (int j = 0; j < columns; j++)
			canvas[i][j] = ' ';
	}
}

void Canvas::set_pixel(int x, int y, char value)
{
	if(x >= 0 && y >= 0 && x < lines && y < columns)
		canvas[x][y] = value;
}

void Canvas::set_pixels(int count, ...)
{
	va_list args;
	va_start(args, count);

	while (count--) {
		int x = va_arg(args, int), y = va_arg(args, int);
		char val = va_arg(args, char);
		this->set_pixel(x, y, val);
	}

	va_end(args);
}

void Canvas::clear()
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			canvas[i][j] = ' ';
}

void Canvas::print() const
{
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) 
			printf("%c", canvas[i][j]);
		printf("\n");
	}
}
