#include<stdio.h>
#include<string.h>
int main()
{
	//code
	int t,i;
	char arr[25];
	char stack[25];
	int top ;
	scanf("%d",&t);
	while(t--)
	{
		top=-1;
	    scanf("%s",arr);
	    i=0;
	    while(i<strlen(arr))
	    {
	        if(top==-1)
	        stack[++top]=arr[i];
	        else
	        {
	            if(stack[top]!=arr[i])
	            stack[++top]=arr[i];
	        }
	        i++;
	    }
	    i=0;
	    while(i<=top)
	    printf("%c",stack[i++]);
	    printf("\n");
	    
	}
	return 0;
}
