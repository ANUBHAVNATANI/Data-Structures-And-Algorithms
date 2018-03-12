#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* link;
};
struct node* head;

void insert(int x)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	if(head==NULL)
	{
		temp->link=head;
		head=temp;
		return;
	}
	struct node* temp1=head;
	while(temp1->link!=NULL)
	{
		temp1=temp1->link;
	}
	temp->link=temp1->link;
	temp1->link=temp;
}

void print()
{
	struct node* temp=head;
	printf("Numbers are: ");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}

void reverse(struct node* temp)
{
	if(temp->link==NULL)
	{
		head=temp;
		return;
	}
	else reverse(temp->link);
	struct node* temp1=temp->link;
	temp1->link=temp;
	temp->link=NULL;
}

int main()
{
	int n,x;
	head=NULL;
	printf("How many numbers?\n");
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		insert(x);
		print();
	}
	reverse(head);
	printf("After reversing ");
	print();
	return 0;
}
