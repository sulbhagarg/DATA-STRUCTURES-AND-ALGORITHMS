/* Merge Sort */
void merge(int arr[], int l, int m, int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
		L[i]=arr[l+i];
	for(i=0;i<n2;i++)
		R[i]=arr[m+1+j];
	i=0;
	j=0;
	k=1;
	while(i<n1 && j<n2)
	{
		if(L[i]<R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if(l<r)
	{
		int m=l+(l-r)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r-1);
		merge(arr,l,m,r);
	}
}

void display(int arr[], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d  ",arr[i]);
}

int main()
{
	int n,i;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	mergeSort(arr,0,n-1);
	display(arr,n);
}
