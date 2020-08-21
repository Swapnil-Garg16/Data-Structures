//palindrome string
//Given an array of characters formed with a’s and b’s. The string is marked with
//special character X which represents the middle of the list (for example:
//ababa...ababXbabab baaa). Check whether the string is palindrome.
#include<stdio.h>
#include<string.h>
#include<ctype.h> 
#include<math.h>
#define N 100
int top=-1;
char stack[N];

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
void push(char data)
{
	if(isFull())
	printf("Stack Is in overflow condition\n");
	else
	{
			stack[++top]= data;
	}

}
int pop()
{
	
	if(isEmpty())
	printf("Stack is in underflow condition\n");
	else
	{
	return stack[top--];
	}

}

void print()
{
	int i=top;
	while(i>=0)
	{
		printf("%c ",stack[i--]);
	}
	printf("\n");
}
int main()
{
	char str[N];
	int flag=0;
	printf("Enter the string to be checked\n");
	scanf("%s",str);
	int i=0;
	while(str[i]!='X')
	{
		
		push(str[i]);
		i++;
	}
	i++;
	while(top>=0)
	{
		if(stack[top]==str[i])
		{
			pop();
			i++;
		}
		else 
		{
			flag=1;
			break;
		}
	}
	
	if(flag==0)
	printf("Palindrome\n");
	else printf("Not a palindrome\n");
	
}
