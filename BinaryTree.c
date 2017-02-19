#include<stdio.h>
#include<stdlib.h>

typedef struct BinaryTree{
	int data;
	struct BinaryTree *left;
	struct BinaryTree *right;
}BST;
BST *createNode();
BST *insert(BST *,int);
void InOrder(BST *);
void PostOrder(BST *);
void PreOrder(BST *);
int totalElement=0;
int find(BST *,int);
void main(){
	int i,element;
	BST *root;
	root=NULL;
	root=insert(root,50);
	for(i=4;i<50;i++){
		root=insert(root,i);
		root=insert(root,2*i);
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
