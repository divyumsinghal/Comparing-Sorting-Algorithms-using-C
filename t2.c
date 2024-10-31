//
// Created by divyu on 24/10/2024.
//


#include <stdio.h>
#include "t2.h"

int number_comparisons = 0;
int number_swaps = 0;

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            number_comparisons++;
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            const int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            number_swaps++;
        }
    }
}


void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        number_comparisons++;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            number_comparisons++;
            number_swaps++;
        }

        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high) {
    const int pivot = arr[high];
    int i = (low - 1);

	number_comparisons++;
    for (int j = low; j < high; j++) {
        number_comparisons++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            number_swaps++;
        }
    }

    const int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    number_swaps++;

    return (i + 1);
}


void quickSortrecursive(int arr[], int p, int r) {

	number_comparisons++;
    if (p < r) {
        int q = partition(arr, p, r);
        quickSortrecursive(arr, p, q - 1);
        quickSortrecursive(arr, q + 1, r);
    }

}


void quickSort(int arr[], int size) {
    quickSortrecursive( arr, 0, size - 1);
}