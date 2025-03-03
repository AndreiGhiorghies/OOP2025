#include "NumberList.h"

void NumberList::Init() {
	count = 0;
}

bool NumberList::Add(int x) {
	if (count >= 10)
		return false;
	
	numbers[count] = x;
	count++;

	return true;
}

void NumberList::Sort() {
	for(int i = 0; i < count - 1; i++)
		for(int j = i + 1; j < count; j++)
			if (numbers[i] > numbers[j]) {
				numbers[i] = numbers[i] + numbers[j];
				numbers[j] = numbers[i] - numbers[j];
				numbers[i] = numbers[i] - numbers[j];
			}
}

void NumberList::Print() {
	if (count > 0)
		printf("%d", numbers[0]);
	for (int i = 1; i < count; i++)
		printf(", %d", numbers[i]);

	printf("\n");
}