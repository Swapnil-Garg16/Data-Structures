// Linear Search
#include<stdio.h>
#include<stdlib.h>

int search(int no,int *arr, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==no)
		return i;
	}
	
	return -1;
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
	printf("Enter the no you want to search\n");
	scanf("%d",&no);
	index = search(no,arr,n);
	if(index!=-1)
	printf("%d is located at %d index\n",no,index);
	else
	printf("%d not found\n",no);
}
