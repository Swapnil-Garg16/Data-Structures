//nearest smaller element to left
#include<stdio.h>
#include<stdlib.h>
# define N 100
int top=-1;
int stack[N];
int isEmpty()
{
	if(top==-1)
	return 1;
	return 0;
}

int isFull()
{
	if(top==N-1)
	return 1;
	return 0;
}

void push(int data)
{
	if(isFull())
	printf("Stack is full\n");
	else
	stack[++top]=data;
}

void pop()
{
	if(isEmpty())
	printf("Stack is empty\n");
	else
	 stack[top--];
	
}

void printArray(int *arr,int n)
{
	int i=0;
	while(i<n)
	{
		printf("%d ",arr[i]);
		i++;
	}
	printf("\n");
}


int main()
{
	int n,i;
	printf("Enter no of elements\n");
	scanf("%d",&n);
	int arr[n],nextL[n];
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	for(i=0;i<n;i++)
	{
		if(isEmpty())
		nextL[i]=-1;
		else
		{
			if(stack[top]<arr[i])
			nextL[i]=stack[top];
			else
			{
				while(!isEmpty() && stack[top]>=arr[i])
				pop();
				if(!isEmpty())
				nextL[i]=stack[top];
				else
				nextL[i]=-1;
			}
		}
		
		push(arr[i]);
	}
	
	printArray(nextL,n);
	
}
