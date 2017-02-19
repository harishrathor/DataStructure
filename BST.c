#include<stdio.h>
#include<stdlib.h>

typedef struct BinarySearchTree
{
	int data;
	struct BinarySearchTree *left;
	struct BinarySearchTree *right;
}BST;
BST *create();
BST *insert(BST *,int);
BST *delete(BST *,int );
int search(BST *,int);
void inorderTraversal(BST *);
void postorderTraversal(BST *);
void preorderTraversal(BST *);
void main(){
	int element,success,option;
	BST *root,*temp;
	while(1){
		printf("\nENter an option:\n0:exit 1:insert 2:search 3:delete 4:inroder traversal 5:preorder traversal 6:postorder traversal");
		scanf("%d",&option);
		switch(option){
			case 0:
				exit(0);
			case 1:
				printf("enter an element:");
				scanf("%d",&element);
				if(root==NULL)
					root=create(root,element);
				else
					insert(root,element);
				break;
			case 3:
				printf("\nEmter an element:\n");
				scanf("%d",&element);
			//	root=delete(root,element)
				break;
			case 2:
				printf("\nEmter an element:\n");
				scanf("%d",&element);
				success=search(root,element);
				if(success==-1)
					printf("Not deleted");
				else
					printf("Deleted");
				break;
			case 4:
				inorderTraversal(root);
				break;
			case 5:
				preorderTraversal(root);
				break;
			case 6:
				postorderTraversal(root);
				break;
			default:
				printf("ENter a valid option");
				break;
			
		}
	}
}
BST *create(int value){
	printf("adfa");
	BST *new_node;
	new_node=(BST *)malloc(sizeof(BST));
	new_node->data=value;
	new_node->left=NULL;
	new_node->right=NULL;
	printf("adfaf");
	return new_node;
}
BST *insert(BST *root,int element){
	if(root=NULL)
		return create(element);
	else{
		if(element<root->data){
			root->left=insert(root->left,element);
		}
		else if(element>root->data){
				root->right=insert(root->right,element);
		}
		return root;
	}
}
int search(BST *root,int element){
	if(root==NULL)
		return -1;
	if(root->data==element)
		return 1;
	else if(root->data<element)
		return search(root->left,element);
	else
		return search(root->right,element);
}
void preorderTraversal(BST *root){
	if(root==NULL)
		return;
	printf("\n%d",root->data);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}
void postorderTraversal(BST *root){
	if(root==NULL)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("\n%d",root->data);
}
void inorderTraversal(BST *root)
{
	if(root==NULL)
		return;
	inorderTraversal(root->left);
	printf("\n%d",root->data);
	inorderTraversal(root->right);
}
