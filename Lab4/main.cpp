#include "Sort.h"
#include <stdio.h>

int main() {
    Sort sort1(10, 1, 100);
    printf("Random values: ");
    sort1.Print();

    sort1.InsertSort(true);
    printf("After InsertSort (ascendent): ");
    sort1.Print();

    sort1.BubbleSort(false);
    printf("After BubbleSort (descendent): ");
    sort1.Print();

    sort1.QuickSort(true);
    printf("After QuickSort (ascendent): ");
    sort1.Print();

    Sort sort2 = { 7, 2, 10, 5, 3 };
    printf("\nInitialization list: ");
    sort2.Print();

    sort2.InsertSort(false);
    printf("After InsertSort (descendent): ");
    sort2.Print();

    int vec[] = {6, 4, 2, 9, 1};
    Sort sort3(vec, 5);
    printf("\nFrom vector: ");
    sort3.Print();

    sort3.QuickSort(false);
    printf("After QuickSort (descendent): ");
    sort3.Print();

    Sort sort4("12,50,30,8,90,65");
    printf("\nFrom string: ");
    sort4.Print();

    sort4.BubbleSort(true);
    printf("After BubbleSort (ascendent): ");
    sort4.Print();

    Sort sort5(4, 5, 15, 25, 10);
    printf("\nFrom variadic parameters: ");
    sort5.Print();

    sort5.InsertSort(true);
    printf("After InsertSort (ascendent): ");
    sort5.Print();

    return 0;
}
