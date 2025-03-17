#include "Sort.h"
#include <stdlib.h>
#include <ctime>
#include <cstdarg>
#include <stdio.h>
#include <algorithm>

Sort::Sort(int number_of_elements, int min_value, int max_value)
{
	srand(time(0));
	this->number_of_elements = number_of_elements;
	this->vector = new int[number_of_elements];

	for (int i = 0; i < number_of_elements; i++)
		this->vector[i] = min_value + rand() % (max_value - min_value + 1);
}

Sort::Sort(std::initializer_list<int> initList)
{
	this->number_of_elements = initList.size();
	this->vector = new int[this->number_of_elements];

	std::copy(initList.begin(), initList.end(), this->vector);
}

Sort::Sort(const int vector[], int number_of_elements)
{
	this->number_of_elements = number_of_elements;
	this->vector = new int[number_of_elements];

	for (int i = 0; i < number_of_elements; i++)
		this->vector[i] = vector[i];
}

Sort::Sort(int number_of_elements, ...)
{
	va_list args;
	va_start(args, number_of_elements);
	this->number_of_elements = number_of_elements;
	this->vector = new int[number_of_elements];

	for (int i = 0; i < number_of_elements; i++)
		this->vector[i] = va_arg(args, int);
	va_end(args);
}

Sort::Sort(const char* vector)
{
	if (vector[0] == '\0') {
		this->number_of_elements = 0;
		this->vector = nullptr;
		return;
	}

	int nr = 0, j = 0;
	this->number_of_elements = 1;
	for (int i = 0; vector[i]; i++)
		this->number_of_elements += vector[i] == ',';

	this->vector = new int[this->number_of_elements];

	for (int i = 0; vector[i]; i++)
		if (vector[i] >= '0' && vector[i] <= '9')
			nr = nr * 10 + vector[i] - '0';
		else {
			this->vector[j++] = nr;
			nr = 0;
		}
	this->vector[j] = nr;
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < this->number_of_elements; i++) {
		int value = this->vector[i], j = i - 1;

		while (j >= 0 && (this->vector[j] > value) == ascendent)
			this->vector[j + 1] = this->vector[j--];

		this->vector[j + 1] = value;
	}
}

void Sort::Swap(int& a, int& b) {
	int aux = a;
	a = b;
	b = aux;
}

int Sort::Partitie(int vector[], int left, int right, bool ascendent)
{
	int pivot = vector[right];
	int i = left - 1;

	for(int j = left; j < right; j++)
		if ((vector[j] < pivot) == ascendent) {
			i++;

			Swap(vector[i], vector[j]);
		}

	Swap(vector[i + 1], vector[right]);
	return i + 1;
}

void Sort::QuickSortHelp(int vector[], int left, int right, bool ascendent)
{
	if (left < right) {
		int pivot = Partitie(vector, left, right, ascendent);

		QuickSortHelp(vector, left, pivot - 1, ascendent);
		QuickSortHelp(vector, pivot + 1, right, ascendent);
	}
}

void Sort::QuickSort(bool ascendent)
{
	QuickSortHelp(this->vector, 0, this->number_of_elements - 1, ascendent);
}


void Sort::BubbleSort(bool ascendent)
{
	int j = this->number_of_elements;
	bool ok = true;

	do {
		ok = false;
		int new_j = j;

		for(int i = 1; i < j; i++)
			if ((this->vector[i - 1] > this->vector[i]) == ascendent) {
				ok = true;
				new_j = i;
				this->vector[i - 1] = this->vector[i - 1] + this->vector[i];
				this->vector[i] = this->vector[i - 1] - this->vector[i];
				this->vector[i - 1] = this->vector[i - 1] - this->vector[i];
			}
		j = new_j;

	} while (ok);
}

void Sort::Print()
{
	for (int i = 0; i < this->number_of_elements; i++)
		printf("%d ", this->vector[i]);
	printf("\n");
}

int Sort::GetElementsCount()
{
	return this->number_of_elements;
}

int Sort::GetElementFromIndex(int index)
{
	if (index < 0 || index >= number_of_elements)
		return -1;

	return this->vector[index];
}
