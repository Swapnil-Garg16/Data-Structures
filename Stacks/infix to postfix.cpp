//infix to postfix
//Assumptions - Operands are upprcase/lowercase letters
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
//	printf("%c data is pushed\n",data);
	}

}
char pop()
{
	
	if(isEmpty())
	printf("Stack is in underflow condition\n");
	else
	{
	//	printf("%c data is popped\n",stack[top]);
			top--;
	}

}

int isOperator(char op)
{
	if(op=='+' || op=='-' || op=='*' || op=='/')
	return 1;
	return 0;
}

int isOperand(char opr)
{
	if((opr>=65 && opr <=90 )|| (opr>=97 && opr<=122))
	return 1;
	return 0; 
}

int checkPrecedence(char a)
{
	
if(a=='*' || a=='/')
{
	if(stack[top]=='^' || stack[top]=='*' || stack[top]=='/')
	return 0;
	else return 1;
}
else if(a=='+' || a=='-')
{
	return 0;
} 
else if(a=='^')
{
	if(stack[top]=='^')
	return 0;
	return 1;
}
	
}

int main()
{
	char expr[200];
	printf("enter the infix expression\n");
	scanf("%s",expr);
	char post[200];
	int len = strlen(expr);
	int i,j=0;
	for(i=0;i<len;i++)
	{
		if(isOperand(expr[i]))
		post[j++]=expr[i];
		else if(expr[i]=='(')
		push(expr[i]);
		else if(expr[i]==')')
		{
			while(!isEmpty() && stack[top]!='(')
			{
				post[j++]= stack[top];
				pop();
			}
			if(!isEmpty())
			pop();
		}
		else{
			//Assuming that it is operator only and no other ambiguous character is pushed
			if(top==-1 || stack[top]=='(')
			push(expr[i]);
			else
			{
				if(checkPrecedence(expr[i])==1)
				{
				//	printf("I am here checking the precedence\n");
					push(expr[i]);
				}
				
				else
				{
				//	printf("I am here in last else\n");
					while(isEmpty()==0 &&( stack[top]!='(' && checkPrecedence(expr[i])==0))
					{
				//		printf("inside while\n");
						post[j++]= stack[top];
				          pop();
					 }
					 push(expr[i]); 
				}
			}
		}
	}
	
	while(top>=0)
	{
		post[j++]=stack[top--];
	}
	post[j]='\0';
	printf("%s",post);
}
