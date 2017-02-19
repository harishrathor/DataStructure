#include<stdio.h>
#include<stdlib.h>

typedef struct NewLinkedList{
	int data;
	struct NewLinkedList *next;
}NODE;
NODE *insertAtHead(NODE *,int);
NODE *createNode(int);
void insertAtTail(NODE *,int);
void insert(NODE *,int,int);
int totalElement=0;
void print(NODE *);
NODE *deleteHead(NODE *);
void deleteTail(NODE *);
void delete(NODE *,int);
NODE *reverseList(NODE *);
void main(){
	int i,element;
	NODE *head;
	head=NULL;
	for(i=1;i<20;i++)
	{
			head=insertAtHead(head,21-i);
			insertAtTail(head,i+20);
			insert(head,i+200,20);
		
	}
	printf("\nPRINTING lIST\n");
	print(head);
	printf("\nGoing to delete two head\n");
	head=deleteHead(head);
	head=deleteHead(head);
	printf("\nGOIND TO DELETE TWO TAILS\n");
	deleteTail(head);deleteTail(head);
	printf("\nLIST AFTER DELETING TWO HEAD AND TWO TAIL\n");
	print(head);
	printf("\nENTER ELEMENT TO DELETE\n");
	scanf("%d",&element);
	delete(head,element);
	printf("\nList after deleting %d.\n",element);
	print(head);
	printf("\nGoing to reverse list\n");
	head=reverseList(head);
	printf("\nReversed list\n");
	print(head);
}
NODE *insertAtHead(NODE *head,int element){
	NODE *new_node;
	new_node=createNode(element);
	if(head==NULL){
		head=new_node;
		return head;
	}
	new_node->next=head;
	head=new_node;
	totalElement++;
	return head;
}
NODE *createNode(int element){
	NODE *new_node;
	new_node=(NODE *)malloc(sizeof(NODE));
	new_node->data=element;
	new_node->next=NULL;
	return new_node;
}
void insert(NODE *head,int new_data,int after_this){
	NODE *temp,*new_node;
	if(head==NULL){
		printf("ROOT IS NULL");
		return;
	}
	temp=head;
	while(temp!=NULL && temp->data!=after_this)
		temp=temp->next;
	if(temp==NULL){
		printf("REFFERED NODE IS NOT PRESENT");
		return;
	}
	new_node=createNode(new_data);
	new_node->next=temp->next;
	temp->next=new_node;
	totalElement++;
}
void insertAtTail(NODE *head,int element){
	NODE *new_node,*temp;
	if(head==NULL){
		printf("ROOT IS NULL");
		return;
	}
	temp=head;
	new_node=createNode(element);
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new_node;
	totalElement++;
}
NODE *deleteHead(NODE *head){
	NODE *temp;
	if(head==NULL){
		printf("ROOT IS NULL");
		return head;
	}
	temp=head;
	head=temp->next;
//	free(temp);
	totalElement--;
	return head;
}
void deleteTail(NODE *head){
	NODE *temp,*ptr;
	if(head==NULL){
		printf("ROOT IS NULL");
		return;
			
	}
	temp=head;
	while(temp!=NULL && temp->next!=NULL){
		ptr=temp;
		temp=temp->next;
	}
	ptr->next=NULL;
	free(temp);
	totalElement--;
}
void delete(NODE *head,int element){
	NODE *temp,*ptr;
	if(head==NULL){
		printf("ROOT IS NULL");
		return;
	}
	temp=head;
	while(temp!=NULL && temp->data!=element){
		ptr=temp;
		temp=temp->next;
	}
	if(temp==NULL){
		printf("\nELEMENT IS NOT PRESENT\n");
		return;
	}
	ptr->next=temp->next;
	free(temp);
	totalElement--;
}
NODE *reverseList(NODE *head){
	NODE *current,*prev,*next;
	if(head==NULL)
		return NULL;
	current=head;
	prev=NULL;
	while(current!=NULL){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
	return head;
}
void print(NODE *head){
	NODE *temp;
	if(head==NULL){
		printf("NO ELEMENTS");
		return;
	}
	temp=head;
	while(temp!=NULL){
		printf("->%d",temp->data);
		temp=temp->next;
	}
	printf("\n\nTOTAL NUMBER OF ELEMENTS ARE %d",totalElement);
}
