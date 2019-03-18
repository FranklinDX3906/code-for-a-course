#include <stdio.h>
#include <malloc.h>
#define MAXNUM 20 


typedef struct node_type{
	int data;
	struct node_type * next;
}node_type;

typedef struct list_type{
	node_type *head;
	node_type *tail;
	int length;
}list_type;

void insert_list(list_type *list,int x)
{
	if(list->length==0)
	{
		node_type *t;
		t=(node_type*)malloc(sizeof(node_type));//申请空间
		t->data=x;
		list->head=t;
		list->tail=t;
		t->next=NULL;
		list->length++;
	}
	else
	{
		int count=2;
		node_type *temp,*p;
		temp=list->head;
		if(temp->data>x)
		{
			node_type *t;
			t=(node_type*)malloc(sizeof(node_type));//申请空间
			t->data=x;
			list->head=t;
			t->next=temp;
			list->length++; 
		}
		else
		{
			temp=temp->next;
			p=list->head;
			while(count<=list->length&&temp!=NULL)
			{
				if(temp->data>x)
				{
					break;
				}
				else
				{
					count++;
					temp=temp->next;
					p=p->next;
				}
			}
			node_type *t;
			t=(node_type*)malloc(sizeof(node_type));//申请空间
			t->data=x;
			p->next=t;
			t->next=temp;
			list->length++;
			if(count==list->length+1)
			{
				list->tail=t;
			}
		}
		
	}
	return;
}

void show_list(list_type *list)
{
	int count;
	node_type * temp;
	count = 1;
	temp = list->head;
	if(list->length==0)//考虑开始就输入0即链表无元素的情况 
	{
		printf("The list is empty!");
		return;
	}
	printf("The list now is: \n");
	while(count <= list->length && temp != NULL)
	{
		printf("%d, ",temp->data);
		count ++;
		temp = temp->next;
	}
	printf("\n");
	return;
}

int main()
{
	list_type list;
	int x;
	list.length=0; 
	list.head=NULL;
	list.tail=NULL;
	while(1)
	{
		printf("Please type the data you want to add to the list:\n");
		scanf("%d",&x);
		insert_list(&list,x);
		show_list(&list);
	}
	return 0;
}
