#include<stdio.h>
#include<stdlib.h>

typedef struct CircularQueue
{
	int size;
	int front;
	int rear;
	int counter;
	int *queue;
}CQ;
CQ *q;
void createCircularQ(int);
int  Enqueue(int);
int  Dequeue();
int  Find(int);
void PrintElementsCounter();
void PrintFrontRear();
void main(){
	int size,option=1,element,flag;
	printf("Enter the size of queue");
	scanf("%d",&size);
	createCircularQ(size);
	while(option!=0){
		printf("\n\nEnter a number\n 1:Enqueue\n 2:Dequeue \n 3:Find\n 4:Print Eelement Count \n 5: Print Front Rear \n 0: Exit \n");
		scanf("%d",&option);
		switch(option){
			case 0:
				exit(0);
			case 1:
				printf("Enter an element to Enqueue:");
				scanf("%d",&element);
				flag=Enqueue(element);
				if(flag==0)
					printf("Not Enqueued");
				else
					printf("Enqueued");
				break;
			case 2:
				flag=Dequeue();
				if(flag==-1)
					printf("Element not Dequeued");
				else
					printf("Element is %d ",flag);
				break;
			case 3:
				printf("Enter an element for finding");
				scanf("%d",&element);
				flag=Find(element);
				if(flag==-1)
					printf("Element not found");
				else
					printf("Element found");
				break;
			case 4:
				PrintElementsCounter();
				break;
			case 5:
				PrintFrontRear();
			default:
				break;
		}
	}
}

void createCircularQ(int size){
	q=(CQ *)malloc(sizeof(CQ));
	q->size=size;
	q->front=0;
	q->rear=0;
	q->counter=0;
	q->queue=malloc(q->size*sizeof(int));
}
int Enqueue(int element){
	if(q->counter==q->size)
		return 0;
	q->queue[q->rear]=element;
	q->counter++;
	q->rear++;
	if(q->rear>=(q->size))
		q->rear=0;
	return 1;
}
int Dequeue(){
	int element;
	if(q->counter==0)
		return -1;
	element=q->queue[q->front];
	q->counter--;
	q->front++;
	if(q->front>=(q->size))
		q->front=0;
	return element;
}
int Find(int element){
	int i=q->front,rear=q->rear;
	if(q->counter==0)
		return -1;
	if(q->rear==0)
		rear=q->size;
	if(rear<q->front){
		while(i<q->size){
			if(q->queue[i]==element)
				return 1;
			i++;
		}
		i=0;
		while(i<rear){
			if(q->queue[i]==element)
				return 1;
			i++;		
		}
	}
	else{
		while(i<rear){
			if(q->queue[i]==element)
				return 1;
			i++;
		}
	}
	return -1;
}
void PrintElementsCounter(){
	int i=q->front;
	if(q->counter==0)
		printf("No elements present");
	printf("\nTotal present elemnts are %d \n",q->counter);	
}
void PrintFrontRear(){
	printf("\nFront=%d\n",q->front);
	printf("\nRear=%d",q->rear);
}	

