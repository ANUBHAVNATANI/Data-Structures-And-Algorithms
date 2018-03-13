//implementation of Circular Queue using the linked list
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
	temp->link=head;
	if(head==NULL){
		
		head=temp;
		temp->link = head;
		}
		
	else{
		
		node* p;
		p=head;
		while(p->link!=head){
			p=p->link;
		}
		p->link=temp;
		
		}
	}
int dequeue(){
	node *p;
	int q;
	p=head;
	while(p->link!=head){
		p=p->link;
		}
	q=head->data;
	head=head->link;
	p->link=head;
	return(q);
	}
void show(){
	node* p;
	p=head;
	while(p->link!=head){
		printf("%d",p->data);
		p=p->link;
		}
		printf("%d",p->data);
		printf("\n");
	}
int main(){
	int n,element;
	printf("Enter the number of element you want to add to the queue\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&element);
		queue(element);
		} 
	show();
	int d=dequeue();
	printf("%d ",d);
	show();
	d=dequeue();
	printf("%d ",d);
	d=dequeue();
	printf("%d ",d);
	show();
	}
	
	
