// sort an array of 0s, 1s, 2s using counting sort

#include<stdio.h>
#include<stdlib.h>

void printArray(int * arr,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
}

void countingSort(int *arr, int n)
{
	int a[3];
	int brr[n];
	int i;
	for(i=0;i<3;i++)
		a[i]=0;
		
		for(i=0;i<n;i++)
		{
			a[arr[i]]++;
		}
		
		for(i=1;i<3;i++)
		a[i]=a[i-1]+a[i];
		
		for(i=n-1;i>=0;i--)
		{
			brr[--a[arr[i]]]= arr[i];
		}
		
		for(i=0;i<n;i++)
		arr[i]=brr[i];
}



int main()
{
	int i,n;
	printf("enter how many numbers\n");
	scanf("%d",&n);
	printf("Enter the numbers\n");
	int arr[n];
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	countingSort(arr,n);
    printArray(arr,n);
}
