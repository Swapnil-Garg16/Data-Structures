//splitting circular list into 2 equal parts

int count(struct Node *head)
{
	if(head==NULL)
	return 0;
	
	struct Node *temp = head;
	int cnt = 1;
    while(temp->next!=head)
    {
    	temp=temp->next;
    	cnt++;
	}
	
	return cnt;
}


//method 1 - by counting the length and splitting
void (struct Node **head1, struct Node **head2)
{
	int cnt = count(head1);
	int n;
	if(cnt%2==0);
	n=cnt/2;
	else n=cnt/2 +1;
	struct Node *pre = NULL;
	struct Node *temp = *head1;
	while(n>0)
	{
		pre= temp;
		temp=temp->next;
		n--;
	}
	
	pre->next = *head1;
	*head2 = temp;
	n=cnt/2;
		while(n>0)
	{
		pre= temp;
		temp=temp->next;
		n--;
	}
	pre->next = *head2;
	
}

//by mid and last pointers through Floyd Cycle Algo
void twoPointerSplit(struct Node *head, struct Node **head1, struct Node **head2)
{
	if(head==NULL || head->next==head)
	return;
	

	struct Node *sp,*fp;
	sp=fp=head;
	
	while(fp->next!=head && fp->next->next!=head)
	{
		sp=sp->next;
		fp=fp->next->next;
		
	}
	if(fp->next->next==head)
	fp=fp->next;
	
	*head1=head;
	*head2=sp->next;
	
	sp->next = *head1;
    fp->next=*head2;
}
