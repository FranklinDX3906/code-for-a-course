#include<stdio.h>
#include <malloc.h>

typedef struct dnode_type
{
	int data;
	struct dnode_type *prior;
	struct dnode_type *next;
}dnode_type;

typedef struct dlist_type
{
	dnode_type *head;
	dnode_type *tail;
	int length;
}dlist_type;

void creat_list(dlist_type *list)
{
	dnode_type *t,*p;
	int x;
	printf("Please type in the data of node a1:");
	scanf("%d",&x);
	if(x!=-100)
	{
		p=(dnode_type*)malloc(sizeof(dnode_type));
		p->data=x;
		list->head=p;
		list->tail=p;
		p->prior=NULL;
		p->next=NULL;
		list->length++;
		int i=2;
		while(1)
		{
			printf("Please type in the data of node a%d:",i);
			scanf("%d",&x);
			if(x==-100)
			{
				break;
			}
			else
			{
				t=p;
				p=(dnode_type*)malloc(sizeof(dnode_type));
				p->data=x;
				p->next=NULL;
				p->prior=t;
				t->next=p;
				list->length++;
				i++;
			}
		} 
	} 
	return;
}

void show_list(dlist_type *list)
{
	int count;
	dnode_type * temp;
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

void sort_list(dlist_type *list)//对链表进行排序 
{
	dnode_type *p;
	int count1,count2;//定义两个代表指针的count，类似于冒泡排序的i和j 
	p=list->head;
	for(count1=1;count1<=list->length;count1++)
	{
		p=list->head;
		for(count2=1;count2<=list->length-count1;count2++)
		{
			if(p->data>=p->next->data)
			{
				if(count2!=0)
				{
					p->prior->next=p->next;
					p->next->prior=p->prior;
					p->next=p->next->next;
					p->prior=p->next->prior;
					p->prior->next=p;
					p->next->prior=p;//调换两个链点的顺序
				}
				else
				{
					list->head=p->next;
					p->next->prior=NULL;
					p->next->prior=p;
					p->next=p->next->next;
					list->head->next=p;
					p->prior=list->head;
				}
			}
			else
			{
				p=p->next;
			}
		}
	}
	return; 
}

int main()
{
	dlist_type list;
	list.head=NULL;
	list.tail=NULL;
	list.length=0;
	creat_list(&list);//以-100结尾 
	show_list(&list);
	sort_list(&list);
	printf("Sort succeed!\n");
	show_list(&list);
	return 0;
}
