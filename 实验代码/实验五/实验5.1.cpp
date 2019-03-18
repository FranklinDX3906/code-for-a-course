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
	int l,h;//两边的元素
	l=0;h=7;
	int m;//用于查找的值 
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
	int location1,location2;//两种查找的查找结果
	int find;//想要查找的元素值 
	while(1)
	{
		printf("Please input the data you want to find:\n");
		scanf("%d",&find);
		location1=seq_search(data,find);
		location2=bin_search(data,find);
		printf("\n顺序查找结果：\ndata[%d]=%d\n二分查找结果：\ndata[%d]=%d\n\n\n",location1,find,location2,find);
	}
	return 0;
}
