//linked list formation and  printing the linked list
#include<stdio.h>
#include<stdlib.h>
//here i used stdlib.h for using the dynamic memory allocation function like malloc,free,calloc etc. 
struct node{							
	int data;				
	struct node* link;
	};
//here i have made a structure of the linked list.
struct node* root=NULL;
//here i have declared the head variable the null link
void append(){
	struct node* temp;
	//declaring a variable of type of our structure
	temp=(struct node*)malloc(sizeof(struct node));
	//declared the temperory space for the variale malloc allocates a block of memory for the the variable
	printf("Enter Some data\n");	
 	scanf("%d",&temp->data);
 	temp->link=NULL;
 	//puting the link of the variable to the null
 	if(root==NULL)
 	{
 		root = temp;
 	}
 	else
 	{
 		struct node* p;
 		p=root;
 	while(p->link!=NULL)
 	{
 		p=p->link;
 	}
 	p->link=temp;
 	}
 	}
 //traversing through the list and printing the list
void printlist(){
	struct node *ptr=root;
	printf("\n[");
	//starting to print
	while(ptr!=NULL)
	{
		printf(" %d ",ptr->data);
		ptr=ptr->link;
	}
	printf("]");
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
	printf("printing the given linked list\n");
	printlist();
	}
