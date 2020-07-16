//quickSort

#include<stdio.h>
#include<stdlib.h>

int partition(int l,int r, int *arr)
{
	int p = arr[r];
	int pInd = l;
	int i,t;
	for(i=l;i<r;i++)
	{
		if(arr[i]<=p)
		{
			t=arr[pInd];
			arr[pInd]=arr[i];
			arr[i]=t;
			pInd++;
		}
	}
	
	t=p;
	arr[r]=arr[pInd];
	arr[pInd]=t;
	
	return pInd;
}

void quickSort(int l,int r,int *arr)
{
	if(l<r)
	{
		int pivot = partition(l,r,arr);
		quickSort(l,pivot-1,arr);
		quickSort(pivot+1,r,arr);
	}
}

void printArray(int *arr, int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
}

int main()
{
	int n,i,index,no;
	int *arr;
	printf("Enter the no of elements\n");
	scanf("%d",&n);
	arr = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
    quickSort(0,n-1,arr);
    printArray(arr,n);

}
