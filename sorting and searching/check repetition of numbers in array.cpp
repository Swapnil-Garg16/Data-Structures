//Given an array A[0...n– 1] of n numbers containing the repetition of some number.
//Give an algorithm for checking whether there are repeated elements or not. Assume that
//we are not allowed to use additional space (i.e., we can use a few temporary variables,
//O(1) storage).

// using merge sort - O(nlogn)

#include<stdio.h>
#include<stdlib.h>

void merge(int *arr, int l,int m, int r)
{
	int n1,n2;
	n1= m-l+1;
	n2 = r-m;
	int a[n1],b[n2];
	int i,j,k;
	for(i=0;i<n1;i++)
	a[i]=arr[i+l];
	
	for(j=0;j<n2;j++)
	{
		b[j]=arr[j+m+1];
	}
	i=j=0;
	k=l;
	
	while(i<n1 && j<n2)
	{
		if(a[i]<=b[j])
		arr[k++]=a[i++];
		else
		arr[k++]=b[j++];
	}
	
	while(i<n1)
	arr[k++]=a[i++];
	
	while(j<n2)
	arr[k++]=b[j++];
	
	
}

void mergeSort(int *arr, int l,int r)
{
	if(l<r)
	{
		int m = (l+r)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
int main()
{
	int i,n,t=0;
	printf("how many nos\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the numbers\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	mergeSort(arr,0,n-1);
	
	for(i=0;i<n-1;i++)
	{
		if(arr[i]==arr[i+1])
		{
			printf("Yes\n");
			t=1;
			break;
		}
	}
	
	if(t==0)
	printf("NO\n");
}
