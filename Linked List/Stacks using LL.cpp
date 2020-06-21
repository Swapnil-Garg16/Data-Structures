//Stacks using Linked List
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};

void push(struct Node **head, int data)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode ->data = data;
	newNode->next = *head;
	*head = newNode;
}

void pop(struct Node **head)
{
	if(*head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	struct Node *temp = *head;
	*head = temp->next;
	free(temp);
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

int main()
{
	printf("For push , press 1 and enter the number to be pushed\n");
	printf("For pop, press 2\n");
	int i,no,n;
	struct Node *head=NULL;
	for(i=1;i<=10;i++)
	{
		scanf("%d",&n);
		if(n==1)
		{
			printf("enter the no you want to be pushed\n");
			scanf("%d",&no);
			push(&head,no);
			print(head);
		}
		else if(n==2)
		{
			pop(&head);
			print(head);
		}
	}
}
