#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

typedef struct Node node;
node* root = NULL;

void insertUnsorted(int d)
{
	if(root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root -> next = root;
		root -> data = d;
		return;
	}
	node* iterator = root;
	while(iterator -> next != root)
		iterator = iterator -> next;
	//iterator = last node
	node* temp = (node*)malloc(sizeof(node));
	iterator -> next = temp;
	temp -> next = root;
	temp -> data = d;
}
void insertAscending(int d)
{
	if(root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root -> next = root;
		root -> data = d;
		return;
	}
	if(d < root -> data)//insert from head, change the root
	{
		node* iterator = root;
		while(iterator -> next != root)
			iterator = iterator -> next;
		node* temp = (node*)malloc(sizeof(node));
		iterator -> next = temp;
		temp -> next = root;
		temp -> data = d;
		root = temp;
		return;
	}
	node* iterator = root;
	while(iterator -> next != root && d >= iterator -> next -> data)
		iterator = iterator -> next;
	node* temp = (node*)malloc(sizeof(node));
	temp -> next = iterator -> next;
	iterator -> next = temp;
	temp -> data = d;
}
void insertDescending(int d)
{
	if(root == NULL)
        {
                root = (node*)malloc(sizeof(node));
                root -> next = root;
                root -> data = d;
                return;
        }
	if(d > root -> data)//insert from head, change the root
        {
                node* iterator = root;
                while(iterator -> next != root)
                        iterator = iterator -> next;
                node* temp = (node*)malloc(sizeof(node));
                iterator -> next = temp;
                temp -> next = root;
                temp -> data = d;
                root = temp;
                return;
        }
        node* iterator = root;
        while(iterator -> next != root && d <= iterator -> next -> data)
                iterator = iterator -> next;
        node* temp = (node*)malloc(sizeof(node));
        temp -> next = iterator -> next;
        iterator -> next = temp;
        temp -> data = d;

}
void removing(int d)
{
	if(root == NULL)
	{
		printf("list is empty, removing cannot be done\n");
		return;
	}
	if(d == root -> data)
	{
		if(root -> next == root)
		{
			node* temp = root;
			root = NULL;
			free(temp);
			printf("removing all data in the list\n");
			return;
		}
		node* iterator = root;
		while(iterator -> next != root)
			iterator = iterator -> next;
		iterator -> next = root -> next;
		node* temp = root;
		root = iterator -> next;
		free(temp);
		return;
	}
	node* iterator = root;
	while(iterator -> next != root && iterator -> next -> data !=d)
		iterator = iterator -> next;
	if(iterator -> next == root)
	{
		printf("removing cannot be done, no data in the list(%d)\n",d);
		return;
	}
	node* temp = iterator -> next;
	iterator -> next = temp -> next;
	free(temp);

}
void printList()
{
	if(root == NULL)
	{
		printf("list is empty, no data to print\n");
		return;
	}
	node* iterator = root;
	printf("%d ",root -> data);
	iterator = iterator -> next;
	while(iterator != root)
	{
		printf("%d ",iterator -> data);
		iterator = iterator -> next;
	}
}

int main()
{
	insertUnsorted(20);
	insertUnsorted(15);
	insertUnsorted(30);
	insertUnsorted(40);
	insertUnsorted(50);

	printList();
	printf("\n");

	removing(20);
	removing(15);
	removing(50);
	removing(30);
	removing(40);

	printList();

	insertAscending(20);
	insertAscending(15);
	insertAscending(30);
	insertAscending(40);

	printList();
	printf("\n");
	
	removing(20);
	removing(15);
	removing(30);
	removing(40);

	insertDescending(20);
	insertDescending(15);
	insertDescending(30);
	insertDescending(40);

	printList();
	printf("\n");

	return 0;
}
