//print contents of circular LL

void print(struct Node *head)
{
	if(head==NULL)
	printf("Linked list has no content\n");
	else
	{
		struct Node *temp = head;
		do{
			printf("%d ",temp->data);
			temp=temp->next;
		}while(temp!=head);
	}
}
