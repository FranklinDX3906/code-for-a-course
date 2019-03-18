#include <stdio.h>
#define MAXLENGTH 100     //������ݸ�����100 
typedef struct list_type{//����ṹ�� 
	int data[MAXLENGTH];  //������ 
	int length;//ʵ�ʸ��� 
}list_type;

void init_table(list_type * table)//��ʼ��˳��� 
{
	int i;
	for(i = 0;i < MAXLENGTH;i++)
		table->data[i] = -100;//ȫ����Ϊ-100 
	table->length = 0;
	return;
}
void create_table(list_type *table)//����˳�����ʵ�ǽ��������룩 
{
    int x,i;
	printf("����Ԫ�أ�\n");//��ʾ�������� 
	for(i=0;i<MAXLENGTH;i++)
	{
		scanf("%d",&x);//�������ݣ��س������-100���� 
		if(x==-100)
			break;
		else
		{
			table->data[i]=x;
			table->length++;
		}
	}
	return;
}

void invert_list(list_type *table)
{
	int t,i;
	if(table->length%2==0)
	{
		for(i=0;i<0.5*table->length;i++)
		{
			t=table->data[i];
			table->data[i]=table->data[table->length-1-i];
			table->data[table->length-1-i]=t;
		}
	}
	else
	{
		for(i=0;i<0.5*(table->length-1);i++)
		{
			t=table->data[i];
			table->data[i]=table->data[table->length-1-i];
			table->data[table->length-1-i]=t;
		}	
	}
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
	list_type table;
	init_table(&table);
	create_table(&table);
	show_list(&table);
	printf("\n");
	invert_list(&table);
	show_list(&table);
	return 0;
}