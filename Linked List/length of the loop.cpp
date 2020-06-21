//finding the length of the loop
int loopLength(struct Node *head)
{
	struct Node *slowptr, *fastptr;
	slowptr = fastptr = head;
	while(fastptr!=NULL && slowptr!=NULL && fastptr->next!=NULL )
	{
		fastptr = fastptr->next->next;
		slowptr = slowptr->next;
		
		if(slowptr==fastptr)
		{
			int count = 0;
			do{
				fastptr = fastptr->next;
				count++;
			}while(fastptr!=slowptr);
			
			printf("%d is the length\n",count);
			return;
		}
	}
	printf("no loop detected\n");
	return ;
}
