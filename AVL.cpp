/* AVL TREE */

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
	int height;
}*root,*temp;

void LR()
{
	
}

void RL()
{
	
}

void LL()
{
	
}

void RR()
{
	
}

void insert(int n)
{
	int bf;
	temp=root;
	New = (struct node*)malloc(sizeof(struct node*));
	New->data=n;
	New->left=NULL;
	New->right=NULL;
	New->height=1;
	if(temp==NULL)
		root=New;
	else{
		temp=root;
		while(temp!=NULL)
		{
			if(n<temp->data)
			{
				if(temp->left==NULL)
				{
					temp->left=New;
					break;
				}
				temp=temp->left;
			}
			else
			{
				if(temp->right == NULL)
				{
					temp->right = New;
					break;
				}
				temp=temp->right;
			}
		}
	}
}

void traverse()
{
	
}

int main()
{
	int k,i,j,n;
	do{
	printf("Choose one of the following operations:\n");
	printf("1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
	scanf("%d",&k);
	switch(k)
	{
		case 1:
			printf("Enter the value to be inserted\n");
			scanf("%d",&n);
			insert(n);
	}
}
