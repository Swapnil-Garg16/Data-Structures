//binary search
#include<stdio.h>
#include<stdlib.h>
int binarySearch(int l,int r, int *arr, int no)
{
//	printf("%d %d\n",l,r);
	int mid;
	if(l<=r)
	{
		mid = (l+r)/2;
	//	printf("%d is mid\n",arr[mid]);
		if(arr[mid]==no)
		return mid;
		if(arr[mid]<no)
		binarySearch(mid+1,r,arr,no);
		else
		binarySearch(l,mid-1,arr,no);
	}
	else return -1;
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
	index = binarySearch(0,n-1,arr,no);
	if(index!=-1)
	printf("%d is located at %d index\n",no,index);
	else
	printf("%d not found\n",no);
}

