// Program a function to reverse a Linked List using three sliding pointer method (i.e.) by reversing the links.


#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void create (int A[], int n)
{
	int i; 
	struct Node *t, *last;
	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	last=first;
	for(i=1; i<n; i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

void Display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d ", p->data);
		p=p->next;
	}
}

void Reverse_links(struct Node *p)
{
	struct Node *q=NULL, *r=NULL;
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
}

int main()
{
	int A[]={10,20,30,40,50};
	create(A,5);
	Reverse_links(first);
	Display(first);
	printf("\n\n");
	return 0;
}


/*

Output :- 

50 40 30 20 10

*/
