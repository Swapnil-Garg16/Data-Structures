// implementation of stacks
#include<stdio.h>
#include<stdlib.h>
#define N 10
int top=-1;
int stack[N];

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
	stack[++top]= data;
}
void pop()
{
	if(isEmpty())
	printf("Stack is in underflow condition\n");
	else
	top--;
}

void print()
{
	int i=top;
	while(i>=0)
	{
		printf("%d ",stack[i]);
		i--;
	}
	printf("\n");
	
}

void getTop()
{
	printf("%d is top\n",top);
}

int main()
{
	int ch;
	int data;
	do{
		printf("enter choice : \n 1: Push \n 2: Pop \n 3: Print\n 4: Print Top\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter data you want to push\n");
				scanf("%d",&data);
				push(data);
				break;
			
			case 2: 
			pop();
			break;
			
			case 3:
				print();
				break;
			
			case 4: 
			getTop();
			
		}
	}while(ch!=0);
}
