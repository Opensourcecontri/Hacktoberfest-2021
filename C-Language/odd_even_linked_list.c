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
void oddeven()
{
    struct node *temp = head;
    int even,odd=0;
    
    while(temp!=NULL)
    {
        if((temp->data)%2==0)
        {
            even++;
        }
        else
        {
            odd++;
        }
         temp=temp->link;
    }
    printf("Number of even numbers :%d \n",even);
    printf("Number of odd numbers :%d \n",odd);
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
    oddeven();
        

    return 0;
}
