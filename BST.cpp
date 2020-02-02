/* Binary Search Tree */
#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *left;
	struct node *right;
	int info;
}*ROOT,*temp,*temp1,*pre,*ptr,*parent,*New;

void insert_node(int n)
{
	temp = ROOT;
	New = (struct node*)malloc(sizeof(struct node*));
	New->info=n;
	New->left=NULL;
	New->right=NULL;
	if(temp==NULL)
		ROOT=New;
	else
		temp=ROOT;
		while(temp!=NULL)
		{
			if(n<temp->info)
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

void inorder_traversal(struct node *T)
{
	if(T==NULL)
	{
		printf("Empty");
		return;
	}
	if(T->left!=NULL)
		inorder_traversal(T->left);
	printf("->%d ",T->info);
	if(T->right!=NULL)
		inorder_traversal(T->right);
}

void preorder_traversal(struct node *T)
{
	if(T==NULL)
	{
		printf("Empty");
		return;
	}
	printf("->%d ",T->info);
	if(T->left!=NULL)
		preorder_traversal(T->left);
	if(T->right!=NULL)
		preorder_traversal(T->right);
}

void postorder_traversal(struct node *T)
{
	if(T==NULL)
	{
		printf("Empty");
		return;
	}
	if(T->left!=NULL)
		postorder_traversal(T->left);
	if(T->right!=NULL)
		postorder_traversal(T->right);
	printf("->%d ",T->info);
}

void delete_node(int n)
{
	if(ROOT==NULL)
		printf("Empty tree.\n");
	else if(ROOT->left==NULL && ROOT->right==NULL)
	{
		ROOT=NULL;
		return;
	}
	else{
		parent=ROOT;
		ptr=ROOT;
		int flag=0;
		while(ptr->info!=n)
		{
			if(n < ptr->info){
				parent=ptr;
				ptr=ptr->left;
			}
			else{
				parent=ptr;
				ptr=ptr->right;
			}
		}
		int del_choice;
		if(ptr->left==NULL && ptr->right==NULL)
		{
			if(parent->left==ptr)
				parent->left=NULL;
			else
				parent->right=NULL;
		}
		else if(ptr->left!=NULL && ptr->right!=NULL)
		{
			
		}
	}	
}

int main()
{
	int k,n,k1;
	do{
	printf("Choose one of the following operations:\n");
	printf("1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
	scanf("%d",&k);
	switch(k)
	{
		case 1:
			printf("Enter the value to be inserted:\n");
			scanf("%d",&n);
			insert_node(n);
			break;
		
		case 2:
			printf("Enter the value to be deleted:\n");
			scanf("%d",&n);
			//delete_node(n);
			break;
			
		case 3:
			printf("Choose one of the following traversing options:\n");
			printf("1. In-Order Traversal\n2. Pre-Order Traversal\n3. Post-Order Traversal\n");
			scanf("%d",&k1);
			switch(k1)
			{
				case 1:
					printf("\n");
					inorder_traversal(ROOT);
					break;
				
				case 2:
					printf("\n");
					preorder_traversal(ROOT);
					break;
				
				case 3:
					printf("\n");
					postorder_traversal(ROOT);
					break;
					
				default:
                	printf("Enter Valid Input!Can't you read there are only 3 options given?");
                	break;
			}
		
		case 4:
			exit(0);
			break;
		
		default:
            printf("Enter Valid Input!Can't you read there are only 3 options given?");
            break;
	}
	}while(1);
}
