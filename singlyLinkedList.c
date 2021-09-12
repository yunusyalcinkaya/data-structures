/* insertion to list from head
 * insertion to list from end
 * insertion to list ascending sort
 * insertion to list descending sort
 * removing from list
 * printing list
 */
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
typedef struct Node node;

node* root = NULL;

void insertEnd(int d)
{
	if(root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root -> data = d;
		root -> next = NULL;
		return;
	}
	node* temp = (node*)malloc(sizeof(node));
	node* iterator = root;
	while(iterator -> next != NULL)
		iterator = iterator -> next;
	//iterator = last node
	iterator -> next = temp;
	temp -> data = d;
	temp -> next = NULL;
}

void insertHead(int d)
{
	if(root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root -> data = d;
		root -> next = NULL;
		return;
	}
	node* temp = (node*)malloc(sizeof(node));
	temp -> data = d;
	temp -> next = root;
	root = temp;
}

void insertAscending(int d)
{
	if(root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root -> data = d;
		root -> next = NULL;
		return;
	}
	if(d < root -> data)//inserting to the  head, change the root
	{
		node* temp = (node*)malloc(sizeof(node));
		temp -> data = d;
		temp -> next = root;
		root = temp;
		return;
	}
	node* temp = (node*)malloc(sizeof(node));
	node* iterator = root;
	/*WARRING 1.0
         * we have to print "iterator -> next -> != NULL" firstly
         * otherwise error(segmentation fault)
         * because if "iterator->next == NULL","iter->next->data" inaccessible
         * so we have to check to "iter -> next ?= NULL"
         */
	while(iterator -> next != NULL && d >= iterator -> next -> data)
		iterator = iterator -> next;
	temp -> next = iterator -> next;
	iterator -> next = temp;
	temp -> data = d;
}

void insertDescending(int d)
{
	if(root == NULL)
        {
                root = (node*)malloc(sizeof(node));
                root -> data = d;
                root -> next = NULL;
                return;
        }
        if(d > root -> data)//insertion to the head, change the root
        {
                node* temp = (node*)malloc(sizeof(node));
                temp -> data = d;
                temp -> next = root;
                root = temp;
                return;
        }
        node* temp = (node*)malloc(sizeof(node));
        node* iterator = root;
	//WARRING 1.0
        while(iterator -> next != NULL && d <= iterator -> next -> data)
                iterator = iterator ->next;
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
		node* temp = root;
		root = root -> next;
		temp -> next = NULL;
		free(temp);
		return;
	}
	node* iterator = root;
	while(iterator -> next != NULL && iterator -> next -> data != d)
		iterator = iterator -> next;
	if(iterator -> next == NULL)
	{
		printf("no data to remove in the list(%d)\n", d);
		return;
	}
	node* temp = iterator -> next;//data to be removed
	iterator -> next = temp -> next;
	temp -> next = NULL;
	free(temp);
}

void printList()
{
	if(root == NULL)
	{
		printf("list is empty, no data to printing\n");
		return;
	}
	node* iterator = root;
	while(iterator != NULL)
	{
		printf("%d ",iterator -> data);
		iterator = iterator -> next;
	}
}

int main()
{
	insertHead(10);
	insertHead(20);
	insertHead(30);
	insertHead(40);
	printList();

	printf("\n");

	insertEnd(50);
	insertEnd(60);
	
	printList();
	printf("\n");
	
	removing(40);
	removing(60);
	removing(10);
	removing(30);
	removing(100);//no data in the list
	removing(20);
	removing(50);

	
	printList();
	printf("\n");

	insertAscending(30);
	insertAscending(20);
	insertAscending(25);
	insertAscending(40);
	
	printList();
	printf("\n");

	removing(20);
	removing(25);
	removing(30);
	removing(40);

	insertDescending(30);
	insertDescending(20);
	insertDescending(25);
	insertDescending(40);
	
	printList();
	printf("\n");

	return 0;
}

