#include<stdio.h>

#define MAXNUM 10

void quick_sort(int data[MAXNUM],int low,int high)
{
	int L,R;//��ָ�롢��ָ��
	int temp;//���ڽ�������ʱ���� 
	L=low;R=high;
	int k=data[low];//��׼Ԫ�ص�ֵ 
	while(L<R)
	{
		while(data[R]>=k&&L<R)
		{
			R--;
		}
		while(data[L]<=k&&L<R)
		{
			L++;
		}
		temp=data[L];
		data[L]=data[R];
		data[R]=temp;
	}
	temp=data[low];
	data[low]=data[R];
	data[R]=temp;
	if(R-1>low)
	{
		quick_sort(data,low,R-1);
	}
	if(high>R+1)
	{
		quick_sort(data,R+1,high);
	}
	return;
}

int main()
{
	int data[MAXNUM];
	int input;
	int i=0;
	while(i<MAXNUM)
	{
		printf("Please input the data:\n");
		scanf("%d",&input);	
		data[i]=input;
		i++;
	}
	int low,high;
	low=0;
	high=MAXNUM-1;
	quick_sort(data,low,high);
	printf("\nThe array after quick sort is:\n");
	for(int j=0;j<i;j++)
	{
		printf("%d,",data[j]);	
	}
	printf("\n\n\n");
	return 0;
}
