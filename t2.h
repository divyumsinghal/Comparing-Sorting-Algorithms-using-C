//
// Created by divyu on 24/10/2024.
//

#ifndef T2_H
#define T2_H

extern int number_comparisons;
extern int number_swaps;


void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);

int partition(int arr[], int low, int high);
void quickSortrecursive(int arr[], int p, int r);
void quickSort(int arr[], int size);

#endif //T2_H
