//QuickSort

#include<stdio.h>

void swap(int *p, int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}

int sort(int a[],int p, int r)
{
    int x=a[r];
    int i=p-1;
    int j;

    for(j=p;j<=r-1;j++)
    {
        if(a[j]<=x)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }

    swap(&a[i+1],&a[r]);

    return (i+1);
}

void quick_sort(int a[], int p, int r)
{
    int q;

    if(p<r)
    {
        q=sort(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
}

int main()
{
    int n,i,j;

    printf("Enter the total no. of integers you want to sort\n");
    scanf("%d",&n);

    int a[n];

    printf("Enter the numbers:\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    quick_sort(a,0,n-1);

    printf("\nThe Sorted Array:\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
