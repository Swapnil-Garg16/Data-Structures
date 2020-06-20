//Linked List insertion code - insert at any position
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
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
	}
	else
	{
		if(pos==1)
		{
			newNode->next=*head;
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
			temp->next = newNode;
		}
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
	for(i=0;i<10;i++){
	printf("Enter the data to be added and it's position \n");
	scanf("%d %d",&n,&pos);
	insert(&head,n,pos);
	print(head);
}
	
}
