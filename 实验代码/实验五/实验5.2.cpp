#include<stdio.h>
#include<string.h>

#define MAXNUM 30

void hash_save(char hash[20][MAXNUM])
{
	int number;//总的个数
	char name[20];//姓名
	int flag[MAXNUM];//判断哈希表有没有存东西 
	printf("\n你要输入多少个元素？\n");
	scanf("%d",&number);
	while(number>0)
	{
		number--;
		printf("\n请输入姓名：\n");
		scanf("%s",&name);
		int hash_value=0;
		int length=strlen(name);
		for(int i=0;i<length;i++)
		{
			hash_value+=(int)(name[i]);
		}
		while(hash_value<0)
		{
			hash_value+=MAXNUM;
		}
		hash_value=hash_value%MAXNUM;
		printf("%d",hash_value);
		while(flag[hash_value]==1)
		{
			hash_value=(hash_value+1)%MAXNUM;
		}
		hash[20][hash_value]=name[20];
		flag[hash_value]=1;
	}
	return;
}

int hash_search(char hash[20][MAXNUM])
{
	int location;
	char name[20];
	printf("\n请输入姓名：\n");
	scanf("%s",&name);
	int hash_value=0;
	int length=strlen(name);
	for(int i=0;i<length;i++)
	{
		hash_value+=(int)name[i];
	}
	while(hash_value<0)
	{
		hash_value+=MAXNUM;
	}
		hash_value=hash_value%MAXNUM;
	while(hash[20][hash_value]!=name[20])
	{
		hash_value=(hash_value+1)%MAXNUM;
	}
	location=hash_value;
	return location;
}

int main()
{
	char hash[20][MAXNUM];
	hash_save(hash);//先存数据创建哈希表 
	int location;//查找到的位置 
	while(1)
	{
		location=hash_search(hash);//寻找并返回位置 
		printf("\n查找到的的位置在：\n%d",location);
	}
	return 0;
}
