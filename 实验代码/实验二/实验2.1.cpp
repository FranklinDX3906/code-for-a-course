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

void get_element(int *x,int *l)
{
	printf("please input the element x= ");
	fflush(stdin);
	scanf(" %d",x);
	printf("\n");
	printf("the location of inserting l= ");
	fflush(stdin);
	scanf("%d",l);
	printf("\n");
	return;
}

void create_list(list_type *table)  
{
	int x;
	int i;
	node_type *temp;

	table->head = NULL;
	table->tail = NULL;
	table->length = 0;
	for(i = 5; i >= 1 ; i --){
		printf("input the data of a%d = ",i);
		fflush(stdin);
		scanf(" %d",&x);
		printf("\n");

		temp = (node_type *)malloc(sizeof(node_type));
		temp->data = x;
		temp->next = NULL;
		temp->next = table->head;
		table->head = temp;
	}
	table->length = 5;
}
/* create a structure of node with the inputting data*/
node_type* create_node(int new_node)
{
	node_type* temp;
	temp = (node_type*)malloc(sizeof(node_type));
	temp->data = new_node;
	temp->next = NULL;
	return temp;
}
/* insert the new_node before the spacified location */
void insert_list(list_type *table,int new_node,int location)
{
	int count;
	node_type* new_nodep , *p;

	new_nodep = create_node(new_node);
	if(location == 1)
	{
		new_nodep->next = table->head;
		table->head = new_nodep;
		table->length ++;
	}
	else
	{
		count = 1;
		p = table->head;
		while( count < location-1&& p->next != NULL)
		{
			count ++;
			p = p->next;
		}
		new_nodep->next = p->next;
		p->next = new_nodep;
		table->length ++;
	}

	return;
}
void delete_list(list_type *table,int location)
{
	int count;
	node_type * temp,*q;

	if(location < 0 || location > table->length){
		printf("error position\n");
	}
	if(location == 1){
		temp = table->head;
		table->head = table->head->next;
		free(temp);
		table->length --;
		return;
	}
	count = 1;
	temp = table->head;
	while(count < location - 1 && temp->next != NULL){
		count ++;
		temp = temp->next;
	}
	q = temp->next;
	temp->next = temp->next->next;
	free(q);
	table->length --;
}
void show_list(list_type *table)
{
	int count;
	node_type * temp;
	count = 1;
	temp = table->head;
	while(count <= table->length && temp != NULL){
		printf("%d, ",temp->data);
		count ++;
		temp = temp->next;
	}
	printf("\n");
}
void menu()
{
	printf("\n");
	printf("  menu\n");

	printf("  1. insert a element\n");
	printf("  2. delete a element\n");
	printf("  0. exit program\n");
	printf(" enter your choise: ");
	
}
int main(void)
{
	int x;
	int l;
	int choise;
	list_type table;
	
	create_list(&table); 
	show_list(&table); 

	while(1){
		menu();
		fflush(stdin);
		scanf("%d",&choise);
		switch(choise){
		case 1:
			get_element(&x,&l);
			insert_list(&table,x,l);
			printf("insert ok!\n");
			show_list(&table);
		break;
		case 2:
			printf("input the element number to delete: ");
			fflush(stdin);
			scanf("%d",&x);
			delete_list(&table,x);
			printf("delete ok!\n");
			show_list(&table);

		break;
		case 0:
			goto end;
		break;
		}
	}
  
end:
	return 0;
}
