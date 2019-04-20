#include <stdio.h>
#include<stdlib.h>
struct node
{
	struct node* left;
	struct node* right;
	char data;
};
typedef struct node Node;
Node* insert(char a[],int n){
	Node* node=NULL;
	if(a[n]!='\0'){
		node = (Node*)malloc(sizeof(Node));
		node->left = insert(a,2*n+1);
		node->data = a[n];
		node->right = insert(a,2*n+2);
	}
	return node;
}
void inorder(Node* node)
{
 if(node!=NULL)
 {
  inorder(node->left);
  printf("%c ",node->data);
  inorder(node->right);
 }
}
void main(){
	Node* node=NULL;
	char a[]={'1','2','3','4','a','b','\0'};
	node=insert(a,0);
	inorder(node);
}
