//bubble sort

#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *arr, int n)
{
	int i,j,t,flag=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				flag=1;
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
		
		if(flag=0)
		break;
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
    bubbleSort(arr,n);
    printArray(arr,n);

}
