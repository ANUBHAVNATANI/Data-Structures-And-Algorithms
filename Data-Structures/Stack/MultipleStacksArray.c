//Multiple stack implementation in an array
#include<stdio.h>
#define SIZE 10
int stack[SIZE];
int top=-1;
int rear=SIZE;
void pushst1(int element){
	if(top!=(SIZE/2)-1){
		stack[++top]=element;
	}
	else{
		printf("1 st Stack full\n");
		}
	}
void pushst2(int element){
	if(rear!=SIZE/2-1){
		stack[--rear]=element;
		}
	
	else{
		printf("Second stack full\n");
		}
	}
void printst1(int n)
	{
	int i;
	for(i=0;i<n;i++)
	{
	printf("%d",stack[i]);
	}
	printf("\n");
	}
void printst2(int n)
	{
	int i;
	for(i=SIZE-1;i>=SIZE-n-1;i--)
	{
	printf("%d",stack[i]);
	}
	printf("\n");
	}
int popst1()
	{
	int element;
	element=stack[top];
	top--;
	return top;
	}
int popst2()
	{
	int element;
	element=stack[rear];
	rear++;
	return element;
	}
void main(){
	int n,element;
	printf("Enter the number of element you want to add to the stack1\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d ",&element);
		pushst1(element);
		} 
	
	printst1(n);
	int d=popst1();
	printf("%d",d);
	printst1(n-1);
	printf("Enter the number of element you want to add to the stack2\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d ",&element);
		pushst2(element);
		} 
	
	printst2(n);
	d=popst2();
	printf("%d",d);
	printst2(n-1);
	}
