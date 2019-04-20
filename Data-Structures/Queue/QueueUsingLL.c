//queue using the linked list concept
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* link;
	};
typedef struct Node node;
struct Node* head = NULL;
void queue(){
	node* temp;
	temp=(node*)malloc(sizeof(node));
	printf("Enter the elements of the queue\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(head==NULL)
 	{
 		head = temp;
 	}
 	else
 	{
 		struct Node* p;
 		p=head;
 	while(p->link!=NULL)
 	{
 		p=p->link;
 	}
 	p->link=temp;
 	}
	}
int dequeue(){
	node* temp;
	temp=head;
	head=temp->link;
	return temp->data;
	}
void printlist(){
	struct Node *ptr=head;
	printf("\n[");
	//starting to print
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->link;
	}
	printf("]\n");
	}	
int main(){
	int j;
	printf("Enter the number of elements you want to add in the queue\n");
	scanf("%d",&j);
	for(int k=0;k<j;k++){
		queue();
	}
	printf("printing the given queue\n");
	printlist();
	int f=dequeue();
	printf("%d\n",f);
	printlist();
	}
	
