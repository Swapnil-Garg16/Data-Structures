//getMinimum() in O(1) with efficient space complexity
//Assumption all nos >0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define N 100
int top=-1;
int topMin=-1;
int stack[N];
int stackMin[N];


void push(int data,int min)
{
	
	stack[++top]= data;
	if(min!=0)
	stackMin[++topMin]= min;
}
int pop()
{
   return stack[top--];
}

int popMin()
{
	return stackMin[topMin--];
}

int getMin()
{
	return stackMin[topMin];
}

void print()
{
	int i=top;
	while(i>=0)
	printf("%d ",stack[i--]);
	printf("\n");
}

void printMin()
{
	int i=topMin;
	while(i>=0)
	printf("%d ",stackMin[i--]);
	printf("\n");
}
int main()
{
	int n,no,min,t,p;
	while(1){
	printf("press 1: push\n 2: pop \n 3: minimum no \n 4: print number stack\n 5: print min stack\n");
	scanf("%d",&n);
	
	switch(n)
	{
		case 1:
			printf("enter no to be pushed\n");
			scanf("%d",&no);
			
			if(top==-1 || stackMin[topMin]>=no)
			{
				min=no;
				push(no,min);
			}
			else
			{
				push(no,0);
			 } 
			break;
		case 2:
			t = pop();
			if(t==stackMin[topMin])
			p = popMin();
			break;
		case 3:
		printf("minimum no : %d\n",getMin());
			break;
		case 4:
			print();
			break;
		case 5:
			printMin();
			break;
		default:
			exit(0);
	}
}
	
}

