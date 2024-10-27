#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node{
	int data;
	struct node *next;
}Node;

typedef struct Header{
	Node *front;
	Node *rear;
	int size;
	int largest;
	int smallest;
	
}Header;

Node* CreateNode(int data){
	Node *new =(Node*)malloc(sizeof(Node));
	new->data=data;
	new->next=NULL;
	return new;	
}
Header *Initialize(){
	Header *queue =(Header*)malloc(sizeof(Header));
	queue->front=NULL;
	queue->rear=NULL;
	queue->size=0;
	queue->smallest=INT_MAX;
	queue->largest=INT_MIN;
	return queue;
}
void enqueue(Header *queue,int data)
{
	Node *new= CreateNode(data);
	if(queue->rear==NULL){
		queue->front= new;
		queue->rear=new;
		queue->rear->next=queue->front;
	}else{
		queue->rear->next=new;
		queue->rear=new;
		queue->rear->next=queue->front;
	}
	queue->size++;
	if(data>queue->largest) queue->largest=data;
	if(data<queue->smallest)queue->smallest=data;

}
int dequeue(Header *queue){
	if(queue->front ==NULL){
		printf("Queue is empty\n");
		return;
	}
	Node *temp = queue->front;
	int data = temp->data;
	if(queue->front==queue->rear){
		queue->front =NULL;
		queue->rear = NULL;
		
	}else{
		queue->front = queue->front->next;
		queue->rear->next=queue->front;
	
	}
	free(temp);
	queue->size--;
	return data;
}
int getLargestValue(Header *queue){
	return queue->largest;
}
int getSmallestValue(Header *queue){
	return queue->smallest;
}
void displayQueue(Header *queue){
	if(queue->front==NULL){
		printf("Queue is empty\n");
		return;
	}
	Node *temp = queue->front;
	do {
		printf("%d\n",temp->data);
		temp= temp->next;
	}while(temp->next!=queue->front);
	printf("\n");
}
int main(){
	int choice, data;
	Header *queue  = Initialize();
	do{
		printf("Queue Operations\n");
		printf("1 Enqueue\n2 Dequeue \n3 Get largest value\n4 Get Smallest value\n5 Display Queue \n6 Exit");
		printf("\n Enter a choice \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the data");
				scanf("%d",&data);
				enqueue(queue,data);
				break;
			case 2 :
				printf("Dequeue : %d\n",dequeue(queue));
				break;
			case 3:
				printf("largest value is %d\n",getLargestValue(queue));
				break;
			case 4:
				printf("Smallest value is %d\n",getSmallestValue(queue));
				break;
			case 5:
				printf("Queues are \n");
				displayQueue(queue);
				break;
			case 6:
				printf("Exiting");
				break;
			default:
				printf("Invalid operation ");
				break;
	}
	}while(choice!=6);
		
	return 0;
}
