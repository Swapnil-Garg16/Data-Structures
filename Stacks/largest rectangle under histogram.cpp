//Largest rectangle area in a histogram
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
	int rect,i,max;
	printf("Enter no of rectangles\n");
	scanf("%d",&rect);
	int height[rect],rightSmall[rect],leftSmall[rect], width[rect];
	printf("Enter height of each rectangle\n");
	for(i=0;i<rect;i++)
	scanf("%d",&height[i]);
	
	for(i=rect-1;i>=0;i--)
	{
		if(i==rect-1)
		rightSmall[i]=rect;
		else
		{
			if(height[stack[top]]<height[i])
			rightSmall[i]=stack[top];
			else
			{
				while(!isEmpty() && height[stack[top]]>=height[i])
				pop();
				
				if(top!=-1)
				rightSmall[i]=stack[top];
				else
				rightSmall[i]=rect;
			}
		}
		
		push(i);
	}
	
	printArray(rightSmall,rect);
	
	while(top>=0)
	pop();
	
	for(i=0;i<rect;i++)
	{
		if(i==0)
		leftSmall[i]=-1;
		else
		{
			if(height[stack[top]]<height[i])
			leftSmall[i]=stack[top];
			else
			{
				while(!isEmpty() && height[stack[top]]>=height[i])
				pop();
				
				if(top!=-1)
				leftSmall[i]=stack[top];
				else
				leftSmall[i]=-1;
			}
		}
		
		push(i);
	}
	
	printArray(leftSmall,rect);
	
	max=1;
	for(i=0;i<rect;i++)
	{
		width[i]=rightSmall[i]-leftSmall[i]-1;
		if(width[i]*height[i]>max)
		max=width[i]*height[i];
	}
	
	printf("%d\n",max);
	
	
}
