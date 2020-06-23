// reversing a singly linked list
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};

//inserting in a linked list
void insert(struct Node **head,int data)
{
	struct Node * newNode =(struct Node *) (malloc)(sizeof(struct Node));
	struct Node *temp = *head;
	newNode->data = data;

	if(*head==NULL)
	{
		*head=newNode;
	newNode->next=NULL;
	}
	else
	{
			
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next = newNode;
			newNode->next=NULL;
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

//iterative method of reversing a linked list
void reverse(struct Node **head)
{
	if(*head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	struct Node *t1,*t2,*t3;
	t1 = t3 = *head;
	if(t1->next)
	t2 = t1->next;
	else
	{
		print(*head);
		return;
	}
	
	while(t3!=NULL)
	{
		t3 = t2->next;
		t2->next = t1;
		if(t1==*head)
		t1->next = NULL;
		t1=t2;
		t2=t3;
	}
	
	*head = t1;
}

int main()
{
	int n,i,pos,len;
	struct Node * head = NULL;
	printf("Enter the length of linked list\n");
	scanf("%d",&len);
	for(i=0;i<len;i++){
	printf("Enter the data to be added \n");
	scanf("%d",&n);
	insert(&head,n);
	print(head);
	
}

    reverse(&head);
	print(head);
}
