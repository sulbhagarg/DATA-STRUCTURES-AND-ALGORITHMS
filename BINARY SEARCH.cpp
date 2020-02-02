/* Binary Search */
#include<stdio.h>
#include<stdlib.h>
int b_search(int arr[],int l,int r,int x)
{
	if(r>=l)
	{
		int mid=l+(r-l)/2;
		if(arr[mid]==x)
			return mid;
		if(arr[mid]<x)
			return b_search(arr,mid+1,r,x);
		if(arr[mid]>x)
			return b_search(arr,l,mid-1,x);

	}
	return -1;
}

int main()
{
	int a[20];
	int i,n;
	int k,j,temp;
	printf("Enter the length of array:\n");
	scanf("%d",&n);
	printf("Enter The Elements of The array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(k=0;k<n-1;k++)
	{
		for(j=i;j<n;j++)
		{
			if(a[k]>a[j])
			{
				temp=a[k];
				a[k]=a[j];
				a[j]=temp;
			}
		}
	}
	int x;
	printf("Enter The key value to search:\n");
	scanf("%d",&x);
	int loc;
	loc=b_search(a,0,n-1,x);
	if(loc==-1)
		printf("Element is not present in arrray");
	else
		printf("Element is present at this location:\n%d",loc+1);
}
