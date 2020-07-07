//check palindrome
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
void reverse(struct Node **head)
{
	
	if(*head==NULL || (*head)->next==NULL)
	return;
	
	struct Node *temp = *head;
	struct Node *prev, *curr;
	prev=curr = *head;
	
	while(temp!=NULL)
	{
		if(temp==*head)
		temp=prev->next;
		curr=temp->next;
		temp->next = prev;
		if(prev==*head)
		prev->next=NULL;
		prev=temp;
		temp=curr;
		
		if(curr==NULL)
		*head = prev;
	}
	
	print(*head);
	
	
}
//check palindrome
void checkPalindrome(struct Node *head)
{
	struct Node *s,*f;
	s=f=head;
	while(f->next!=NULL && f->next->next!=NULL)
	{
		f=f->next->next;
		s=s->next;
	}
	
	reverse(&(s->next));
	struct Node *first, *second;
	first=head;
	second=s->next;
	while(first!=NULL && second!=NULL)
	{
		if(first->data==second->data)
		{
			first=first->next;
			second=second->next;
			continue;
		}
		
		else
		{
				printf("Not a palindrome\n");
				return;
		}
	}
	
	printf("Palindrome\n");

	
}


int main()
{
	int n,i,pos,len;
	struct Node * head1,*head2, *head3 ;
	head1 = head2 = head3 = NULL;
	printf("Enter the length of linked list\n");
	scanf("%d",&len);
	for(i=0;i<len;i++){
	printf("Enter the data to be added \n");
	scanf("%d",&n);
	insert(&head1,n);
	print(head1);
	
}
checkPalindrome(head1);
   
 
}
