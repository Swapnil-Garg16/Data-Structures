//Merging 2 sorted list in a 3rd list in sorted order

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

//By creating a new Linekd List - space complexity - O(m+n) - not memory efficient
void merge(struct Node *head1, struct Node *head2, struct Node **head3)
{
	struct Node *temp1 = head1;
	struct Node *temp2 = head2;
	struct Node *temp3 = *head3;
	if(temp1==NULL)
	{
		*head3=temp2;
		return;
	}
	if(temp2==NULL)
	{
		*head3=temp1;
		return;
	}
	while(temp1!=NULL && temp2!=NULL)
	{
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
		newNode->next = NULL;
		if(temp3==NULL)
		{
			*head3=newNode;
			
		}
		else
		{
			temp3->next = newNode;
		
		}
		
			temp3=newNode;
		
		if(temp1->data <= temp2->data)
		{    
			newNode->data = temp1->data;
			temp1=temp1->next;
			
			continue;
		}
		else
		{
			newNode->data = temp2->data;
			temp2=temp2->next;
			continue;
		}
		
		
		
	}
	
	while(temp1!=NULL)
	{
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
		temp3->next=newNode;
		temp3=newNode;
		newNode->data = temp1->data;
		newNode->next=NULL;
		temp1=temp1->next;
		
	}
	
		while(temp2!=NULL)
	{
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
		temp3->next=newNode;
		temp3=newNode;
		newNode->data = temp2->data;
		newNode->next=NULL;
		temp2=temp2->next;
		
	}
}


//Merging without creating a new linked list - iterative method
void mergeWithoutExtraSpace ( struct Node *head1, struct Node *head2, struct Node **head3)
{
	struct Node *temp1,*temp2, *curr ;
	temp1= head1; 
	temp2= head2;
	curr = NULL;
	if(temp1==NULL)
	{
		*head3= head2;
		return;
	}
	
	if(temp2==NULL)
	{
		*head3 = head1;
		return;
	}
	
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->data <= temp2->data)
		{
			if(curr==NULL)
			{
				curr=temp1;
				*head3 = curr;
			}
			else
			{
				curr->next=temp1;
				curr=temp1;
			}
			temp1=temp1->next;
			
		}
		else
		{
				if(curr==NULL)
			{
				curr=temp2;
				*head3 = curr;
			}
			else
			{
				curr->next=temp2;
				curr=temp2;
			}
			temp2=temp2->next;
		}
	}
	
	if(temp2!=NULL)
	{
		curr->next=temp2;
	}
	
	if(temp1!=NULL)
	{
		curr->next = temp1;
	//	temp1=temp1->next;
	}
	
}

//recusrsive merge
struct Node *recursiveMerge ( struct Node *head1, struct Node *head2)
{
	if(head1==NULL)
	return head2;
	
	if(head2==NULL)
	return head1;

struct Node *head3 = NULL;
	
	if(head1->data<=head2->data)
	{
		head3=head1;
		head3->next = recursiveMerge(head1->next, head2);
	}
	else
	{
		head3 = head2;
		head3->next = recursiveMerge(head1,head2->next );
	}
	
	return head3;
}


int main()
{
	int n,i,pos,len;
	struct Node * head1,*head2, *head3 ;
	head1 = head2 = head3 = NULL;
	printf("Enter the length of 1st linked list\n");
	scanf("%d",&len);
	for(i=0;i<len;i++){
	printf("Enter the data to be added \n");
	scanf("%d",&n);
	insert(&head1,n);
	print(head1);
	
}

	printf("Enter the length of 2nd linked list\n");
	scanf("%d",&len);
	for(i=0;i<len;i++){
	printf("Enter the data to be added \n");
	scanf("%d",&n);
	insert(&head2,n);
	print(head2);
	
}

    head3 = recursiveMerge(head1,head2);
print(head3);
 
}
