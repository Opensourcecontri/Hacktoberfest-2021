#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*newnode,*head;
void create(int item)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode-> data=item;
    newnode->link=NULL;
    struct node *temp;
    if(head==NULL)
    {
        head=newnode;
        temp=newnode;
    }
    else
    {
        temp->link=newnode;
        temp=temp->link;
    }
}
void count()
{
    struct node *temp = head;
    int c=0;
    while(temp!=NULL)
    {
        temp=temp->link;
        c++;
    }
    printf("Number of nodes:%d \n",c);
}
void display()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("list empty \n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d \n",temp->data);
            temp=temp->link;
        }
    }
}

int main()
{
    int i,j;
	j=1;
	printf("Enter -1 to stop \n");
	for(i=0;i<j;i++){
		int num;
		scanf("%d",&num);
		if (num==-1)
		   break;
		else{
			create(num);
			j++;
		}
	}
    display();
    count();
        

    return 0;
}
