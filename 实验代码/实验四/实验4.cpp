#include<stdio.h>
#include<malloc.h>
/*由于实验4的三个必做题可以放在一起，所以以下为整个实验4*/
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
}stack_type;//用于遍历的栈 

/*typedef struct tree_type
{
	tnode_type *root;
	int number;//唯一确定一棵树 
}tree_type;
*/

void insert_tree(tnode_type *root,int in)//建立排序树 
{
	tnode_type *temp,*p;//temp用于申请空间，p用于指向树作比较 
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


void show_tree(tnode_type *root)//用三种顺序输出树 
{
	stack_type stack;
	stack.top=-1; 
	tnode_type *p;//用于遍历的指针 
	
	printf("\n先序遍历：\n");
	p=root;//这里不考虑根节点空的情况 
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
	printf("\n中序遍历\n");
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
	printf("\n后序遍历\n");
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
				flag[i]=1;//表示已访问 
				i--; 
				p=NULL;
			}
		}
	}
	
	return;
}


int caculate_tree(tnode_type *root)//计算树的深度 
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


void reverse_show(tnode_type *root)//求二叉树排序的反序结果 
{
	printf("反序输出的结果是：");	
	stack_type stack;//下面进行输出 
	stack.top=-1; 
	tnode_type *p;//用于遍历的指针
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


int main()//基本思路是：先创建树，然后做选择：排序插入（4-2）并显示三种遍历（4-1）或计算深度（4-3）或反序结果（4-3）， 
{
	tnode_type root;//根节点 
	root.data=-100;//根节点的值为0
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
			 	insert_tree(&root,in);//排序插入 
			 	show_tree(&root);//展示三种顺序
			 	printf("\n\n\n");
			 	break;
			case 2:
				printf("\n树的深度是：\n");
				printf("%d\n\n\n",caculate_tree(&root));
				break;
			case 3:
				reverse_show(&root);//反序结果 
				printf("\n\n\n");
				break;
		}	 
	}
	return 0;
}
