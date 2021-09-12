//create stack with array

#include<stdio.h>
#include<stdlib.h>

#define LIMIT 5

int array[LIMIT];
int top = -1;

void push(int data)
{
	if(top >= LIMIT -1)
	{
		printf("--------------------\n");
		printf("stack is full\n");
		printf("--------------------\n");
	}

	else
	{
		top = top +1;
		array[top] = data;
		printf("--------------------\n");
		printf("inserted data = %d\n",data);
		printf("--------------------\n");
	}
}


void pop()
{
	if(top == -1)
	{
		printf("--------------------\n");
		printf("removing canont be done, stack is empty\n");
		printf("--------------------\n");
	}
	else
	{
		printf("--------------------\n");
		printf("removed data = %d\n", array[top]);
		printf("--------------------\n");
		top--;
	}
}

void peak(){

	if(top == -1)
	{
		printf("--------------------\n");
		printf("no peak data, stack is empty\n");
		printf("--------------------\n");
	}

	else
	{
		printf("--------------------\n");
		printf("peak data = %d\n", array[top]);
		printf("--------------------\n");
	}
}

void printStack()
{
	if(top == -1)
		printf("stack is empty\n");
	else
	{
		printf("----------------------\n");

		for(int i=0; i <=top; i++)
			printf("%d  ", array[i]);

		printf("\n----------------------\n");

	}
}

int main()
{
	int secim, item;
	
	while(1)
	{
		printf("1- inserting data(push)\n");
		printf("2- removing data(pop)\n");
		printf("3- print peak data(peak)\n");
		printf("4- print all stack(printStack)\n");
		printf("5- exit\n");

		scanf("%d", &secim);
		
		switch(secim)
		{
			case 1:
				printf("enter a digit\n");
				scanf("%d", &item);
				push(item);
				break;

			case 2:
				pop();
				break;

			case 3:
				peak();
				break;

			case 4:
				printStack();
				break;

			case 5:
				exit(0);
		}
	}
}



