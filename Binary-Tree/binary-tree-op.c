#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
struct Queue
{
    int front, rear;
    int size;
    struct node* *array;
};
struct node{
	int data;
	struct node* left;
	struct node* right;
	};
struct node* newNode(int element){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=element;
	temp->left=NULL;
	temp->right=NULL;
	return(temp);
	}
struct Queue* createQueue(int size)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof( struct Queue ));
 
    queue->front = queue->rear = -1;
    queue->size = size;
 
    queue->array = (struct node**) malloc(queue->size * sizeof( struct node* ));
 
    int i;
    for (i = 0; i < size; ++i)
        queue->array[i] = NULL;
 
    return queue;
}
int isEmpty(struct Queue* queue)
{
    return queue->front == -1;
}
 
int isFull(struct Queue* queue)
{  return queue->rear == queue->size - 1; }
 
int hasOnlyOneItem(struct Queue* queue)
{  return queue->front == queue->rear;  }
 
void Enqueue(struct node *root, struct Queue* queue)
{
    if (isFull(queue))
        return;
 
    queue->array[++queue->rear] = root;
 
    if (isEmpty(queue))
        ++queue->front;
}
struct node* Dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return NULL;
 
    struct node* temp = queue->array[queue->front];
 
    if (hasOnlyOneItem(queue))
        queue->front = queue->rear = -1;
    else
        ++queue->front;
 
    return temp;
}
 
struct node* getFront(struct Queue* queue)
{  return queue->array[queue->front]; }
int hasBothChild(struct node* temp)
{
    return temp && temp->left && temp->right;
}
void insert(struct node **root, int data, struct Queue* queue)
{
    struct node *temp = newNode(data);
    if (!*root)
        *root = temp;
    else
    {
     struct node* front = getFront(queue);
        if (!front->left)
            front->left = temp;
        else if (!front->right)
            front->right = temp;   
        if (hasBothChild(front))
            Dequeue(queue);
    }
    Enqueue(temp, queue);
}
 
void InOrder(struct node* node){
	if(node==NULL)
		return;
	InOrder(node->left);
	printf("%d ",node->data);
	InOrder(node->right);
}
void PostOrder(struct node* node){
	if(node==NULL)
		return;
	PostOrder(node->left);
	PostOrder(node->right);
	printf("%d ",node->data);
}
void levelOrder(struct node* root)
{
    struct Queue* queue = createQueue(SIZE);
 
    Enqueue(root, queue);
 
    while (!isEmpty(queue))
    {
        struct node* temp = Dequeue(queue);
 
        printf("%d ", temp->data);
 
        if (temp->left)
            Enqueue(temp->left, queue);
 
        if (temp->right)
            Enqueue(temp->right, queue);
    }
}
void Find(struct node* root,int value)
{
    struct Queue* queue = createQueue(SIZE);
 
    Enqueue(root, queue);
 
    while (!isEmpty(queue))
    {
        struct node* temp = Dequeue(queue);
 
        if(value==temp->data){
        printf("Founded value");
        break;}
 
        if (temp->left)
            Enqueue(temp->left, queue);
 
        if (temp->right)
            Enqueue(temp->right, queue);
    }
}
void main(){
    struct node* root = NULL;
    struct Queue* queue = createQueue(SIZE);
    int i;
 
    for(i = 1; i <= 12; ++i)
        insert(&root, i, queue);
    printf("Printing in level order\n");
    levelOrder(root);
    printf("\nPrinting in Post Order traversal\n");
    PostOrder(root);
    printf("\nPrinting in In Order traversal\n");
    InOrder(root);
    printf("\n");
    Find(root,5);
}
