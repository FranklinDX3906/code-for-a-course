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

void creat_list(list_type *list)//创建链表 
{
	node_type *t,*p;
	int node;
	int i=2;
	printf("Please type in the node a1=");
	scanf("%d",&node);
	printf("\n"); 
	if(node!=-100)
	{
		t=(node_type*)malloc(sizeof(node_type));//先赋值好第一个节点 
		t->data=node;
		list->head=t;
		list->length++;
		while(1)
		{
			printf("Please type in the node a%d=",i);
			scanf("%d",&node);
			printf("\n");
			if(node==-100)
			{
				break;
			}
			else
			{
				p=(node_type*)malloc(sizeof(node_type));
				t->next=p;
				p->data=node;
				t=t->next;
				list->length++;
				i++;
			}
		}
	}
	else
	{
		return;
	}
}

void delete_negative(list_type *list)
{
	node_type *t,*p;
	int count;
	count=1;
	p=list->head;
	if(list->length!=0)
	{
		if(p->data<0)
		{
			list->head=p->next;	
			free(p);
			list->length--;		
		}
		else
		{
			while(count<=list->length&&p!=NULL)
			{
				if(p->next->data<0)
				{
					t=p->next;
					p->next=p->next->next;
					free(t);
					list->length--;
				}
				p=p->next;
				count++;
			}
		}
	}
	return;
}

int main()
{
	list_type list;
	list.length=0;
	list.head=NULL;
	list.tail=NULL;//初值 
	creat_list(&list);//创建链表，以-100结尾（-100不在内） 
	show_list(&list);
	delete_negative(&list);
	printf("Deletion successed!\n");
	show_list(&list);
	return 0;
}
