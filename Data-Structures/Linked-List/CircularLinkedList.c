#include<stdlib.h>

#include<stdio.h>

struct Node

{

  int data;

  struct Node* link;

};

struct Node* head=NULL;

void Insert(int x)

{

  struct Node* temp=(struct Node*)malloc(sizeof(struct Node));

  temp->data=x;

  temp->link=head;

  head=temp;

}

void Circular()

{

  struct Node* temp=head;

  while(temp->link!=NULL)

  {

    temp=temp->link;

  }

  temp->link=head;

}

void Print()

{

  struct Node* temp=head;

  while(temp->link!=head)

  {

    printf("%d ",temp->data);

    temp=temp->link;

  }
	printf("%d",temp->data);
  printf("\n");

}

int main()

{

  int i,n,x;

  printf("No. of nodes in the linked lists\n");

  scanf("%d",&n);

  printf("Enter the element\n");

  for(i=0;i<n;i++)

  {

    scanf("%d",&x);

    Insert(x);

  }

Circular();
printf("Printing Reversely the linked list\n");
  Print();

}
//Coded given by HIMANSHU SHARMA
