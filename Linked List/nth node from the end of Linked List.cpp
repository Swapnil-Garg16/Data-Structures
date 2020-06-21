//nth node from the end of Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
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

int countNodes(struct Node *head)
{
	struct Node *temp = head;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	
	return count;
}

// O(n) solution in 2 scans - one for counting the length of linked list and one for getting the element count-n+1
void nthNodeFromEnd(struct Node *head, int n)
{
	int count = countNodes(head);
	if(n>count)
	{
		printf("Node doesn't exist\n");
		return ;
	}
	struct Node *temp = head;
	count=count-n+1;
	int pos = 1;
	while(pos!=count && temp!=NULL)
	{
		temp=temp->next;
		pos++;
	}
	
	printf("%d\n",temp->data);
	
}

// O(n) solution with one scan using 2 pointers
void nthFromEnd(struct Node *head, int n)
{
	struct Node *temp, *temp1;
	temp=temp1=head;
	int count = countNodes(head);
	if(n>count)
	{
		printf("Node doesn't exist\n");
		return ;
	}
	int pos=1;
	while(pos!=n)
	{
		temp=temp->next;
		pos++;
	}
	
	while(pos!=count && temp->next!=NULL)
	{
		temp=temp->next;
		temp1=temp1->next;
		pos++;
	}
	
	printf("%d \n",temp1->data);
}

int main()
{
	int n,i,pos;
	struct Node * head = NULL;
	for(i=0;i<10;i++){
	printf("Enter the data to be added \n");
	scanf("%d",&n);
	insert(&head,n);
	print(head);
}
for(i=0;i<4;i++)
{
printf("Enter n\n");
scanf("%d",&n);
nthFromEnd(head,n);

}
	
}
