#include<stdio.h>
#include<malloc.h>
/*����ʵ��4��������������Է���һ����������Ϊ����ʵ��4*/
typedef struct tnode_type
{
	int data;
	struct tnode_type *Lchild;
	struct tnode_type *Rchlid;
}tnode_type;

typedef struct stack_type
{
	tnode_type data[100];
	int top;
}stack_type;//���ڱ�����ջ 

/*typedef struct tree_type
{
	tnode_type *root;
	int number;//Ψһȷ��һ���� 
}tree_type;
*/

void insert_tree(tnode_type *root,int in)//���������� 
{
	tnode_type *temp,*p;//temp��������ռ䣬p����ָ�������Ƚ� 
	if(root->data==-100)
	{
		root->data=in;
	}
	else
	{
		p=root;
		temp=(tnode_type *)malloc(sizeof(tnode_type));
		temp->data=in;
		temp->Lchild=NULL;
		temp->Rchlid=NULL;
		while(p!=NULL)
		{
			if(temp->data<p->data)
			{
				if(p->Lchild==NULL)
				{
					p->Lchild=temp;
					break;
				}
				else
				{
					p=p->Lchild;
				}
			}
			else
			{
				if(p->Rchlid==NULL)
				{
					p->Rchlid=temp;
					break;
				}
				else
				{
					p=p->Rchlid;
				}
			}
		}
	}
	return;
}


void show_tree(tnode_type *root)//������˳������� 
{
	stack_type stack;
	stack.top=-1; 
	tnode_type *p;//���ڱ�����ָ�� 
	
	printf("\n���������\n");
	p=root;//���ﲻ���Ǹ��ڵ�յ���� 
	while(p!=NULL||stack.top!=-1)
	{
		if(p!=NULL)
		{
			printf("%d,",p->data);
			stack.top++;
			stack.data[stack.top]=*p;
			p=p->Lchild;
		}
		else
		{
			p=&stack.data[stack.top];
			stack.top--;
			p=p->Rchlid;
		}
	}
	
	stack.top=-1;
	printf("\n�������\n");
	p=root;
	while(p!=NULL||stack.top!=-1)
	{
		if(p!=NULL)
		{
			stack.top++;
			stack.data[stack.top]=*p;
			p=p->Lchild;
		}
		else
		{
			p=&stack.data[stack.top];
			stack.top--;
			printf("%d,",p->data);
			p=p->Rchlid;
		}
	}
	
	stack.top=-1;
	printf("\n�������\n");
	p=root;
	int flag[100];
	int i;
	for(i=0;i<100;i++)
	{
		flag[i]=0;
	}
	i=0;
	while(p!=NULL||stack.top!=-1)
	{
		if(p!=NULL)
		{
			stack.top++;
			i++;
			stack.data[stack.top]=*p;
			flag[i]=0;
			p=p->Lchild;
		}
		else
		{
			p=&stack.data[stack.top];
			if(p->Rchlid!=NULL&&flag[i+1]==0)
			{
				p=p->Rchlid;
			}
			else
			{
				stack.top--;
				printf("%d,",p->data);
				flag[i]=1;//��ʾ�ѷ��� 
				i--; 
				p=NULL;
			}
		}
	}
	
	return;
}


int caculate_tree(tnode_type *root)//����������� 
{
	int degree;
	int Ldegree,Rdegree;
	if(root->Lchild==NULL)
	{
		Ldegree=0;
	}	
	else
	{
		Ldegree=caculate_tree(root->Lchild);
	}
	if(root->Rchlid==NULL)
	{
		Rdegree=0;
	}
	else
	{
		Rdegree=caculate_tree(root->Rchlid);
	}
	if(Ldegree>Rdegree)
	{
		degree=Ldegree+1;
	}
	else
	{
		degree=Rdegree+1;
	}
	return degree;
}


void reverse_show(tnode_type *root)//�����������ķ����� 
{
	printf("��������Ľ���ǣ�");	
	stack_type stack;//���������� 
	stack.top=-1; 
	tnode_type *p;//���ڱ�����ָ��
	printf("\n");
	p=root;
	while(p!=NULL||stack.top!=-1)
	{
		if(p!=NULL)
		{
			stack.top++;
			stack.data[stack.top]=*p;
			p=p->Rchlid;
		}
		else
		{
			p=&stack.data[stack.top];
			stack.top--;
			printf("%d,",p->data);
			p=p->Lchild;
		}
	}
	return;
}


int main()//����˼·�ǣ��ȴ�������Ȼ����ѡ��������루4-2������ʾ���ֱ�����4-1���������ȣ�4-3����������4-3���� 
{
	tnode_type root;//���ڵ� 
	root.data=-100;//���ڵ��ֵΪ0
	root.Lchild=NULL;
	root.Rchlid=NULL;
	int choice,in;
	while(1)
	{
		printf("Please choose what you want to do:\n1: insert a data by order\n2: caculate the depth\n3: print the reversed result\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Please input the data you want to insert into the tree:\n");
			 	scanf("%d",&in);
			 	insert_tree(&root,in);//������� 
			 	show_tree(&root);//չʾ����˳��
			 	printf("\n\n\n");
			 	break;
			case 2:
				printf("\n��������ǣ�\n");
				printf("%d\n\n\n",caculate_tree(&root));
				break;
			case 3:
				reverse_show(&root);//������ 
				printf("\n\n\n");
				break;
		}	 
	}
	return 0;
}
