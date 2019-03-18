#include<stdio.h>
#include<malloc.h>

typedef struct node_type
{
	int data;
	struct node_type *next;
}node_type;

typedef struct lstack_type
{
	struct node_type *top;
	int length;
}lstack_type;

void push_lstack(lstack_type *lstack,int x)//��ջ���� 
{
	node_type *p;
	p=(node_type *)malloc(sizeof(node_type));
	p->data=x;
	p->next=lstack->top;
	lstack->top=p;
	lstack->length++;
	return; 
}


void pop_lstack(lstack_type *lstack)//��ջ���� 
{
	node_type *p;
	p=lstack->top;
	lstack->top=p->next;
	free(p);
	lstack->length--;
	return;
}


void show_lstack(lstack_type *lstack)//��ʾջ��Ԫ�� 
{
	node_type *p;
	int count;
	p=lstack->top;
	count=1;
	printf("The stack now is:\n");
	while(count<=lstack->length&&p!=NULL)
	{
		printf("%d, ",p->data);
		count++;
		p=p->next;
	}
	return;
}


int main()
{
	lstack_type lstack;
	lstack.top=NULL;
	lstack.length=0;
	int x;
	while(1)
	{
		printf("Please enter the data you want to push into the stack(end with 0).\n");
		scanf("%d",&x);
		printf("\n");
		if(x==0)
		{
			break;
		}
		else
		{
			push_lstack(&lstack,x);//��ջ 
		}
	}
	show_lstack(&lstack);//��ʾջ��Ԫ�� 
	pop_lstack(&lstack); //��ջ
	pop_lstack(&lstack);//��ջ
	printf("Pop succeed!\n");
	show_lstack(&lstack);//��ʾ��ջ���κ��ջ��Ԫ�� 
	return 0;
}
