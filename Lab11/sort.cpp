#include <iostream>
#include <string>
#include <vector>
#include "pch.h"
using namespace std;

template <typename T>
class Sort {
private:
	T* data;
	int size;

	void Swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

	int partitionate(int left, int right) {
		T pivot = data[right];
		int i = left - 1;

		for (int j = left; j < right; j++) {
			if (data[j] < pivot) {
				i++;
				swap(data[i], data[j]);
			}
		}

		swap(data[i + 1], data[right]);
		return i + 1;
	}

	void quickSortHelp(int left, int right) {
		if (left >= right)
			return;
		int pivot = partitionate(left, right);
		quickSortHelp(left, pivot - 1);
		quickSortHelp(pivot + 1, right);
	}

public:
	void SetValues(vector<T> v) {
		size = (int) v.size();
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = v[i];
	}

	~Sort() {
		delete[] data;
		size = 0;
	}

	void QuickSort() {
		quickSortHelp(0, size - 1);
	}

	string Print() {
		string s = "";
		for (int i = 0; i < size; i++) {
			s += to_string(data[i]);
			if(i + 1 < size)
				s += ", ";
		}
		return s;
	}

};

//int main() {
//	int arr[] = { 5, 3, 7, 8, 2 };
//	Sort<int> v(5);
//	v.QuickSort();
//	v.Print();
//
//	return 0;
//}