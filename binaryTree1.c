//inserting with loop in the tree
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

void insert(int d)
{
        if(root == NULL)
        {
                root = (node*)malloc(sizeof(node));
                root ->data = d;
                root -> left = NULL;
                root -> right = NULL;
        }
        else
        {
                node* temp = (node*)malloc(sizeof(node));
                temp -> right= NULL;
                temp -> left = NULL;
                temp -> data = d;

                node* temp1;

                temp1= root;
                node* parent = NULL;
		//needed the parent because needed node previous temp1 when
		//temp1 = NULL
                while(temp1)
                {
                        parent = temp1;
                        if(d >= temp1 -> data)
                                temp1 = temp1 -> right;
                        else
                                temp1 = temp1 -> left;
                }
                if(temp -> data >= parent -> data)
                        parent -> right = temp;
                if(temp -> data < parent -> data)
                        parent -> left = temp;
        }
}

void preorder(node* root)
{
        if(root == NULL)
	{
		printf("tree is empty\n");
                return;
	}
	printf("%d ",root -> data);
        preorder(root -> left);
        preorder(root -> right);
}

void inorder(node* root)
{
        if(root == NULL)
	{
		printf("tree is empty\n");
                return;
	}
	inorder(root -> left);
        printf("%d ",root -> data);
        inorder(root -> right);
}

void postorder(node* root)
{
        if(root == NULL)
	{
		printf("tree is empty\n");
                return;
	}
        postorder(root -> left);
        postorder(root -> right);
        printf("%d ",root -> data);
}

int main()
{
	insert(20);
	insert(30);
	insert(25);
	insert(35);
	insert(10);
	insert(15);
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");

	return 0;
}
