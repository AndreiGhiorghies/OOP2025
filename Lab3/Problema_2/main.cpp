#include "Canvas.h"

int main() {
	//foloseste sistemul de axe xOy
	Canvas canvas(32, 32);
	
	canvas.DrawRect(4, 21, 10, 15, '#');
	canvas.FillRect(5, 20, 9, 16, '@');
	canvas.SetPoint(7, 18, '*');
	canvas.Print();
	canvas.Clear();

	canvas.DrawCircle(16, 16, 10, '#');
	canvas.FillCircle(16, 16, 9, '@');
	canvas.SetPoint(16, 16, '*');
	canvas.Print();
	canvas.Clear();

	canvas.DrawLine(2, 2, 10, 10, '#');
	canvas.Print();
}