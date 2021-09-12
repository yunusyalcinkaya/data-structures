//create queue with array

#include<stdio.h>
#define MAX 5

void adjustQueue();
int queue[MAX];
int head = -1, end = -1;
//keep head of queue and end of queue

//inserting data in the queue
void enQueue()
{
	int value;
	//data to inserting in the queue
	if(MAX -1 == end)
		adjustQueue();


	if(MAX - 1 == end)
	{
		printf("the queue is full, inserting cannot be done\n");
		return;
	}
	if(head == -1)
		head = 0;		
	printf("enter a data(digit): \n");
	scanf("%d",&value);
	queue[++end] = value;
}

//removing data from the queue
void deQueue()
{
	if(head == -1 || head > end)
	{
		printf("queue is empty, removing cannot be done\n");
		return;
	}
	printf("data to the removed = %d\n",queue[head++]);
}

//the process of moving data to the first indexes that are empty
//because the data is deleted from the queue from the front
void adjustQueue()
{
	int j = 0;
	for(int i = head; i <= end; i++)
		queue[j++] = queue[i];
	
	end = end - head;
	head = 0;
}

//printing the queue
void printQueue()
{
	if(head == -1 || head > end)
	{
		printf("the queue is empty, no data to printing\n");
		return;
	}
	printf("data of the queue:\n");
	
	for(int i = head; i <= end; i++)
		printf("%d\t",queue[i]);
	printf("\n");
}

int main()
{
	enQueue();
	enQueue();
	enQueue();
	enQueue();
	enQueue();
	enQueue();
	printQueue();
	deQueue();
	enQueue();
	printQueue();
	




	return 0;
}
