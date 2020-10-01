//Counting Sort
#include <stdio.h>
#include <time.h>

/*  Counting sort function  */
void counting_sort(int A[], int k, int n)
{
    int i, j;
    int B[15], C[100];
    for (i = 0; i <= k; i++)
        C[i] = 0;

    for (j = 1; j <= n; j++)
        C[A[j]] = C[A[j]] + 1;

    for (i = 1; i <= k; i++)
        C[i] = C[i] + C[i - 1];

    for (j = n; j >= 1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    printf("The Sorted array is : ");
    for (i = 1; i <= n; i++)
        printf("%d ", B[i]);
}
/*  End of counting_sort()  */

int main()
{
    int n, k = 0, A[15], i;
    time_t start, end;
    start = time(NULL);

    printf("Enter the number of input : ");
    scanf("%d", &n);
    printf("\nEnter the elements to be sorted :\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
        if (A[i] > k)
        {
            k = A[i];
        }
    }
    counting_sort(A, k, n);
    printf("\n");

    end = time(NULL);
    printf("\n Time taken by the program is %.2f seconds", difftime(end, start));
    return 0;
}