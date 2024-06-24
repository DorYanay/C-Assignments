#include <stdio.h>
#define SIZE 50
// Insertion sort exercise.
void printArray(int *arr, int size)
{
    printf("%d", *arr);
    for (int i = 1; i < size; i++)
    {
        printf(",%d", *(arr + i));
    }
    printf("\n");
}

// Shift Element to the right from a given pointer.
void shift_element(int *arr, int i)
{
    for (int j = i; j > 0; j--)
    {
        *(arr + j) = *(arr + j - 1);
    }
}

void insertion_sort(int *arr, int size)
{
    int key, j, cnt;
    int *ptr;
    for (int i = 1; i < size; i++)
    {
        key = *(arr + i);
        j = i - 1;
        cnt = 0;

        while (j >= 0 && *(arr + j) > key)
        {
            cnt++;
            j = j - 1;
        }
        if (cnt)
        {
            ptr = (arr + j + 1);
            shift_element(ptr, cnt);
            *(arr + j + 1) = key;
        }
    }
}

int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        scanf(" %d", (arr + i));
    }
    insertion_sort(arr, SIZE);
    printArray(arr, SIZE);
    return 0;
}
