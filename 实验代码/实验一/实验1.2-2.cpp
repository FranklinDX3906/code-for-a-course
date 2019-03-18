#include <stdio.h>
#define MAXLENGTH 20     //������ݸ�����20 
typedef struct list_type{//����ṹ�� 
	int data[MAXLENGTH];  //������ 
	int length;//ʵ�ʸ��� 
}list_type;

void init_table(list_type * table)//��ʼ��˳��� 
{
	int i;
	for(i = 0;i < MAXLENGTH;i++)
		table->data[i] = -100;//ȫ����Ϊ-1 
	table->length = 0;
	return;
}
void create_table(list_type *table)//����˳�����ʵ�ǽ��������룩 
{
    int x,i;
	printf("����Ԫ�أ�\n");//��ʾ�������� 
	for(i=0;i<MAXLENGTH;i++)
	{
		scanf("%d",&x);//�������ݣ��س���� 
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

void delete_list(list_type *table)
{
	int i=0;
	int j=0;
	for(i = 0; i < table->length;i++)
	{
		if(table->data[i]<0)
		{
			j--;
		}
		else
		{
			if(i==j)
			{
				table->data[j]=table->data[i];	
			}
			else
			{
				table->data[j]=table->data[i];
				table->data[i]=-100;
			}
		}
		j++;
	}
	table->length=table->length+j-i;
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

int main()//ɾ������ 
{
	list_type table;
	init_table(&table);
	create_table(&table);
	show_list(&table);
	delete_list(&table);
	printf("ɾ��������\n");
	show_list(&table);
	return  0;
}
 