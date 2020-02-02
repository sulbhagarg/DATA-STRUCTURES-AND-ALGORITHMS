/* queue implementation */
#include<stdio.h>
#define size 20

void insert();
void del();
void display();

int queue[20];
int front = -1, rear = -1;

int main()
{
	int choice;
	do
	{
		printf("Enter 1 for insert element in queue.\nEnter 2 for delete element in queue.\nEnter 3 for displaying elements in queue.\nEnter 4 for exiting the program\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
		
			case 2:
				del();
				break;
			
			case 3:
				display();
				break;
		
			case 4:
				printf("Exiting the program.\n");
				break;
				
			default:
				printf("Invalid!!");
				break;
		}
	}while(choice!=4);
}

void insert()
{
	int ele;
	if((front==rear+1) || (front==0 && rear==size-1))
		printf("Queue Overflow!!\n");
	
	else
	{
		if(front==-1)
			front=0;
		
		printf("Enter the element to add to the queue\n");
		scanf("%d",&ele);
		queue[++rear]=ele;
	}
}

void del()
{
	if(front==-1)
		printf("Queue Underflow!!\n");
		
	else
	{
		if(front==rear)
			front = rear = -1;
		else
			front=front+1;
		//printf("The element deleted in the queue is %d\n",queue[front-1]);
	}
}

void display()
{
	int i;
	if(front==-1)
		printf("Queue is empty\n");
	
	else
	{
		printf("Elements in the queue are:\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d  ",queue[i]);
		}
		printf("\n");
	}
}
