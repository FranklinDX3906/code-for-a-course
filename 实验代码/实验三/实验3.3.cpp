#include<stdio.h>
#define MAXNUM 20

typedef struct dhstack
{
	int top1;//从0那一端开始 
	int top2;//从MAXNUM-1那一端开始 
	int data[MAXNUM];
}dhstack;

void push_stack(dhstack *stack,int in,int which)
{
	if(which==1)
	{
		stack->top1++;
		stack->data[stack->top1]=in;
	}
	else
	{
		stack->top2--;
		stack->data[stack->top2]=in;
	}
	return;
}

int pop_stack(dhstack *stack,int which)
{
	int out;
	if(which==1)
	{
		out=stack->data[stack->top1];
		stack->top1--;
	}
	else
	{
		out=stack->data[stack->top2];
		stack->top2++;
	}
	return out;
}
void show_stack(dhstack *stack)
{
	printf("The stack now is:\n");
	for(int i=0;i<MAXNUM;i++)
	{
		printf("%d, ",stack->data[i]);
	}
	printf("\ntop1= %d",stack->top1);
	printf("\ntop2= %d\n\n\n",stack->top2);
	return;
}

int main()
{
	dhstack stack;
	stack.top1=-1;//top1在0那一端的栈底 
	stack.top2=MAXNUM;//top2在MAXNUM那一端的栈底 
	int choice,which;//choice指的是选择push还是pop，which指的是选择top1还是top2 
	int in;//输入的元素
	int out;//输出元素 
	for(int i=0;i<MAXNUM;i++)
	{
		stack.data[i]=0;
	}
	while(1)
	{
		printf("Please choose what you want to do:\n1: push stack\n2: pop stack\n");
		scanf("%d",&choice);
		printf("Please choose which side you want to do with the stack\n1: start with data[0]\n2: start with data[%d]\n",MAXNUM-1);
		scanf("%d",&which);
		if(choice==1)//入栈 
		{
			if(stack.top1!=stack.top2-1)//等号成立时栈满
			{
				printf("Please input the data you want to push into the stack:\n");
				scanf("%d",&in);
				push_stack(&stack,in,which);
			}
			else
			{
				printf("The stack is full!\n");
			} 
		}
		else//出栈 
		{
			if((which==1&&stack.top1==-1)||(which==2&&stack.top2==MAXNUM))//保证栈不为空
			{
				printf("The stack is empty!\n");
			} 
			else
			{
				out=pop_stack(&stack,which);
				printf("The data is %d\n",out); 
			}
		}
		show_stack(&stack);
	}

	return 0;
}
