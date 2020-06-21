//finding the starting node of the cycle/loop

int findStartingNode(struct Node *head)
{
	struct Node *slowptr, *fastptr;
	slowptr = fastptr = head;
	while(fastptr!=NULL && slowptr!=NULL && fastptr->next!=NULL )
	{
		fastptr = fastptr->next->next;
		slowptr = slowptr->next;
		
		if(slowptr==fastptr)
		{
			slowptr = head;
			while(slowptr!=fastptr)
			{
				slowptr=slowptr->next;
				fastptr= fastptr->next;
				
			}
			printf("%d - Head node"slowptr->data);
			return 1;
		}
		
		
	}
	
	return 0;
}
