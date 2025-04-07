#pragma once

float operator"" _Kelvin(const char* sir) {
	int nr = 0;
	for (int i = 0; sir[i]; i++)
		nr = nr * 10 + sir[i] - '0';
	return nr - 273.15;
}

float operator"" _Fahrenheit(const char* sir) {
	int nr = 0;
	for (int i = 0; sir[i]; i++)
		nr = nr * 10 + sir[i] - '0';
	return (nr - 32) / 1.8;
}