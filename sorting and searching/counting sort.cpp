//counting sort
#include<stdio.h>
#include<stdlib.h>

int getK(int *arr,int n)
{
	int i,max;
	max=arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]>max)
		max=arr[i];
	}
	
	return max;
}
void countSort(int *arr,int n)
{
	int k = getK(arr,n);
	int brr[k+1];
	int crr[n];
	int i;
	for(i=0;i<n;i++)
	{
		brr[i]=0;
	}
	
	for(i=0;i<n;i++)
	{
		brr[arr[i]]++;
	}
	
	for(i=1;i<=k;i++)
	{
		brr[i]=brr[i-1]+brr[i];
	}
	
	for(i=n-1;i>=0;i--)
	{
		crr[--brr[arr[i]]] = arr[i];
	}
	
	for(i=0;i<n;i++)
	{
		arr[i]=crr[i];
	}
	
	
}

void printArray(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
}

int main()
{
	int n,i;
	printf("no of inputs\n");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	countSort(arr,n);
	printArray(arr,n);
}
