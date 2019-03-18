#include<stdio.h>
#define MAXNUM 20

typedef struct extqueue
{
	int front;
	int rear;
	int flag;//展示是否满，1满0不满 
	int data[MAXNUM]; 
}extqueue;

void push_queue(extqueue *queue,int in)
{
	queue->rear=(queue->rear+1)%MAXNUM;
	queue->data[queue->rear]=in;
	if(queue->rear==queue->front)
	{
		queue->flag=1;
	}
	return;
}

int pop_queue(extqueue *queue)
{
	int out;
	if(queue->rear==queue->front)
	{
		queue->flag=0;
	}
	queue->front=(queue->front+1)%MAXNUM;
	out=queue->data[queue->front];
	queue->data[queue->front]=-100;
	return out;
}

void show_queue(extqueue *queue)
{
	printf("The queue is: \n");
	for(int i=0;i<MAXNUM;i++)
	{
		printf("%d, ",queue->data[i]);
	}
	printf("\nThe front is at: %d",queue->front);
	printf("\nThe rear is at: %d",queue->rear);
	switch(queue->flag)
	{
		case 1:printf("\nThe queue is full.\n\n\n");
		case 0:printf("\nThe queue is not full.\n\n\n");
		break;
	}
	return;
}

int main()
{
	extqueue queue;
	queue.front=0;
	queue.rear=0;
	queue.flag=0;
	int choice;
	int in;//入队数 
	int out;//出队数 
	for(int i=0;i<MAXNUM;i++)
	{
		queue.data[i]=-100;//初值 
	}
	while(1)
	{
		printf("Please choose what you to do:\n1: push\n2: pop\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			if(queue.rear%MAXNUM==queue.front&&queue.flag==1)
			{
				printf("The queue is full!\n");
			}
			else
			{
				printf("Please input the data:\n");
				scanf("%d",&in);
				push_queue(&queue,in);
			}
		}
		else
		{
			if(queue.rear%MAXNUM==queue.front&&queue.flag==0)
			{
				printf("The queue is empty!\n");
			}
			else
			{
				out=pop_queue(&queue);
				printf("The data poped out is: %d\n",out);
			}
		}
		show_queue(&queue);
	}
	return 0;
}
