//stock span problem - O(n) solution by stacks
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

void printSpanArray(int *arr,int n)
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
	printf("enter no. of days\n");
	scanf("%d",&n);
	int prices[n],span[n];
	printf("Enter prince for %d no of days\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&prices[i]);
	
	//considering array is not empty
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			span[i]=1;
			push(i);
		}
		else
		{
			while(!isEmpty() && prices[i]>= prices[stack[top]] )
			pop();
			
			if(isEmpty())
			span[i]=i+1;
			else
			span[i]=i-stack[top];
			push(i);
		}
	}
	
	printSpanArray(span,n);
	
	
	
}
