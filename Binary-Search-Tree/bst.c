//bst implementation in c
//structure of node in the bst
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
	};
//creating a new node in the binary search tree
struct node* newNode(int element){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=element;
	temp->left=NULL;
	temp->right=NULL;
	return(temp);
	}
//insert a node in the binary search tree
struct node* insert(struct node* root,int data){
	struct node* temp=newNode(data);
	if(root==NULL){
		return temp;
		}
	else{
		if(root->data>data){
			root->left=insert(root->left,data);
			}
		else{
			root->right=insert(root->right,data);
			}
		}
	}
//traversal
//inorder
void InOrder(struct node* node){
	if(node==NULL)
		return;
	InOrder(node->left);
	printf("%d ",node->data);
	InOrder(node->right);
}
//postorder
void PostOrder(struct node* node){
	if(node==NULL)
		return;
	PostOrder(node->left);
	PostOrder(node->right);
	printf("%d ",node->data);
}
//preorder
void PreOrder(struct node* node){
	if(node==NULL)
		return;
	printf("%d ",node->data);
	PostOrder(node->left);
	PostOrder(node->right);
}
//finding a node
int search(struct node* a,int data){
	struct node* p;
	struct node* c;
	p=a;
	c=a;
	p=c;
	while(c!=NULL){
		p=c;
		if(c->data==data){
			return 1;
			}
		else if(c->data>data){
			c=c->left;
			}
		else{
			c=c->right;
			}
		}
	return 0;
	}
//program to find the minimumvalue node in the bst
struct node* minVal(struct node* root){
	struct node* c=root;
	while(c->left!=NULL){
		c=c->left;
		}
	return c;
	}
//program to delete a node from the bst
struct node* delete(struct node* root,int element){
	if(root==NULL){
		return root;
		}
	if(root->data>element){
		delete(root->left,element);
		}
	else if(root->data<element){
		delete(root->right,element);
		}
	else{
		if(root->left==NULL){
			struct node* temp=root->right;
			free(root);
			return temp;
			}
		else if(root->right==NULL){
			struct node* temp=root->left;
			free(root);
			return temp;
			}
		struct node* temp=minVal(root->right);
		root->data=temp->data;
		root->right=delete(root->right,temp->data);
		}
	return root;
	
	}
void main(){
	int d,number;
	struct node* head=NULL;
	printf("Enter one to enter the elements and enter 0 to stop entering the elements\n");
	while(1){
		int key_press;
		scanf("%d",&key_press);
		if(key_press == 0){
			break;
			}
		else{
			int ele;
			printf("Enter the element value\n");
			scanf("%d",&ele);
			head = insert(head,ele);		
			}
		}
	//deleting a number
	struct node* y;
	int dle_value;
	printf("Enter the element to be deleted\n");
	scanf("%d",&dle_value);
	y=delete(head,dle_value);
	//pre order traversal
	printf("Pre-order printing of the binary serach tree\n");
	PreOrder(head);
	printf("\n");
	//post order traversal
	printf("Post-order printing of the binary serach tree\n");
	PostOrder(head);
	printf("\n");
	//in order traversal
	printf("In-order printing of the binary serach tree\n");
	InOrder(head);
	printf("\n");
	printf("Enter an element to find in the bst\n");
	scanf("%d",&number);
	d=search(head,number);
	if(d==1){
		printf("Element found\n");
		}
	else{
		printf("Element not found\n");
		}
	}
