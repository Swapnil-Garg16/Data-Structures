/* There are two sorted arrays A and B. The first one is of size m + n containing
only m elements. Another one is of size n and contains n elements. Merge these two arrays
into the first array of size m + n such that the output is sorted  */


#include<stdio.h>
#include<stdlib.h>
void merge(int *arr, int *brr, int m, int n)
{
	int i,j,k;
	i=m-1,j=n-1,k=m+n-1;
	while(i>=0 && j>=0)
	{
		if(arr[i]>=brr[j])
		arr[k--]=arr[i--];
		else
		arr[k--]=brr[j--];
	}
	
	while(j>=0)
	arr[k--]=brr[j--];
}

void print(int *arr, int a)
{
	int i;
	for(i=0;i<a;i++)
	printf("%d ",arr[i]);
}

int main()
{
	int m,n,i;
	printf("Enter m and n\n");
	scanf("%d %d",&m,&n);
	int arr[m+n],brr[n];
	printf("Enter m numbers in first array\n");
	for(i=0;i<m;i++)
	scanf("%d",&arr[i]);
	printf("Enter n numbers in 2nd array\n");
	for(i=0;i<n;i++)
	scanf("%d",&brr[i]);
	merge(arr,brr,m,n);
	print(arr,m+n);
	
}
