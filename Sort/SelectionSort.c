//Selection Sort
#include <stdio.h>
#include <time.h>

void selection(int a[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;

		printf("\n After Pass %d:- \n", i + 1);
		for (j = 0; j < n; j++)
		{
			printf("%d\t", a[j]);
		}
	}
}
int main()
{
	int a[20], n, i;
	time_t start, end;
	start = time(NULL);
	printf("\n enter the size of array : ");
	scanf("%d", &n);
	printf("\n Enter the elements in array :\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	selection(a, n);
	end = time(NULL);
	printf("\n Time taken by the program is %.3f seconds", difftime(end, start));
	return 0;
}
