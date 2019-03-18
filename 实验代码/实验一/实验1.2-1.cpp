#include<stdio.h>
#define MAXLENGTH 100
typedef struct list_type{//����ṹ�� 
	int data[MAXLENGTH];
	int length;
}list_type;


void init_table(list_type * table)//��ʼ���б� 
{
	int i;
	for(i = 0;i < MAXLENGTH;i++)
		table->data[i] = -100;
	table->length = 0;
	return;
}

void get_element(int *x)//����ǰ����׼�� 
{
	printf("please input the element x= ");
	fflush(stdin);
	scanf(" %d",x);
	printf("\n");
	return;
}

void create_table(list_type *table)//����˳�����ʵ�ǽ��������룩 
{
    int x,i;
	printf("����Ԫ�أ����յ���˳�򣩣����������ݳ��ּ�С����������룺\n");//��ʾ�������� 
	scanf("%d",&table->data[0]);
	table->length++;
	for(i=1;i<MAXLENGTH;i++)
	{
		scanf("%d",&x);//�������ݣ��س���� 
		if(x<table->data[i-1])
			break;
		else
		{
			table->data[i]=x;
			table->length++;
		}
	}
	return;
}

/*
void get_element(int *x)
{
	printf("����Ҫ��������ݴ�Сx=");
	fflush(stdin);
	scanf(" %d",&x);
	return; 
}*/

void insert_element(list_type *table,int new_node)
{
	int i;
	int location=0;
	for(i=0;i<table->length;i++)
	{
		if(table->data[i]>new_node)
				break;
		else
			location++;
	}
	for(i=table->length-1;i>location-1;i--)
	{
		table->data[i+1]=table->data[i];
	}
	table->data[location]=new_node;
	table->length++;
	return;

}

void show_list(list_type *table)//չʾ���� 
{
	int i;
	for(i = 0; i < table->length; i++)
	{
		printf("%d, ",table->data[i]);
	}
	printf("\n");
}

int main()
{
		int x;
		list_type table;
		init_table(&table);
		create_table(&table);
		show_list(&table);
		while(1)
		{
			get_element(&x);
			insert_element(&table,x);
			printf("����ɹ���\n");
			show_list(&table);
		}
		return 0;
}

