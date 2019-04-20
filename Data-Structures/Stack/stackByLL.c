#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* link;
	};
typedef struct Node node;
node* head=NULL;
void push(int element){
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=element;
	if(head==NULL){
		head=temp;
		temp->link=NULL;
	}
	else{
		temp->link=head;
		head=temp;
		}
	}
int pop(){
	int data;
	data=head->data;
	head=head->link;
	return data;
	}
void show(){
	node* p= head;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->link;
		}
		printf("\n");
	}
void main(){
	push(40);
	push(30);
	push(60);
	push(50);
	show();
	int d=pop();
	printf("%d \n",d);
	show();
	}
