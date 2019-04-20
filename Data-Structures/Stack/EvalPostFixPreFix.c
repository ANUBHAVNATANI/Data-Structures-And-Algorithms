#define size 20
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int stack[size];
int top=-1;
void push(int element){
	if(top==size-1){
		printf("Stack is full");
		}
	else{
		stack[++top]=element;
		}
	}
int pop(){
	if(top==-1){
		printf("Stack is empty");
		}
	else{
		int data = stack[top];
		top=top-1;
		return data;
		}
	}
int post_fix(char a[],int n){
	for(int i=0;i<n;i++){
		//printf("%s \n",a);
			if(isdigit(a[i])){
			int num=a[i]-48;
			push(num);
			}
			else{
				int value1=pop();
				//printf("%d \n",value1);
				int value2=pop();
				//printf("%d \n",value2);
				switch(a[i]){
				case '+':push(value2+value1);break;
				case '-':push(value2-value1);break;
				case '*':push(value2*value1);break;
				case '/':push(value2/value1);break;
		}
	
	}
	}
	return pop();
	}
int pre_fix(char a[],int n){
	//printf("HI");
	//printf("%d",n);
	for(int i=n-1;i>=0;i--){
		//printf("%s",a);
		//printf("%d",i);
		//printf("%s \n",a);
			if(isdigit(a[i])){
			int num=a[i]-48;
			//printf("%d",num);
			push(num);
			}
			else{
				int value1=pop();
				//printf("%d \n",value1);
				int value2=pop();
				//printf("%d \n",value2);
				switch(a[i]){
				case '+':push(value1+value2);break;
				case '-':push(value1-value2);break;
				case '*':push(value1*value2);break;
				case '/':push(value1/value2);break;
		}
	
	}
	}
	return pop();
	}

int main()
{
 char a[100];
 int d;
 
 printf("Enter 1 for prefix evaluation or 2 for postfix evaluation\n");
 scanf("%d",&d);
 if(d==1){
 scanf("%s",a);
 int k=pre_fix(a,strlen(a));
  printf("Result\n");
  printf ("%d",k);
 }
 else if(d==2){
 scanf("%s",a);
 int k=pre_fix(a,strlen(a));
  printf("Result\n"); 
  printf ("%d",k);
 }
 else{
 printf("Enter a valid number\n");
 }
 
    return 0;
}
