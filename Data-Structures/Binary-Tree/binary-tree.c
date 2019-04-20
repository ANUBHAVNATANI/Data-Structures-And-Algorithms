#include "stdio.h"
#include "stdlib.h"
struct node
{
	int data;
	struct node *left;
	struct node *right;
	
};
typedef struct node Node;
Node* newNode(int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}
void PostOrder(Node* node){
	if(node==NULL)
		return;
	PostOrder(node->left);
	PostOrder(node->right);
	printf("%d ",node->data);
}
void InOrder(Node* node){
	if(node==NULL)
		return;
	InOrder(node->left);
	printf("%d ",node->data);
	InOrder(node->right);
}
void PreOrder(Node* node){
	if(node==NULL)
		return;
	printf("%d ",node->data);
	PreOrder(node->left);
	PreOrder(node->right);
} 
int main(){
	Node *root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);
	root->right->right = newNode(40);
	printf("Printing in PostOrder\n");
	PostOrder(root);
	printf("\n");
	printf("Printing in PreOrder\n");
	PreOrder(root);
	printf("\n");
	printf("Printing in InOrder\n");
	InOrder(root);
	printf("\n");
	return 0;
}