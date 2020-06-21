// detecting cycle/loop in a linked list using Floyd Cycle Algorithm

//assuming that the insertion and other code exists.
int detectLoop(struct Node *head)
{
	struct Node *slowptr, *fastptr;
	slowptr = fastptr = head;
	while(fastptr!=NULL && slowptr!=NULL && fastptr->next!=NULL )
	{
		fastptr = fastptr->next->next;
		slowptr = slowptr->next;
		
		if(slowptr==fastptr)
		return 1;
	}
	
	return 0;
}
