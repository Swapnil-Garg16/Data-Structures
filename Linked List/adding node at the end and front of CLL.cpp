//adding a node at the end/front of circular LL
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};

insert(struct Node **head, int data)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = data;
	struct Node *temp = *head;
	if(*head==NULL)
	{
		*head=newNode;
		newNode->next = newNode;
	}
	
	else
	{
		while(temp->next!=*head)
		{
			temp=temp->next;
		}
		temp->next = newNode;
		newNode->next = *head;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	if(head==NULL)
	return ;
	do{
		printf("%d  ",temp->data);
		temp=temp->next;
	}while(temp!=head);
	
	printf("\n");
}

void insertAtEnd(struct Node **head, int data)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	struct Node *temp = *head;
	newNode ->data = data;
	if(*head==NULL)
	{
		newNode->next = newNode;
		*head = newNode;
	}
	else
	{
		while(temp->next!=*head)
		temp=temp ->next;
		
		temp->next = newNode;
		newNode->next = *head;
	}
}

void insertNodeAtFront(struct Node **head, int data)
{
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	struct Node *temp = *head;
	newNode ->data = data;
	if(*head==NULL)
	{
		newNode->next = newNode;
	
	}
	else
	{
		while(temp->next!=*head)
		temp=temp ->next;
		
		temp->next = newNode;
		newNode->next = *head;
	}
	
		*head = newNode;
}

int main()
{
	struct Node *head = NULL;
	insert(&head,10);
	insert(&head,20);
	insert(&head,30);
	insert(&head,40);
	insert(&head,50);
	insert(&head,55);
	print(head);
	insertAtEnd(&head,60);
	insertNodeAtFront(&head,70);
	print(head);
}

