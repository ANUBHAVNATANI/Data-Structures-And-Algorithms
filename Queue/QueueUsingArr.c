//queue implementation in c using array
#include<stdio.h>
#include<stdbool.h>
#define MAX 20
int queue[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;
int peek(){
	return queue[front];
	}
bool isEmpty(){
	return itemCount == 0;
	}
bool isFull(){
	return itemCount == MAX;
	}
int size(){
	return itemCount;
	}
void insert(int data){
	if(!isFull())
	{	
		if(rear==MAX-1){
			rear = -1;
			}
			queue[++rear]=data;
			itemCount++;
	}
	}
int dequeue(){
	int data = queue[front++];
	if(front==MAX){
		front=0;
		}
	itemCount--;
	return data;
	}
int print(int n){
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",queue[i]);
	}
	printf("\n");
	}
int main(){
	int n,data;
	printf("Enter the length of the queue you would like to enter in the computer\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter the data\n");
		scanf("%d",&data);
		insert(data);
	}
	print(n);
	int num=dequeue();
	printf("%d\n",num);
	num=dequeue();
	printf("%d\n",num);
	int sized=size();
	printf("%d",sized);
	}
