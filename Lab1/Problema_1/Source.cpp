#include <iostream>

using namespace std;

int atoi_custom(char s[100]) {
	int nr = 0;
	for (int i = 0; i < 100 && s[i]; i++)
		if (s[i] >= '0' && s[i] <= '9')
			nr = nr * 10 + s[i] - '0';
	return nr;
}

void main2() {
	FILE* file;
	int suma = 0;
	char buffer[100];

	fopen_s(&file, "in.txt", "r");


	while (fgets(buffer, 100, file))
		suma += atoi_custom(buffer);

	printf("%d", suma);

	return 0;
}