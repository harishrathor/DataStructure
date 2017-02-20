#include<stdio.h>
#include<stdlib.h>

typedef struct BinaryTree{
	int data;
	struct BinaryTree *left;
	struct BinaryTree *right;
}BST;
typedef struct Queue{
	struct BinaryTree *node;
	struct Queue *next;
}Q;

Q *front;
Q *rear;
void Enqueue(BST *);
BST *Dequeue();
int IsEmpty();
BST *Front();
Q *createQNode();
Q *createQ();

BST *createNode(int);
BST *insert(BST *,int);
void InOrder(BST *);
void PostOrder(BST *);
void PreOrder(BST *);
int totalElement=0;
int find(BST *,int);
void LevelOrder(BST *);
BST *FindMin(BST *);
BST *FindMax(BST *);
void FindHeight(BST *);
void FindLevelSum(BST *);
BST *delete(BST *,int);

void main(){
	int i,element;
	BST *root;
	front=NULL;
	rear=NULL;
	root=NULL;
	root=insert(root,50);
	for(i=60;i<80;i++){
		
		root=insert(root,2*i);
		root=insert(root,i);
		root=insert(root,i/2);
	}
	printf("\ntotal elements are %d\n",totalElement);
	InOrder(root);
	printf("\nPreorder\n");
	PreOrder(root);
	printf("\nPostorder\n");
	PostOrder(root);
	printf("\nEnter element to find\n");
	scanf("%d",&element);
	i=find(root,element);
	if(i==-1)
		printf("\nElement %d is not present in the tree.\n",element);
	else
		printf("Element %d exists in the tree.",element);
	printf("\nPrinting from LevelOrder:\n");
	LevelOrder(root);
	FindLevelSum(root);
	FindMin(root);
	FindMax(root);
	FindHeight(root);
	LevelOrder(root);
	printf("\nEnter element to delete\n");
	scanf("%d",&element);
	root=delete(root,element);
	LevelOrder(root);
}
BST *createNode(int element){
	BST *new_node;
	new_node=(BST *)malloc(sizeof(BST));
	new_node->data=element;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}
BST *insert(BST *root,int element){
	if(root==NULL)
		return createNode(element);
	else if(root->data>element)
		root->left=insert(root->left,element);
	else if(root->data<element)
		root->right=insert(root->right,element);
	totalElement++;
	return root;
}
void InOrder(BST *root){
	if(root!=NULL){
		InOrder(root->left);
		printf("\t%d",root->data);
		InOrder(root->right);
	}
}
void PreOrder(BST *root){
	if(root!=NULL){
	//	InOrder(root->left);
		printf("\t%d",root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
void PostOrder(BST *root){
	if(root!=NULL){
		PostOrder(root->left);
		PostOrder(root->right);
		printf("\t%d",root->data);
	//	InOrder(root->right);
	}
}

void LevelOrder(BST *root){
	BST *temp;
	if(root==NULL)
		return;
	Enqueue(root);
	while(!IsEmpty()){
		temp=Dequeue();
		if(temp){
			printf("   %d",temp->data);
			if(temp->left!=NULL){
				Enqueue(temp->left);			}
			if(temp->right!=NULL){
				Enqueue(temp->right);
			}
		}
	}
}
void FindHeight(BST *root){
	BST *temp;
	int level=0,nodesInCurrentLeve=0,nodesInNextLevel=0;
	if(root==NULL)
		return;
	Enqueue(root);
	nodesInCurrentLeve++;
	while(!IsEmpty()){
		temp=Dequeue();
		nodesInCurrentLeve--;
		if(temp){
			printf("   %d",temp->data);
			if(temp->left!=NULL){
				Enqueue(temp->left);
				nodesInNextLevel++;
			}
			if(temp->right!=NULL){
				Enqueue(temp->right);
				nodesInNextLevel++;
			}
		}
		if(nodesInCurrentLeve==0){
			printf("\n");
			nodesInCurrentLeve=nodesInNextLevel;
			nodesInNextLevel=0;
			level++;

		}
	}
	printf("\nTotal height is %d",level);
}
int find(BST *root,int element){
	if(root==NULL)
		return -1;
	else if(root->data==element)
		return 1;
	else if(element<root->data)
		return find(root->left,element);
	else
		return find(root->right,element);
}
Q *createQNode(BST *element){
	Q *new_node;
	new_node=(Q *)malloc(sizeof(Q));
	new_node->node=element;
	new_node->next=NULL;
	return new_node;
}
void Enqueue(BST *element){
	Q *new_node,*temp;
	new_node=createQNode(element);
	if(front==NULL){
		front=new_node;
		rear=new_node;
		return;
	}
	temp=rear;
	temp->next=new_node;
}
BST * Dequeue(){
	Q *temp;
	if(front==NULL){
		return NULL;
	}
	temp=front;
	front=temp->next;
	return temp->node;
}
int IsEmpty(){
	return front==NULL;
}
Q *createQ(){
	return front;
}
BST *Front(){
	Q *temp;
	temp=front;
	return temp->node;
}

BST *FindMin(BST *root){
	BST *temp,*min;
	if(root==NULL)
		return root;
	Enqueue(root);
	min=createNode(32556);
	while(!IsEmpty()){
		temp=Dequeue();
		if(temp){
			//printf("   %d",temp->data);
			if(temp->data<min->data)
				min=temp;
			if(temp->left!=NULL){
				Enqueue(temp->left);			}
			if(temp->right!=NULL){
				Enqueue(temp->right);
			}
		}
	}
	printf("\nMin is %d\n",min->data);
	return min;
}

BST *FindMax(BST *root){
	BST *temp,*max;
	if(root==NULL)
		return root;
	Enqueue(root);
	max=createNode(-32565);
	while(!IsEmpty()){
		temp=Dequeue();
		if(temp){
			//printf("   %d",temp->data);
			if(temp->data>max->data)
				max=temp;
			if(temp->left!=NULL){
				Enqueue(temp->left);			}
			if(temp->right!=NULL){
				Enqueue(temp->right);
			}
		}
	}
	printf("\nMax is %d\n",max->data);
	return max;
}
void FindLevelSum(BST *root){
	BST *temp;
	int level=0,nodesInCurrentLeve=0,nodesInNextLevel=0,sum=0;
	if(root==NULL)
		return;
	Enqueue(root);
	nodesInCurrentLeve++;
	while(!IsEmpty()){
		temp=Dequeue();
		nodesInCurrentLeve--;
		if(temp){
			//printf("   %d",temp->data);
			sum+=temp->data;
			if(temp->left!=NULL){
				Enqueue(temp->left);
				nodesInNextLevel++;
			}
			if(temp->right!=NULL){
				Enqueue(temp->right);
				nodesInNextLevel++;
			}
		}
		if(nodesInCurrentLeve==0){
			printf("\nLevel %d sum is %d\n",level,sum);
			sum=0;
			nodesInCurrentLeve=nodesInNextLevel;
			nodesInNextLevel=0;
			level++;

		}
	}
	printf("\nTotal NUMBER of LEvels are %d",level);
}
BST *delete(BST *root,int element){
	BST *temp;
	if(root==NULL)
		return root;
	else if(element<root->data){
		root->left=delete(root->left,element);
	}
	else if(element>root->data){
		root->right=delete(root->right,element);
	}else{

		//If no child
		if(root->left==NULL && root->right==NULL){
			free(root);
			root=NULL;
			return root;
		}
		//if one child
		else if(root->left==NULL){
			temp=root;
			root=root->right;
			free(temp);
			return root;
		}
		else if(root->right==NULL){
			temp=root;
			root=root->left;
			free(temp);
			return root;
		}
		//case 2 child
		else{
			temp=FindMin(root->right);
			root->data=temp->data;
			root->right=delete(root->right,temp->data);
		}
	}
	return root;
}