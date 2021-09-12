//create stack with linked list
#include<stdio.h>
#include<stdlib.h>

struct Node {

	int data;
	struct Node* link;
};
typedef struct Node node;

node* top = NULL;// top = root

//inserting to head
void push(int d){
	if(top == NULL)//stack is empty
	{
		top = (node*)malloc(sizeof(node));
		top -> data = d;
		top -> link = NULL;
	}
	else
	{
		node* temp = (node*)malloc(sizeof(node));
		temp -> data = d;
		temp -> link = top;
		top = temp;
	}//inserting is done to the head, so the top(root) changed
}
		


void pop() {
	if(top== NULL)
		printf("removing cannot be done, stack is empty\n");
	else
	{
		node* temp = top;
		top = temp -> link;
		printf("removed data: %d\n",temp -> data);
		free(temp);
	}//removing is done to the head, so the top changed
}

void printStack(){

	if(top == NULL)
		printf("no data to print, stack is empty\n");

	else
	{
		node* temp = top;

		while(temp != NULL)
		{
			printf("%d\n",temp->data);
			temp = temp -> link;
		}
	}
}

int main(){
	pop();
	push(10);
	push(20);
	push(30);
	printStack();
	pop();
	printStack();
	pop();
	pop();
	pop();

	return 0;
}
