#define N 15
#include<stdio.h>



typedef struct queue_type 
{
	int data[N];
	int front,rear;
}queue_type;


int dequeue(queue_type *queue)//���Ӻ��� 
{
	int x;
	queue->front=(queue->front+1)%N;
	x=queue->data[queue->front];
	queue->data[queue->front]=-100;
	return x;
}


void enqueue(queue_type *queue,int x)//��Ӻ��� 
{
	queue->rear=(queue->rear+1)%N;
	queue->data[queue->rear]=x;
	return;
}

void aa(queue_type *queue)//Ҫ��ĺ��� 
{
	int out;
	while(queue->front<10)
	{
		out=dequeue(queue);//�����ӵ���������������ж�
		if(out>0)
		{
			enqueue(queue,out);
		} 
	}
	return; 
}


void show_queue(queue_type *queue)//չʾ���� 
{
	int count;
	count=queue->front+1;
	printf("The queue now is:\n");
	while(count!=queue->rear+1)
	{
		printf("%d, ",queue->data[count]);
		count=(count+1)%N;
	}
	return;
} 


int main()
{
	queue_type queue;
	queue.front=0;
	queue.rear=10;//��Ϊ��ֱ�Ӹ����и�ֵ�����Ըտ�ͷ�Ͱ�ָ��䵽�涨�ĵط� 
	int a[15]={-100,2,3,-4,6,-5,8,-9,7,-10,20,-100,-100,-100,-100};
	for(int i=0;i<15;i++)
	{
		queue.data[i]=a[i];
	}
	show_queue(&queue);
	printf("\n"); 
	aa(&queue);
	show_queue(&queue); 
	return 0;
}
