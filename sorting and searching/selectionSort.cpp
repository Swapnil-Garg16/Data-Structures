//selection sort

#include<stdio.h>
#include<stdlib.h>

void selectionSort(int *arr, int n)
{
	int i,j,min,t;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1; j<n;j++)
		{
			if(arr[j] < arr[min])
			min=j;
		}
		
		t=arr[i];
		arr[i]=arr[min];
		arr[min] = t;
		
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
    selectionSort(arr,n);
    printArray(arr,n);

}
