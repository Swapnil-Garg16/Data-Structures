//insertion sort

#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *arr, int n)
{
	int i,j,t;
	for(i=1;i<n;i++)
	{
		
		    t=arr[i];
			j=i-1;
			while(arr[j]>t && j>=0)
			{
				arr[j+1]=arr[j];
				j--;
			}
			
			arr[j+1]=t;
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
    insertionSort(arr,n);
    printArray(arr,n);

}
