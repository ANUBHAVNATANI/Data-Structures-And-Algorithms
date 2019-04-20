#define size 20
#include<stdio.h>
int stack[size];
int top=-1;
void push(int element){
	if(top==size-1){
		printf("Stack Overflow\n");
		}
	else{
		top++;
		stack[top]=element;	
		}
	}
int pop(){
	int data;
	if(top==-1){
		printf("Stack Empty\n");
		}
	else{
		data=stack[top];
		top=top-1;
		return data;
		}
	}
void stackprint(int n)
	{
	int i;
	for(int i=0;i<n;i++)
	{	
		printf("%d ",stack[i]);
		printf("\n");
	}
	}
void main(){
	push(5);
	push(6);
	push(7);
	push(8);
	push(9);
	
	stackprint(5);
	int d=pop();
	printf("\n");
	printf("%d",d);
	printf("\n");
	stackprint(5);
	}
