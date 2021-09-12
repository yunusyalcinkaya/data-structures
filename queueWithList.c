#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
typedef struct Node node;

node* root = NULL;

void enQueue(int d)
{
	if(root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root -> data = d;
		root -> next = NULL;
		return;
	}
	node* temp = (node*)malloc(sizeof(node));
	temp -> next = root;
	temp -> data = d;
	root = temp;
}
void deQueue()
{
	if(root == NULL)
	{
		printf("queue is empty, removing cannot be done\n");
		return;
	}
	//"root -> next ?= NULL" must be checked
	//if "root -> next = NULL", "root -> next -> next"  fault(in while)
	if(root -> next == NULL)
	{
		node* temp = root;
		root = NULL;
		free(temp);
		return;
	}
	node* iterator = root;
	while(iterator -> next -> next != NULL)
		iterator = iterator -> next;
	node* temp = iterator -> next;
	iterator -> next = NULL;
	free(temp);
}

void printQueue()
{
	if(root == NULL)
	{
		printf("queue is empty, no data to printing\n");
		return;
	}
	node* iterator = root;
	while(iterator != NULL)
	{
		printf("%d ", iterator -> data);
		iterator = iterator -> next;
	}
}

int main()
{
	enQueue(10);
	enQueue(20);
	enQueue(30);
	enQueue(40);
	enQueue(50);
	enQueue(60);

	printQueue();
	printf("\n");

	deQueue();
	deQueue();

	printQueue();
	printf("\n");

	deQueue();
	deQueue();
	deQueue();
	deQueue();

	printQueue();
	printf("\n");

	return 0;
}
