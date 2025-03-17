#pragma once
#include <initializer_list>

class Sort
{
    // add data members
    int number_of_elements;
    int* vector;
public:
    // add constuctors
    Sort(int number_of_elements, int min_value, int max_value);
    Sort(std::initializer_list<int> initList);
    Sort(const int vector[], int number_of_elements);
    Sort(int number_of_elements, ...);
    Sort(const char* vector);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);

private:
    void Swap(int& a, int& b);
    void QuickSortHelp(int vector[], int left, int right, bool ascendent = false);
    int Partitie(int vector[], int left, int right, bool ascendent = false);

};
