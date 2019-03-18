#include <stdio.h>
#define MAXLENGTH 100     //最大数据个数：100 
typedef struct list_type{//定义结构体 
	int data[MAXLENGTH];  //最多个数 
	int length;//实际个数 
}list_type;

void init_table(list_type * table)//初始化顺序表 
{
	int i;
	for(i = 0;i < MAXLENGTH;i++)
		table->data[i] = -100;//全部置为-100 
	table->length = 0;
	return;
}
void create_table(list_type *table)//创建顺序表（其实是将数据输入） 
{
    int x,i;
	printf("输入元素：\n");//提示输入数据 
	for(i=0;i<MAXLENGTH;i++)
	{
		scanf("%d",&x);//输入数据，回车间隔，-100结束 
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

void show_list(list_type *table)//展示数据 
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