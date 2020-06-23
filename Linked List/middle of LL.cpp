// Middle of linked list
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

//O(n) solution by finding the length of the linked list
void middle(struct Node *head)
{
	
	int ct = count(head);
	int mid;
	if(ct%2==0)
	mid = ct/2;
	else mid = ct/2+1;
	if(ct)
	{
		struct Node *temp = head;
		while(mid>1 && temp!=NULL)
		{
			mid--;
			temp=temp->next;
			
		}
		
		printf("%d is the mid\n",temp->data);
		return;
	}
	else
	{
		printf("empty linked list\n");
	}
}

//two pointer approach

void midTwoPtr(struct Node *head)
{
	if(head==NULL)
	return;
	struct Node *sp , *fp;
	sp=fp=head;
	while(sp!=NULL && fp!=NULL && fp->next!=NULL && fp->next->next!=NULL)
	{
		sp=sp->next;
		fp=fp->next->next;
		
	}
	
	printf("%d is mid\n",sp->data);
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

    midTwoPtr(head);
}

