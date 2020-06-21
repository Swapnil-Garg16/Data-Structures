//inserting node in a sorted LL
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};

void insert(struct Node **head, int n)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = n;
	if(*head==NULL)
	{
		newNode->next=NULL;
		*head=newNode;
	}
	else
	{
		struct Node *temp = *head;
		struct Node *prev = *head;
		if(temp->data>n)
		{
			newNode->next = *head;
			*head = newNode;
			return;
		}
		else
		{
			while(temp->data<n && temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		
		if(temp->data<n && temp->next==NULL)
		{
			temp->next=newNode;
			newNode->next = NULL;
		}
		else{
		
		prev->next = newNode;
		newNode->next = temp;
	}
		return;
		}
		
		
	}
	
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
	struct Node *head = NULL;
	int n,i;
	for(i=0;i<6;i++){
	printf("enter the no you want to insert\n");
	scanf("%d",&n);
	insert(&head,n);
	print(head);
	
}
}
