//stack implementation using linked list
#include<stdio.h>
#include<stdlib.h>
#define N 5
int top =-1;
struct Node{
	struct Node *next;
	int data;
};


int isFull(struct Node *head)
{
	if(top==N-1)
	return 1;
	return 0;
}

int isEmpty(struct Node *head )
{
	if(top==-1)
	return 1;
	return 0;
}

void push(int data, struct Node **head)
{
	if(isFull(*head))
	{
		printf("Stack is in overflow state\n");
		return;
	}
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next = *head;
	*head = newNode;
	top++;
}

void pop(struct Node **head)
{
	if(isEmpty(*head)==1)
	{
		printf("Stack is in underflow state\n");
		return;
	}
	struct Node *temp;
	temp=*head;
	*head = temp->next;
	free(temp);
	top--;
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while(temp!=NULL)
	{
			printf("%d ",temp->data);
			temp=temp->next;
	}

	printf("\n");
}

void getTop(struct Node *head)
{
	if(head==NULL)
	printf("Stack is empty\n");
	else
	printf("%d\n",head->data);
}

int main()
{
	struct Node *head = NULL;
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
				push(data,&head);
				break;
			
			case 2: 
			pop(&head);
			break;
			
			case 3:
				print(head);
				break;
			
			case 4: 
			getTop(head);
			
		}
	}while(ch!=0);
}
