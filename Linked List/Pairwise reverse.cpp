//reverse linked list in pairs
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

//pair wise reverse - iterative method
void pairReverse(struct Node *head,struct Node **head2)
{
	struct Node *temp1,*temp2,*curr;
	curr = head;
	temp1=temp2=NULL;
	if(curr==NULL || curr->next==NULL)
	{
		*head2 = head;
		return;
	}
	while(curr!=NULL && curr->next!=NULL)
	{
		if(temp2!=NULL)
		{
			temp2=temp1;
			temp2->next=temp2->next->next;
		}
		 temp1 = curr->next;
		curr->next = curr->next->next;
		temp1->next=curr;
		if(temp2==NULL)
		{
			temp2 = temp1;
			*head2 = temp2;
		}
		temp1=curr;
		curr=curr->next;
	}
}

//recursive method
struct Node *recursiveReversal(struct Node *head)
{
	if(head==NULL || head->next==NULL)
	return head;
	
	struct Node *temp;
	temp = head->next;
	head->next = head->next->next;
	temp->next = head;
	head=temp;
	head->next->next = recursiveReversal(head->next->next);
	return head;
	
}

int main()
{
	int n,i,pos,len;
	struct Node * head1,*head2 ;
	head1 = head2 =NULL;
	printf("Enter the length of linked list\n");
	scanf("%d",&len);
	for(i=0;i<len;i++){
	printf("Enter the data to be added \n");
	scanf("%d",&n);
	insert(&head1,n);
	print(head1);
	
}
head2 = recursiveReversal(head1);
print(head2);

}
