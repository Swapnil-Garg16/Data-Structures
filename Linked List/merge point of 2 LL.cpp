//merge point of 2 linked list 

int count ( struct Node * head)
{
	if(head==NULL)
	return 0;
	struct Node *temp = head;
	int count=1;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		count++;
	}
	return count;
}

//using the difference in length of both the linkedlist.
void mergePoint(struct Node *head1, struct Node *head2)
{
	if(head1== NULL || head2==NULL)
	return;
	
	int count1 = count(head1);
	int count2 = count(head2);
	int diff = 0;
	struct Node *temp1 = head1;
	struct Node *temp2 = head2;
	if(count1>count2)
	{
		diff = count1-count2;
		while(diff>0)
		{
			temp1=temp1->next;
			diff--;
		}
	}
	else
	{
		diff = count2-count1;
		while(diff>0)
		{
			temp2=temp2->next;
			diff--;
		}
		
	}
	
	while(temp1!=NULL && temp2!=NULL)
	{
		temp1=temp1->next;
		temp2=temp2->next;
		if(temp1==temp2)
		{
			printf("%d is the merge point\n",temp1->data);
			return;
		}
		
	}
	
	printf("No merge point found\n");
}

//using stacks - O(max (count1,count2))
void mergePointUsingStacks(struct Node *head1, *head2)
{
	if(head1== NULL || head2==NULL)
	return;
	
	int count1 = count(head1);
	int count2 = count(head2);
	int arr1[count1], arr2[count2];
	struct Node *temp1, *temp2;
	temp1= *head1;
	temp2= *head2;
	int j;
	int i=0;
	while(temp1!=NULL)
	{
		arr1[i++]=temp1;
		temp1=temp1->next;
	}
	i=0;
	while(temp2!=NULL)
	{
		arr2[i++]=temp2;
		temp2=temp2->next;
	}
	
	i=count1-1;
	j = count2-1;
	int mergePt;
	while( i>0 && j>0)
	{
		if(arr1[i]==arr2[j]){
		mergePt = arr1[i];
		i--;
		j--;
	}
	else {
		printf("%d is the address of merge point node\n",mergePt);
		return;
	}
		
	}
	
	printf("linked lists don't merge\n");
	
	
}

