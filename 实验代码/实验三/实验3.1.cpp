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

void push_lstack(lstack_type *lstack,int x)//入栈函数 
{
	node_type *p;
	p=(node_type *)malloc(sizeof(node_type));
	p->data=x;
	p->next=lstack->top;
	lstack->top=p;
	lstack->length++;
	return; 
}


void pop_lstack(lstack_type *lstack)//出栈函数 
{
	node_type *p;
	p=lstack->top;
	lstack->top=p->next;
	free(p);
	lstack->length--;
	return;
}


void show_lstack(lstack_type *lstack)//显示栈内元素 
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
			push_lstack(&lstack,x);//入栈 
		}
	}
	show_lstack(&lstack);//显示栈内元素 
	pop_lstack(&lstack); //出栈
	pop_lstack(&lstack);//出栈
	printf("Pop succeed!\n");
	show_lstack(&lstack);//显示出栈两次后的栈内元素 
	return 0;
}
