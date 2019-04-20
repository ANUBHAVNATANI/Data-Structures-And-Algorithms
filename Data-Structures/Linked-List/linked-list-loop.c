#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* link;
	};
typedef struct Node node;
node* head=NULL;
void append(){
	node* temp;
	//declaring a variable of type of our structure
	temp=(node*)malloc(sizeof(node));
	//declared the temperory space for the variale malloc allocates a block of memory for the the variable
	printf("Enter Some data\n");	
 	scanf("%d",&temp->data);
 	temp->link=NULL;
 	//puting the link of the variable to the null
 	if(head==NULL)
 	{
 		head = temp;
 	}
 	else
 	{
 		node* p;
 		p=head;
 	while(p->link!=NULL)
 	{
 		p=p->link;
 	}
 	p->link=temp;
 	}
 	}
void loopfind(){
	//using the fast pointer and slow pointer concept to find the loop
	//slow pointer is one step behind the fast pointer 
	//if there is loop then they will definetly meet once
	node* fast_ptr=head;
	node* slow_ptr=head;
	while(slow_ptr!=NULL){
		slow_ptr=slow_ptr->link;
		fast_ptr=fast_ptr->link->link;
		if(slow_ptr->data==fast_ptr->data){
			printf("Loop detected");
			break;
			}
		}
	}
void main(){
	int j; 
	//looping to enter the number untill user wanted
	while(1){
		printf("Enter 1 to append to the linked list and any other number to terminate the linked list\n");
		scanf("%d",&j);
		if(j==1){
			append();
			}
		else{
			break;
			}
	}
	//creating the loop
	node* p=head;
	node* q=head->link;
	while(p->link!=NULL){
		p=p->link;
		}
		p->link=q;         
	loopfind();
}
