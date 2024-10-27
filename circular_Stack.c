#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Header node structure
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
    int largest;
    int smallest;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
Queue* initializeQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    queue->size = 0;
    queue->largest = INT_MIN;
    queue->smallest = INT_MAX;
    return queue;
}

// Function to enqueue an element
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        queue->rear->next = queue->front; // Circular link
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
        queue->rear->next = queue->front; // Circular link
    }

    queue->size++;
    if (data > queue->largest) queue->largest = data;
    if (data < queue->smallest) queue->smallest = data;
}

// Function to dequeue an element
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return INT_MIN;
    }

    Node* temp = queue->front;
    int data = temp->data;

    if (queue->front == queue->rear) {
        queue->front = queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
        queue->rear->next = queue->front; // Circular link
    }

    free(temp);
    queue->size--;

    return data;
}

// Function to get the largest value
int getLargestValue(Queue* queue) {
    return queue->largest;
}

// Function to get the smallest value
int getSmallestValue(Queue* queue) {
    return queue->smallest;
}

// Function to display the queue
void displayQueue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = queue->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != queue->front);
    printf("\n");
}

int main() {
    Queue* queue = initializeQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 5);
    enqueue(queue, 30);
    enqueue(queue, 25);

    printf("Queue: ");
    displayQueue(queue);

    printf("Largest value: %d\n", getLargestValue(queue));
    printf("Smallest value: %d\n", getSmallestValue(queue));

    printf("Dequeue: %d\n", dequeue(queue));
    printf("Queue: ");
    displayQueue(queue);

    return 0;
}

