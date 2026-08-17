#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*CompareFunc)(const void *, const void *);

void swap(void *a, void *b, size_t size)
{
    void *temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

void heapify(void *arr, size_t n, size_t i, size_t size, CompareFunc cmp)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n &&
        cmp((char *)arr + left * size, (char *)arr + largest * size) > 0)
        largest = left;

    if (right < n &&
        cmp((char *)arr + right * size, (char *)arr + largest * size) > 0)
        largest = right;

    if (largest != i)
    {
        swap((char *)arr + i * size,(char *)arr + largest * size, size);
        heapify(arr, n, largest, size, cmp);
    }
}

void heapSort(void *arr, size_t n, size_t size, CompareFunc cmp)
{
    size_t i;

    for (i = n / 2; i > 0; i--)
        heapify(arr, n, i - 1, size, cmp);

    for (i = n; i > 1; i--)
    {
        swap((char *)arr, (char *)arr + (i - 1) * size, size);
        heapify(arr, i - 1, 0, size, cmp);
    }
}

int compareInt(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

int compareFloat(const void *a, const void *b)
{
    float x = *(const float *)a;
    float y = *(const float *)b;

    return (x > y) - (x < y);
}

int compareChar(const void *a, const void *b)
{
    char x = *(const char *)a;
    char y = *(const char *)b;

    return (x > y) - (x < y);
}

int main()
{
    int arr[] = {5, 2, 9, 1, 7, 6, 3};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n, sizeof(int), compareInt);

    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
