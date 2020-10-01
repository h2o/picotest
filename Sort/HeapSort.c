#include <stdio.h>
#include <time.h>

int temp;

void heap(int arr[], int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heap(arr, size, largest);
    }
}

void heapSort(int arr[], int size)
{
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
        heap(arr, size, i);
    for (i = size - 1; i >= 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heap(arr, i, 0);
    }
}

int main()
{
    int arr[20];
    int i, size;
    time_t start, end;
    start = time(NULL);

    printf("Enter the size of an array: ");
    scanf("%d", &size);
    printf("\n Enter the elements in the array: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, size);

    printf("printing sorted elements\n");
    for (i = 0; i < size; ++i)
        printf("%d\t", arr[i]);

    end = time(NULL);
    printf("\n Time taken by program is %.2f seconds", difftime(end, start));
    return 0;
}