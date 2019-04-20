#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
	int data;
	struct node* back;
	struct node* front;
	};
struct node* head=NULL;
struct node* last=NULL;
struct node* current=NULL;
bool isEmpty(){
	return head == NULL;
	}
int length(){
	int length=0;
	struct node *current;
	for(current=head;current!=NULL;current=current->front){
		length++;
		}
	return length;
	}
void displayForward(){
	struct node *ptr=head;
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->front;
	}
	}
void displayBackward(){
	struct node *ptr=last;
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->back;
	}
	}
void insertFirst(int element){
	struct node *link=(struct node*)malloc(sizeof(struct node));
	link->data=element;
	if(isEmpty()){
		last=link;
		}
	else{
		head->back=link;
		}
		link->front=head;
		head=link;
	}
void insertBack(int element){
	struct node *link=(struct node*)malloc(sizeof(struct node));
	link->data=element;
	if(isEmpty()){
		last=link;
		}
	else{
		last->front=link;
		link->back=last;
		}
	last=link;
	}
struct node* deleteFirst(){
	struct node* tempLink=head;
	if(head->front==NULL)
	{	
	last=NULL;
	}
	else{
	head->front->back=NULL;
	}
	head=head->front;
	return tempLink;
	}
struct node* deleteLast(){
	struct node* tempLink=last;
	if(head->front=NULL)
	{	
		head=NULL;
	}
	else{
	last->back->front=NULL;
	}
	last=last->back;
	return tempLink;
	}

int main(){
	int n,element;
	printf("Enter the number of elements you want to add in the double linked list\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	scanf("%d",&element);
	insertFirst(element);
	}
	displayBackward();
	}	
	
