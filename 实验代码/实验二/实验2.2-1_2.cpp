#include <stdio.h>
#include <malloc.h>

typedef struct node_type{
	int data;
	struct node_type * next;
}node_type;

typedef struct list_type{
	node_type *head;
	node_type *tail;
	int length;
}list_type;

void show_list(list_type *table)
{
	int count;
	node_type * temp;
	count = 1;
	temp = table->head;
	if(table->length==0)//考虑开始就输入0即链表无元素的情况 
	{
		printf("The list is empty!");
		return;
	}
	printf("The list now is: \n");
	while(count <= table->length && temp != NULL)
	{
		printf("%d, ",temp->data);
		count ++;
		temp = temp->next;
	}
	printf("\n");
	return;
}

void creat_list(list_type *table)//创建链表 
{
	node_type *t,*p;
	int node;
	int i=2;
	printf("Please type in the node a1=");
	scanf("%d",&node);
	printf("\n"); 
	if(node!=0)
	{
		t=(node_type*)malloc(sizeof(node_type));//先赋值好第一个节点 
		t->data=node;
		table->head=t;
		table->length++;
		while(1)
		{
			printf("Please type in the node a%d=",i);
			scanf("%d",&node);
			printf("\n");
			if(node==0)
			{
				break;
			}
			else
			{
				p=(node_type*)malloc(sizeof(node_type));
				t->next=p;
				p->data=node;
				t=t->next;
				table->length++;
				i++;
			}
		}
	}
	else
	{
		return;
	}
}

int detect_list(list_type *table,int x)//判断输入的数字有没有以判断需要执行什么操作 
{
	int count=1;
	int s;
	node_type *p;
	p=table->head;
	if(table->length!=0)
	{
		while(count<=table->length&&p!=NULL)
		{
			if(p->data!=x)
			{
				p=p->next;
				count++;
				s=2; 
			}
			else
			{
				s=1;
				break;
			}
		}
	}
	else
	{
		s=2;
	}
	return s;
}

void delete_list(list_type *table,int x)//执行删除操作 
{
	int count;
	node_type *p;
	node_type *t;
	count=2;
	p=table->head;
	if(p->data==x)
	{
		table->head=p->next;
		free(p);
		table->length--;
		return;
	}
	while(count<=table->length&&p!=NULL)
	{
		if(p->next->data==x)
		{
			t=p->next;
			p->next=t->next;
			free(t);
			table->length--;
			break;
		}
		else
		{
			count++;
			p=p->next;
		}
	} 
	return;
}

void insert_list(list_type *table,int x)//插入到链表尾 
{
	node_type *t;
	t=(node_type*)malloc(sizeof(node_type));
	t->data=x;
	t->next=NULL;
	int count=1;
	node_type *p;
	p=table->head;
	while(count<table->length&&p!=NULL)
	{
		p=p->next;
		count++;
	}
	p->next=t;
	table->length++;
	table->tail=t;
	return;
}


int main()
{
	list_type table;
	table.length=0;
	table.head=NULL;
	table.tail=NULL;//初值 
	int s,x;//操作数 
	creat_list(&table);
	show_list(&table);
	while(1)
	{
		printf("Please type in the data you want to do with: ");
		scanf("%d",&x);
		s = detect_list(&table,x);
		if(s==1)
		{
			delete_list(&table,x);
			show_list(&table);
		}
		else
		{
			insert_list(&table,x);
			show_list(&table);
		}
	}
	return 0;
}
