//  Linked List length even or odd

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

int count(struct Node *head)
{
	if(head==NULL)
	return 0;
	struct Node *temp = head;
	int count = 1;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		count++;
	}
	
	return count;
}


// method 1 - by counting the length - O(n)
void oddOrEven(struct Node *head)
{
	int ct = count(head);
	if(ct==0)
	{
		printf("List is empty\n");
		return;
	}
	
	if(ct%2==0)
	printf("even\n");
	else printf("odd\n");
}

// method 2 - by fast pointer
void oddEvenTwoPtr(struct Node *head)
{
	if(head==NULL)
	return;
	struct Node  *fp;
	fp=head;
	while( fp!=NULL)
	{
		if(fp->next==NULL)
		{
			printf("odd\n");
			return;
		}
		if(fp->next->next==NULL)
		{
			printf("even\n");
			return;
			
		}
		
		fp=fp->next->next;
		
	}
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

oddEvenTwoPtr(head);
 
}
