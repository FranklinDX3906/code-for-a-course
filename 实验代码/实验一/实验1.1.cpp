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
		table->data[i] = -1;//全部置为-1 
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
		if(x==-1)
			break;
		else
		{
			table->data[i]=x;
			table->length++;
		}
	}
	return;
}

void get_element(int *x,int *l)//插入前数据准备 
{
	printf("please input the element x= ");
	fflush(stdin);
	scanf(" %d",x);
	printf("\n");
	printf("the location of inserting l= ");
	fflush(stdin);
	scanf("%d",l);
	printf("\n");
	return;
}


void insert_list(list_type *table,int new_node,int location)//插入数据操作 
{
	if(table->length>MAXLENGTH)
	{
		printf("列表已满，无法插入数据");
	}
	else
	{
		int i;
		location = location - 1;
		for(i = table->length-1; i > location-1; i--)
		{
			table->data[i + 1] = table->data[i];
		}
		table->data[location] = new_node;
		table->length ++;
	}
	return;
}
void delete_list(list_type *table,int location)
{
	int i;
	location = location - 1;
	for(i = location; i < table->length-1 ;i++)
	{
		table->data[i] = table->data[i+1];
	}
	table->length --;
	return;
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
	int x;
	int l;
	list_type table;
	init_table(&table);
	create_table(&table);
	show_list(&table);
	while(1){
		get_element(&x,&l);
		insert_list(&table,x,l);
		printf("insert ok!\n");
		show_list(&table);

		printf("input the position to delete: ");
		fflush(stdin);
		scanf("%d",&x);
		delete_list(&table,x);
		show_list(&table);
	}
	return 0;
}