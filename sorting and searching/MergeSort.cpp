//merge sort
#include<stdio.h>
#include<stdlib.h>

void merge(int l,int m,int r, int *arr)
{
	int n1,n2,i,j,k;
	n1=m-l+1;
	n2 = r-m;
	int a[n1],b[n2];
	for(i=0;i<n1;i++)
	a[i]=arr[l+i];
	
	for(j=0;j<n2;j++)
	b[j]=arr[m+1+j];
	
	i=j=0;
	k=l;
	
	while(i<n1 && j<n2)
	{
		if(a[i]<b[j])
		{
			arr[k++]=a[i++];
		}
		else
		arr[k++] = b[j++];
	}
	
	while(i<n1)
	{
		arr[k++]=a[i++];
	}
	
	while(j<n2)
	arr[k++]=b[j++];
}

void mergeSort(int left,int right,int *arr)
{
  if(left<right)
  {
  	int mid = (left+right)/2;
  	 mergeSort(left,mid,arr);
  	 mergeSort(mid+1,right,arr);
  	 merge(left,mid,right,arr);
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
    mergeSort(0,n-1,arr);
    
    printArray(arr,n);

}
