#include "Math.h"
#include <stdio.h>

int main() {
	printf("%d\n", Math::Add(1, 2));
	printf("%d\n", Math::Add(1, 2, 3));
	printf("%d\n", Math::Add(5.4, 2.6));
	printf("%d\n", Math::Add(5.4, 2.6, 1.99));
	printf("%d\n", Math::Mul(4, 5));
	printf("%d\n", Math::Mul(4, 5, 10));
	printf("%d\n", Math::Mul(1.3, 4.3));
	printf("%d\n", Math::Mul(0.1, 10.55, 9.09));

	printf("%d\n", Math::Add(8, 5, 2, 4, 1, 6, 3, 7, 8));
	printf("%s\n", Math::Add("Un exemplu pentru ", "aceasta functie."));
}