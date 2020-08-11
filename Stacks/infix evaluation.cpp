//evaluating infix expression with stacks in 1 pass
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 100
int topN=-1;
int topS=-1;
int stackN[N];
char stackS[N];

int isFullStackN()
{
	if(topN==N-1)
	return 1;
	else return 0;
}

int isFullStackS()
{
	if(topS==N-1)
	return 1;
	else return 0;
}

int isEmptyStackN()
{
	if(topN==-1)
	return 1;
	return 0;
}

int isEmptyStackS()
{
	if(topS==-1)
	return 1;
	return 0;
}
void pushStackN(int data)
{

	if(isFullStackN())
	printf("Operands Stack Is in overflow condition\n");
	else
	stackN[++topN]= data;
}

void pushStackS(char data)
{

	if(isFullStackS())
	printf("Operators Stack Is in overflow condition\n");
	else
	stackS[++topS]= data;
}
int popStackN()
{

	if(isEmptyStackN())
	printf("Operands Stack is in underflow condition\n");
	else
	return stackN[topN--];

}

char popStackS()
{

	if(isEmptyStackS())
	printf("Operators Stack is in underflow condition\n");
	else
		return stackS[topS--];
}

/*void print()
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
} */

int checkPriority(char a)
{
	if(a=='+' || a=='-')
	{
		 return 0;
	}
	else if(a=='*' || a=='/')
	{
		if(stackS[topS]=='-' || stackS[topS]=='+')
		return 1;
		else return 0;
	}
	else if(a=='^')
	{
		return 1;
	}
}

int performOp(char op, int a,int b)
{
	switch(op)
	{
		case '+':
			return a+b;
			case'-':
				return a-b;
				case '*':
					return a*b;
					case '/':
						return a/b;
						case '^':
							return pow(a,b);
	}
}

int main()
{
	char arr[100];
	scanf("%s",arr);
	int len = strlen(arr);
	int i;
	int a,b;
	char op;
	for(i=0;i<len;i++)
	{
		if(arr[i]=='(')
		pushStackS(arr[i]);
		else if(arr[i]=='+' || arr[i]=='-' ||arr[i]=='*' ||arr[i]=='/' || arr[i]=='^')
		{
			if(topS==-1 || stackS[topS]=='(' || checkPriority(arr[i]))
			pushStackS(arr[i]);
			else
			{
				while(!isEmptyStackN() && !isEmptyStackS() && !checkPriority(arr[i]))
				{
					op = popStackS();
				int b= popStackN();
				int a = popStackN();
				pushStackN(performOp(op,a,b));
				}
				pushStackS(arr[i]);
			}
		}
		else if(arr[i]==')')
		{
			while(!isEmptyStackN() && !isEmptyStackS() && stackS[topS]!='(' )
			{
				op = popStackS();
				int b= popStackN();
				int a = popStackN();
				pushStackN(performOp(op,a,b));
			}
			op=popStackS();
		}
		else
		{
			pushStackN(arr[i]-'0');
		}
		
	}

	
	while(!isEmptyStackS())
	{
		op = popStackS();
				int b= popStackN();
				int a = popStackN();
				pushStackN(performOp(op,a,b));
				
	}
	

	printf("%d is answer\n",stackN[topN]);
	
}
