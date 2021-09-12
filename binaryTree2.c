//recursive inserting in tree
//preorder notation
//postorder notation
//inorder notation

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* right;
	struct Node* left;
};
typedef struct Node node;
node* root = NULL;

void preorder(node* root)
{
	if(root == NULL)
		return;
	printf("%d ",root -> data);
	preorder(root -> left);
	preorder(root -> right);
}

void inorder(node* root)
{
	if(root == NULL)
		return;
	inorder(root -> left);
	printf("%d ",root -> data);
	inorder(root -> right);
}

void postorder(node* root)
{
	if(root == NULL)
		return;
	postorder(root -> left);
	postorder(root -> right);
	printf("%d ",root -> data);
}

node* insert(node* root,int data)
{ 
	if(root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root -> data = data;
		root -> right = NULL;
		root -> left = NULL;
		return root;
	}
	else if(data <= root -> data)
		root -> left = insert(root -> left, data);
	else
		root -> right = insert(root -> right,data);

	return root;
}

int main()
{
	node* root = NULL;
	root = insert(root,20);
	root = insert(root,30);
	root = insert(root,25);
	root = insert(root,35);
	root = insert(root,10);
	root = insert(root,15);

	printf("preorder: \n");
	preorder(root);
	printf("\n");


	printf("inorder: \n");
	inorder(root);
	printf("\n");

	printf("postorder:\n");
	postorder(root);
	printf("\n");

	return 0;
}
