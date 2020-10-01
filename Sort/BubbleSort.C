//bubble sort
#include <stdio.h>
#include <time.h>

void bubble(int a[], int n)
{
    int temp, i, j, k;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        printf("\n After Pass %d:- \n", i);
        for (k = 0; k < n; k++)
        {
            printf("%d    ", a[k]);
        }
    }
}
int main()
{
    int a[10], n, i;
    time_t start, end;
    start = time(NULL);
    printf("\n Enter the size of array : ");
    scanf("%d", &n);
    printf("\n Enter the elements in array :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    bubble(a, n);
    end = time(NULL);
    printf("\n Time taken by the program is %.3f seconds", difftime(end, start));
    return 0;
}
