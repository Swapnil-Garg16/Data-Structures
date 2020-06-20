// doubly linked list - deletion
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * prev;
	struct Node *next;
};

void insert(struct Node **head,int data,int pos)
{
	struct Node * newNode =(struct Node *) (malloc)(sizeof(struct Node));
	struct Node *temp = *head;
	newNode->data = data;
	//ignoring the case when position is greater than linkedListLength+1 
	if(*head==NULL)
	{
		*head=newNode;
	newNode->next=NULL;
	newNode->prev=NULL;
	}
	else
	{
		if(pos==1)
		{
			temp->prev = newNode;
			newNode->next=temp;
			newNode->prev = NULL;
			*head=newNode;
		}
		else
		{
			int count = 1;
			while(count!=pos-1 && temp!=NULL)
			{
				temp=temp->next;
				count++;
			}
			
			newNode->next = temp->next;
			if(temp->next!=NULL)
			temp->next->prev = newNode;
			newNode->prev = temp;
			temp->next = newNode;
		}
	}
}

void deleteNode(struct Node **head,int pos)
{
	struct Node * temp = *head;
//	struct Node *prev=NULL;
	if(pos==1)
	{
		temp->next->prev=NULL;
		*head = temp->next;
		free(temp);
	}
	else
	{
		int count =1;
		while(count!=pos && temp!=NULL)
		{
			temp=temp->next;
			count++;
			
		}
		
		temp->prev->next=temp->next;
		if(temp->next!=NULL)
		temp->next->prev=temp->prev;
		free(temp);
	}
}

void print(struct Node *head)
{
	struct Node * temp = head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	
	printf("\n");
}

int main()
{
	int n,i,pos;
	struct Node * head = NULL;
	for(i=0;i<7;i++){
	printf("Enter the data to be added and it's position \n");
	scanf("%d %d",&n,&pos);
	insert(&head,n,pos);
	print(head);
}

for(i=0;i<4;i++)
{
	printf("Enter the node position you want to delete\n");
		scanf("%d",&pos);
	deleteNode(&head,pos);
	print(head);
	}	
	
}
