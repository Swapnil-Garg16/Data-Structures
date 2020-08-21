//reverse stack using recursion
#include<stdio.h>
#include<stdlib.h>
#define N 100
int top=-1;
int arr[N];
int isFull()
{
	if(top==N-1)
	return 1;
	else return 0;
}

int isEmpty()
{
	if(top==-1)
	return 1;
	return 0;
}
void push(int data)
{
	if(isFull())
	printf("Stack Is in overflow condition\n");
	else
	{
			arr[++top]= data;
//	printf("%c data is pushed\n",data);
	}

}
int pop()
{
	
	if(isEmpty())
	printf("Stack is in underflow condition\n");
	else
	{
	 return arr[top--];
	}

}

void insertBack(int temp)
{
	if(top==-1)
	{
		push(temp);
		return;
	}
	
	
	int a = pop();
	insertBack(temp);
	push(a);
}

void reverse()
{
	if(top==-1)
	return;
	
	int temp = pop();
	reverse();
	
	insertBack(temp);
	
}

void print()
{
	int i = top;
	while(i>=0)
	printf("%d ",arr[i--]);
	printf("\n");
}

int main()
{
	int n,no,i;
	printf("Enter no of elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&no);
		push(no);
	}
	printf("original stack is : \n");
	print();
	reverse();
	printf("reversed stack is : \n");
	print();
}
