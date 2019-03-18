#include <stdio.h>
#define MAXLENGTH 20     //最大数据个数：20 
typedef struct list_type{//定义结构体 
	int data[MAXLENGTH];  //最多个数 
	int length;//实际个数 
}list_type;

void init_table(list_type * table)//初始化顺序表 
{
	int i;
	for(i = 0;i < MAXLENGTH;i++)
		table->data[i] = -100;//全部置为-1 
	table->length = 0;
	return;
}
void create_table(list_type *table)//创建顺序表（其实是将数据输入） 
{
    int x,i;
	printf("输入元素：\n");//提示输入数据 
	for(i=0;i<MAXLENGTH;i++)
	{
		scanf("%d",&x);//输入数据，回车间隔 
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

void show_list(list_type *table)//展示数据 
{
	int i;
	for(i = 0; i < table->length; i++)
	{
		printf("%d, ",table->data[i]);
	}
	printf("\n");
}

int main()//删除负数 
{
	list_type table;
	init_table(&table);
	create_table(&table);
	show_list(&table);
	delete_list(&table);
	printf("删除结束！\n");
	show_list(&table);
	return  0;
}
 