//checking balancing of symbols.
#include<stdio.h>
#include<string.h>
#define N 20
int top=-1;
char arr[N];

int isFull()
{
	if(top==N-1)
	return 1;
	return 0;
}

int isEmpty()
{
	if(top==-1)
	return 1;
	return 0;
}

void pop()
{
//	printf("%c popped\n",arr[top]);
	top--;
}

void push(char a)
{
//	printf("%c is pushed\n",a);
	arr[++top]=a;
}
void print()
{
	int i = top;
	while(i>=0)
	{
		printf("%c in stack\n",arr[i]);
		i--;
	}
}

int main()
{
	int flag=0,i;
	char str[50];
	scanf("%s",str);
	int len = strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]=='[' || str[i]=='{' || str[i]=='(')
		push(str[i]);
		else {
			if(str[i]==']')
			{
				if(arr[top]=='[')
				pop();
				else{
					flag=1;
					break;
				}
			}
			else if(str[i]==')')
			{
				if(arr[top]=='(')
				pop();
				else
				{
					flag=1;
					break;
				}
			}
			else if(str[i]=='}')
			{
				if(arr[top]=='{')
				pop();
				else
				{
					flag=1;
					break;
				}
			}
			
		}
	//	print();
	}
	
	if(flag==0 && top!=-1)
	flag=1;
	
	if(flag==0)
	printf("balanced\n");
	else
	printf("unbalanced\n");
}
