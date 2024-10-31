//
// Created by divyu on 24/10/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "t1.h"

#include <time.h>


//Fills the array with ascending, consecutive numbers, starting from 0.
void fill_ascending(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = i;
    }
}
//Fills the array with descending numbers, starting from size-1
void fill_descending(int* array, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        array[i] = size - i - 1;
    }
}

//Fills the array with uniform numbers.
void fill_uniform(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = size;
    }
}

//Fills the array with random numbers within 0 and size-1. Duplicates are allowed.
void fill_with_duplicates(int* array, int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % size;
    }
}


//Fills the array with unique numbers between 0 and size-1 in a shuffled order. Duplicates are not allowed.
void fill_without_duplicates(int* array, int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        array[i] = i;
    }

    for (int i = 0; i < size; i++)
    {
        int j1 = rand() % size;
        int j2 = rand() % size;

        if (j1 != j2)
        {
            const int temp = array[j1];
            array[j1] = array[j2];
            array[j2] = temp;
        }
    }
}

void printArray(const int* arr, const int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
