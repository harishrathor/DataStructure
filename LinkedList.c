#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList{
	int data;
	struct LinkedList *next;
}NODE;
NODE *HEAD,*temp,*p;
int createLinkedList(int);
int insertAtHead(int);
int insertAtTail(int);
int insert(int,int);
int deleteFirst();
int deleteLast();
int delete(int);
int isExists(int);
void printList();
int find(int);
void main(){
	int option,element,element1,success;
	HEAD=(NODE *)malloc(sizeof(NODE));
	HEAD->data=NULL;
	HEAD->next=NULL;
	while(1){
		printf("\nEnter an option\n0:Exit\n1:Create LinkedList\n2:Insert At Head\n3:Insert at Tail\n4:Insert Elemnt\n5:Delete First Elemnt\n6:Delete Last Elemnt\n7:Delete Element\n8:Element Existence\n9:Print List\n");
		scanf("%d",&option);
	switch(option){
		case 0:
			exit(0);
		case 1:
			printf("\nEnter first element for createing LinkedList:\n");	
			scanf("%d",&element);
			success=insertAtHead(element);
			if(success==-1)
				printf("\nLinked NOT created\n");
			else
				printf("\nLinkedList  created\n");
			break;
		case 2:
			printf("\nEnter an element for inserting at head::\n");	
			scanf("%d",&element);
			success=insertAtHead(element);		
			if(success==-1)
				printf("\nNot inserted at head.\n");
			else
				printf("\nInserted at a head\n");
			break;
		case 3:
			printf("\nEnter element for inserting at tail:\n");	
			scanf("%d",&element);
			success	= insertAtTail(element);
			if(success==-1)
				printf("\nNot inserted at tail\n");
			else
				printf("\nInserted at tail\n");
			break;
		case 4:
			printf("\nEnter element to insert:\n");	
			scanf("%d",&element);
			printf("\nEnter an element after which you want to insert:\n");	
			scanf("%d",&element1);
			success=insert(element,element1);
			if(success==-1)
				printf("\nElement not  inserted\n");
			else
				printf("\nElement Insered\n");
			break;
		case 5:
			success=deleteFirst();
			if(success==-1)
				printf("\nFirst Element not deleted\n");
			else
				printf("\nFirst Element deleted\n");
			break;
		case 6:
			success=deleteLast();
			if(success==-1)
				printf("\nLast element not deleted\n");
			else
				printf("\nLast Element deleted\n");
			break;
		case 7:
			printf("\nEnter element which you want to delete:\n");	
			scanf("%d",&element);
			success=delete(element);
			if(success==-1)
				printf("\nElement not deleted\n");
			else
				printf("\nElement deleted\n");
			break;
		case 8:
			printf("\nEnter element to find:\n");
			scanf("%d",&element);
			success=find(element);
			if(success==-1)
				printf("Element not found");
			else
				printf("Element found");
			break;
		case 9:
			printList();
			break;
		default:
			break;
	}
	}

}

int createLinkedList(int firstElement){
	temp=(NODE *)malloc(sizeof(NODE));
	if(HEAD!=NULL){
		printf("List already exists");
		return -1;
	}
	printf("Temp value for first element %d",temp->data);
	HEAD=temp;
	free(temp);
	return 1;
}
int insertAtHead(int element){
	temp=(NODE *)malloc(sizeof(NODE));
	temp->data=element;
//	printf("temp value %d",temp->data);
	if(HEAD==NULL)
		return createLinkedList(element);
	if(temp==NULL)
		return -1;
	temp->next=HEAD->next;
	HEAD->next=temp;
	return 1;
}
int insertAtTail(int element){
	NODE *new_node;
	new_node=(NODE *)malloc(sizeof(NODE));
	new_node->data=element;
	temp=HEAD;
	if(HEAD==NULL)
		return createLinkedList(element);
	while(temp->next!=NULL){
		temp=temp->next;
	}
	new_node->next=temp->next;
	temp->next=new_node;
	return 1;
}
int insert(int new_node_data,int after_this){
	NODE *new_node;
	new_node=(NODE *)malloc(sizeof(NODE));
	new_node->data=new_node_data;
	temp=HEAD;
	if(HEAD==NULL)
		return -1;
	printf("after number %d",after_this);
	while(temp!=NULL && temp->data!=after_this){
		printf("Current element is %d ",temp->data);
		temp=temp->next;
	}
	if(temp==NULL)
		return -1;
	new_node->next=temp->next;
	temp->next=new_node;
	return 1;
}
int deleteFirst(){
	if(HEAD==NULL)
		return -1;
	
	temp=HEAD->next;
	HEAD->next=temp->next;
	free(temp);
	return 1;
}
int deleteLast(){
	temp=HEAD;
	if(HEAD==NULL)
		return -1;
	
	while(temp->next!=NULL)
	{
		p=temp;
		temp=temp->next;
	}
	p->next=NULL;
	free(temp);
	return 1;
}
int delete(int element){
	temp=HEAD;
	if(HEAD==NULL)
		return -1;
	while(temp->next!=NULL && temp->data!=element){
		p=temp;
		temp=temp->next;
	}
	if(temp==NULL)
		return -1;
	p->next=temp->next;
	free(temp);
	return 1;
}
int find(int element){
	temp=HEAD;
	if(HEAD==NULL)
		return -1;
	while(temp!=NULL && temp->data!=element){
			temp=temp->next;
		}
	if(temp==NULL)
		return -1;
	return 1;
}
void printList(){
	temp=HEAD->next;
	if(HEAD==NULL)
		printf("List does not exist");
	else
	{	
		while(temp!=NULL){
			printf("\n%d",temp->data);
			temp=temp->next;
		}
	}
}

