#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* link;
	};
typedef struct Node node;
node* head=NULL;
void queue(int element){
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=element;
	temp->link=NULL;
	if(head==NULL){
		head=temp;
		}
	else{
		node* p;
		p=head;
		while(p->link!=NULL){
			p=p->link;
			}
		p->link=temp;
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
	queue(45);
	queue(45);
	queue(45);
	queue(45);
	queue(45);
	show();
	int d=pop();
	printf("%d",d);
	show();
	}
