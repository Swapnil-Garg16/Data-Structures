//counting nodes in circular LL


int nodesCount(struct Node *head)
{
	struct Node * temp=head;
	int count = 0;
	if(head==NULL)
	return 0;
	else{
    count = 1;
    temp=temp->next;
	while(temp!=head)
	{
		count++;
		temp=temp->next;
	}
	
	return count;
}
}
