//postfix evaluation using stacks
#include<stdio.h>
#include<string.h>
#include<ctype.h> //to use isdigit function
#include<math.h>
#define N 100
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
	{
			stack[++top]= data;
//	printf("%c data is pushed\n",data);
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
		printf("%d ",stack[i--]);
	}
	printf("\n");
}

int performOp(char op, int var1, int var2)
{
	switch(op)
	{
		case '+' :
			return var1+var2;
			break;
		case '-':
			return var1-var2;
			break;
		case '*':
			return var1*var2;
			break;
		case '/':
			return var1/var2;
		case'^':
			return pow(var1,var2);
	}
}

int main()
{
	char s[100];
	char a,b;
	int l,i,var1,var2,ans;
	printf("Enter the postfix expression\n");
	scanf("%s",s);
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
		{
			var2 = pop();
			var1 = pop();
			ans = performOp(s[i],var1,var2);
		//	printf("%d is ans\n",ans);
			push(ans);
		}
		else
		{
			push(s[i]-'0');
		}
		
	//	print();
	}
	
	printf("%d ",stack[top]);
}

