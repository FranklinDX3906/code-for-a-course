#include<stdio.h>
#include<string.h>

#define MAXNUM 30

void hash_save(char hash[20][MAXNUM])
{
	int number;//�ܵĸ���
	char name[20];//����
	int flag[MAXNUM];//�жϹ�ϣ����û�д涫�� 
	printf("\n��Ҫ������ٸ�Ԫ�أ�\n");
	scanf("%d",&number);
	while(number>0)
	{
		number--;
		printf("\n������������\n");
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
	printf("\n������������\n");
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
	hash_save(hash);//�ȴ����ݴ�����ϣ�� 
	int location;//���ҵ���λ�� 
	while(1)
	{
		location=hash_search(hash);//Ѱ�Ҳ�����λ�� 
		printf("\n���ҵ��ĵ�λ���ڣ�\n%d",location);
	}
	return 0;
}
