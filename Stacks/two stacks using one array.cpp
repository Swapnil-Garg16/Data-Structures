//implement two stacks using only one array
#include<stdio.h>
#include<stdlib.h>
#define N 6
int arr[N];
int topLeft = -1;
int topRight = N;

int isEmpty(int s)
{
	if(s==1)
	{
		if(topLeft==-1)
		return 1;
		return 0;
	}
	else
	{
		if(topRight==N)
		return 1;
		return 0;
	}
}

int isFull()
{
	if(topLeft+1==topRight)
	return 1;
	return 0;
}
void push(int s, int data)
{
	if(isFull()==1){
		printf("Stack is full\n");
		return;
	}
		
	if(s==1)
		arr[++topLeft]=data;
	else
	arr[--topRight]=data;
}

int pop(int s)
{
	
	if(s==1)
	{
		if(isEmpty(s)==1)
		{
			printf("Left Stack is empty\n");
			return -1;
		}
		else
		return arr[topLeft--];
	}
	else
	{
		if(isEmpty(s)==1)
		{
			printf("Right Stack is empty\n");
			return -1;
		}
		else
		return arr[topRight++];
	}
	
}

void print(int s)
{
	int i;
	if(s==1)
	{
		i=topLeft;
		while(i>=0)
		printf("%d ",arr[i--]);
	}
	else
	{
		i=topRight;
		while(i<N)
		printf("%d ",arr[i++]);
	}
	
	printf("\n");
}

int main()
{
	int choice,data, poppedData;
	while(1)
	{
	printf("Enter your choice :\n 1: Push in Left Stack \n 2: Push in Right Stack \n 3: Pop From Left Stack\n 4: Pop From Right Stack \n 5: Print Left Stack \n 6: Print Right Stack \n 7: Exit\n");
    scanf("%d",&choice);
    if(choice==7)
    break;
    switch(choice)
    {
    	case 1: 
    	printf("Enter data to be pushed\n");
    	scanf("%d",&data);
    	push(1,data);
    	break;
    	
    	case 2: 
    	printf("Enter data to be pushed\n");
    	scanf("%d",&data);
    	push(2,data);
    	break;
    	
    	case 3 : 
    	poppedData = pop(1);
    	if(poppedData!=-1)
    	printf("%d is popped\n",poppedData);
    	break;
    	
    	case 4:
    		poppedData = pop(2);
    		if(poppedData!=-1)
    	printf("%d is popped\n",poppedData);
    	break;
    	
    	case 5: 
    	print(1);
    	break;
    	
    	case 6:
    	print(2);
    	break;	
    	
    	
	}
	
}



}
