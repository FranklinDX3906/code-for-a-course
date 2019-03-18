#include<stdio.h>
#include<windows.h>
#define MAXNUM 10
#define small s
typedef struct
{
	int data;
}list_type;
 
void selectsort(list_type x[], int n)
{
	list_type swap;
	int i, j, small, k;
	for (i = 0; i<n - 1; i++)
	{
		small = i;
		for (j = i + 1; j<n; j++)
		{
			if (x[j].data<x[small].data)
				small = j;
		}
		if (small != i)
		{
			swap = x[i];
			x[i] = x[small];
			x[small] = swap;
		}
		for (k = 0; k<n; k++)
		{
			printf(" %d ", x[k].data);
		}
		printf("\n");
 
	}
}
 
void insertsort(list_type x[], int n)
{
	list_type a;
	int i, j, k;
	for (i = 0; i<n - 1; i++)
	{
		a = x[i + 1];
		j = i;
		while (j>-1 && a.data<x[j].data)
		{
			x[j + 1] = x[j];
			j--;
 
		}
 
		x[j + 1] = a;
		for (k = 0; k<n; k++)
		{
			printf(" %d ", x[k].data);
		}
		printf("\n");
	}
 
}
 
 
void bubblesort(list_type x[], int n)
{
	int i, j, k, flag = 1;
	list_type swap;
	for (i = 0; i<n - 1 && flag == 1; i++)
	{
		flag = 0;
		for (j = 0; j<n - i - 1; j++)
		{
			if (x[j].data>x[j + 1].data)
			{
				flag = 1;
				swap = x[j];
				x[j] = x[j + 1];
				x[j + 1] = swap;
			}
 
		}
		for (k = 0; k<n; k++)
		{
			printf(" %d ", x[k].data);
		}
		printf("\n");
		if (flag == 0)
			break;
	}
 
}
int main()
{
	list_type x[MAXNUM], y[MAXNUM], z[MAXNUM];
	int i, b;
	printf("\n please input datas(-1 at the end) \n");
	for (i = 0; i< MAXNUM; i++)
	{
		scanf("%d", &b);
		if (b == -1) break;
		x[i].data = b;
		y[i].data = b;
		z[i].data = b;
	}
	printf("\n the result of the selectsort is:\n");
	selectsort(x, i);
 
	printf("\n the result of the insertsort is:\n");
	insertsort(y, i);
	printf("\n the result of the bubblesort is:\n");
	bubblesort(z, i);
	system("pause");
	return 0; 
}

