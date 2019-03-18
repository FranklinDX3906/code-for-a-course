#include<stdio.h>
#define MAXNUM 20

typedef struct dhstack
{
	int top1;//��0��һ�˿�ʼ 
	int top2;//��MAXNUM-1��һ�˿�ʼ 
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
	stack.top1=-1;//top1��0��һ�˵�ջ�� 
	stack.top2=MAXNUM;//top2��MAXNUM��һ�˵�ջ�� 
	int choice,which;//choiceָ����ѡ��push����pop��whichָ����ѡ��top1����top2 
	int in;//�����Ԫ��
	int out;//���Ԫ�� 
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
		if(choice==1)//��ջ 
		{
			if(stack.top1!=stack.top2-1)//�Ⱥų���ʱջ��
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
		else//��ջ 
		{
			if((which==1&&stack.top1==-1)||(which==2&&stack.top2==MAXNUM))//��֤ջ��Ϊ��
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
