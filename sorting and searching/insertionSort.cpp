//insertion sort

#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *arr, int n)
{
	int i,j,t;
	for(i=1;i<n;i++)
	{
		if(arr[i]<arr[i-1])
		{
		
			j=i;
			while((arr[j]<arr[j-1]) && j>0)
			{
				t = arr[j-1];
				arr[j-1] = arr[j];
				arr[j]=t;
				j--;
				
							}
		}
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
