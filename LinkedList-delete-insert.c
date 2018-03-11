#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *link;
};

struct node *head;

void insert(int x)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x ;
	if(head==NULL)
	{
		temp->link = head;
		head = temp;
		return;
	}
	struct node *temp1 = head;
	while(temp1->link!=NULL)
	{
		temp1=temp1->link;
	}
	temp->link = temp1->link;
	temp1->link = temp;
}

void insertn(int y,int z)
{
	int i;
	struct node *temp=(struct node*)malloc(sizeof(temp));
	temp->data = y;
	if(head==NULL)
	{
		temp->link = head;
		head = temp;
	}
	struct node *temp1 = head;
	for(i=1;i<=z-1;i++)
	{
		temp1 = temp1->link;
	}
	temp->link=temp1->link;
	temp1->link = temp;
}

void Delete(int z)
{
	int i;
	struct node *temp = head;
	for(i=1;i<=z-1;i++)
	{
		temp = temp->link;
	}
	struct node *temp1 = temp->link;
	temp->link = temp1->link;
	free(temp1);
	
}

void reverse()
{
	struct node *prev,*current,*next;
	current = head;
	prev = NULL;
	while(current!=NULL)
	{
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void print()
{
	struct node *temp = head;
	printf("The Elements are : ");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}
 
int main()
{
	int n,x,y,z,i,j;
	printf("Enter the Number of Elements : ");
	scanf("%d",&n);
	head=NULL;
	while(n--)
	{
		scanf("%d",&x);
		insert(x);
		print();		
	}
	printf("Where to insert : ");
	scanf("%d",&z);
	printf("What to insert : ");
	scanf("%d",&y);
	insertn(y,z);
	print();
	printf("Where to delete : ");
	scanf("%d",&j);
	Delete(j);
	print();
	reverse();
	print();
	
}
