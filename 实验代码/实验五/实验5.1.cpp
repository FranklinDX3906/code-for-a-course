#include<stdio.h>

int seq_search(int data[8],int find)
{
	int location1;
	for(int i=0;i<8;i++)
	{
		if(data[i]==find)
		{
			location1=i;
		}
	}
	return location1;
}

int bin_search(int data[8],int find)
{
	int location2;
	int l,h;//���ߵ�Ԫ��
	l=0;h=7;
	int m;//���ڲ��ҵ�ֵ 
	while(l<=h)
	{
		m=(l+h)/2;
		if(data[m]==find)
		{
			location2=m;
			break;
		}
		else
		{
			if(data[m]>find)
			{
				h=m-1;
			}
			else
			{
				l=m+1;
			}
		} 
	} 
	return location2;
}

int main()
{
	int data[8]={3,10,13,17,40,43,50,70};
	int location1,location2;//���ֲ��ҵĲ��ҽ��
	int find;//��Ҫ���ҵ�Ԫ��ֵ 
	while(1)
	{
		printf("Please input the data you want to find:\n");
		scanf("%d",&find);
		location1=seq_search(data,find);
		location2=bin_search(data,find);
		printf("\n˳����ҽ����\ndata[%d]=%d\n���ֲ��ҽ����\ndata[%d]=%d\n\n\n",location1,find,location2,find);
	}
	return 0;
}
