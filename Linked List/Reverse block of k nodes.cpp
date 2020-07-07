// Reverse blocks of k nodes
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

int hasNodes(struct Node *head, int k)
{
	struct Node *temp = head;
	if(head==NULL)
	return 0;
	
	int i=0;
	while(temp!=NULL)
	{
		temp=temp->next;
		i++;
	}
	if(i<k)
	return 0;
	else return 1;
	
}




struct Node * kBlockReverse(int k, struct Node *head)
{
	if(k==0||k==1)
	return head;
	
	if(hasNodes(head,k)==0)
	return head;
	
	
    struct Node *curr = head;
    struct Node *prev = NULL;
    struct Node *next = NULL;
    int cnt = 0;
    
    while(curr!=NULL && cnt<k )
    {
    	//printf("%d \n",curr->data);
    	next = curr->next;
    	curr->next = prev;
    	prev = curr;
    	curr=next;
    	cnt++;
	}
	
	if(next!=NULL)
	head->next = kBlockReverse(k,next);
	
	return prev;
}


int main()
{
	int n,i,pos,len,k;
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
	printf("Enter k\n");
	scanf("%d",&k);
   
   head1 = kBlockReverse(k,head1);
   //printf("%d is newhead\n",head1->data);
   print(head1);
 
}
