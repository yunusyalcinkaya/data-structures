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
	struct Node* prev;
};
typedef struct Node node;

node* root = NULL;

void insertHead(int d)
{
	if(root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root -> next = NULL;
		root -> prev = NULL;
		root -> data = d;
		return;
	}
	node* temp = (node*)malloc(sizeof(node));
	temp -> data = d;
	temp -> next = root;
	temp -> prev = NULL;
	root -> prev = temp;
	root = temp;

}
void insertEnd(int d)
{
	if(root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root -> data = d;
		root -> next = NULL;
		root -> prev = NULL;
		return;
	}
	node* temp = (node*)malloc(sizeof(node));
	node* iterator = root;
	while(iterator -> next != NULL)
		iterator = iterator -> next;
	//iterator = last node
	iterator -> next = temp;
	temp -> prev = iterator;
	temp -> next = NULL;
	temp -> data = d;
}
void insertAscending(int d)
{
	if(root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root -> next = NULL;
		root -> prev = NULL;
		root -> data = d;
		return;
	}
	if(d < root -> data)//inserting to the head, change the root
	{
		node* temp = (node*)malloc(sizeof(node));
		temp -> next = root;
		temp -> prev = NULL;
		root -> prev = temp;
		temp -> data = d;
		root = temp;
		return;
	}
	node* iterator = root;
	node* temp = (node*)malloc(sizeof(node));
	/*WARRING 1.0
         * we have to print "iterator -> next -> != NULL" firstly
         * otherwise error(segmentation fault)
         * because if "iterator->next == NULL","iter->next->data" inaccessible
         * so we have to check to "iter -> next ?= NULL"
         */
	while(iterator -> next != NULL && d >= iterator -> next -> data)
		iterator = iterator -> next;
	if(iterator -> next == NULL)
	{
		iterator -> next = temp;
		temp -> prev = iterator;
		temp -> data = d;
		return;
	}
	temp -> next = iterator -> next;
	temp -> prev = iterator;
	temp -> next -> prev = temp;
	iterator -> next = temp;
	temp -> data = d;

}
void insertDescending(int d)
{
	if(root == NULL)
        {
                root = (node*)malloc(sizeof(node));
                root -> next = NULL;
                root -> prev = NULL;
                root -> data = d;
                return;
        }
        if(d > root -> data)//inserting to head, change the root
        {
                node* temp = (node*)malloc(sizeof(node));
                temp -> next = root;
                temp -> prev = NULL;
                root -> prev = temp;
                temp -> data = d;
                root = temp;
		return;
        }
	node* iterator = root;
        node* temp = (node*)malloc(sizeof(node));
	//WARRING 1.0
        while(iterator -> next != NULL && d <= iterator -> next -> data)
                iterator = iterator -> next;
        if(iterator -> next == NULL)
        {
                iterator -> next = temp;
                temp -> prev = iterator;
                temp -> data = d;
                return;
        }
	temp -> next = iterator -> next;
        temp -> next -> prev = temp;
        temp -> prev = iterator;
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
		free(temp);
		return;
	}
	node* iterator = root;
	while(iterator -> next != NULL && iterator -> next -> data != d)
		iterator = iterator -> next;
	if(iterator -> next == NULL)
	{
		printf("no data to remove int the list(%d)\n", d);
		return;
	}
	node* temp = iterator -> next;//data to be removed
	if(temp -> next == NULL)
	{
		temp -> prev = NULL;
		iterator -> next = NULL;
		free(temp);
		return;
	}
	iterator -> next = temp -> next;
	temp -> next -> prev = iterator;
	temp -> next = NULL;
	temp -> prev = NULL;
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
		printf("%d ", iterator -> data);
		iterator = iterator -> next;
	}
}

int main()
{
	insertHead(10);
	insertHead(20);
	insertHead(30);
	insertHead(40);
	insertHead(50);

	printList();
	printf("\n");

	insertEnd(60);
	insertEnd(70);
	insertEnd(80);

	printList();
	printf("\n");

	removing(50);
	removing(80);
	removing(100);
	removing(10);
	removing(20);
	removing(30);
	removing(40);
	removing(60);
	removing(70);
	
	printList();
	printf("\n");

	insertAscending(20);
	insertAscending(10);
	insertAscending(15);
	insertAscending(30);

	printList();
	printf("\n");
	
	removing(10);
	removing(30);
	removing(15);
	removing(20);

	insertDescending(20);
	insertDescending(10);
	insertDescending(15);
	insertDescending(30);

	printList();
	printf("\n");



	return 0;
}
