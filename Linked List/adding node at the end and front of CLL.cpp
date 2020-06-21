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

//inserting a node at the end of circular linked list
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

//inserting a node at front of the circular linked list
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

//delete last node from circular linked list
void deleteLastNode(struct Node **head)
{
	struct Node *temp = *head;
	struct Node *prev = NULL;
	if(*head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	
	while(temp->next!=*head)
	{
		prev = temp;
		temp=temp->next;
	}
	prev->next = temp->next;
	free(temp);
	return;
	
	
}

//delete first node from circular linked list
void deleteFirstNode(struct Node **head)
{
	struct Node *temp = *head;
	struct Node *prev = NULL;
	if(*head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	
	do{
			prev = temp;
		temp=temp->next;
	}while(temp!=*head);

	prev->next = temp->next;
	*head = temp->next;
	free(temp);
	return;
	
	
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
		print(head);
	insertNodeAtFront(&head,70);
	print(head);
	deleteLastNode(&head);
	print(head);
	deleteFirstNode(&head);
	print(head);
		deleteLastNode(&head);
	print(head);
	deleteFirstNode(&head);
	print(head);
}

