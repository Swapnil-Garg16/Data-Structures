//Given an array A[0 ...n – 1], where each element of the array represents a vote in
//the election. Assume that each vote is given as an integer representing the ID of the chosen
//candidate. Give an algorithm for determining who wins the election.

#include<stdio.h>
#include<stdlib.h>

void merge(int l, int m, int r, int *arr)
{
	int n1,n2;
	n1=m-l+1;
	n2=r-m;
	int a[n1],b[n2];
	int i,j,k;
	for(i=0;i<n1;i++)
	a[i]=arr[l+i];
	
	for(j=0;j<n2;j++)
	b[j]=arr[j+m+1];
	
	i=j=0;
	k=l;
	
	while(i<n1 && j<n2)
	{
		if(a[i]<b[j])
		arr[k++]=a[i++];
		else
		arr[k++]=b[j++];
	}
	
	while(i<n1)
	arr[k++]=a[i++];
	
	while(j<n2)
	arr[k++]=b[j++];
}

void mergeSort(int l, int r, int *arr)
{
	if(l<r)
	{
		int m = (l+r)/2;
		mergeSort(l,m,arr);
		mergeSort(m+1,r,arr);
		merge(l,m,r,arr);
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
	int i,n;
	printf("No of votes\n");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	mergeSort(0,n-1,arr);
	int max,count,winner;
	max=count =1;
	winner=arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i-1]==arr[i])
		{
			count++;
			if(count>max)
			{
				max=count;
			 winner=arr[i];
			}
			
		}
		else{
			count=1;
		}
	}
	
	printf("%d ",winner);
}
