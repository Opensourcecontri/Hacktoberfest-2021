#include <stdio.h>
#include <stdlib.h>
typedef struct Stack
{
    int data;
    struct Stack *link;
} Stack;
void push(Stack **, int);
int pop(Stack **);
int isEmpty(Stack *);
void display(Stack *);
void enqueue(Stack **, int);
int dequeue(Stack **);
int main()
{
    typedef Stack Queue;
    Queue *queue = NULL;
    int choice;
    do
    {
        int val;
        printf("1) Insert \n2) display\n3) Delete top\n4) Exit\n->: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value : ");
            scanf("%d", &val);
            enqueue(&queue, val);
            printf("\ntop->");
            display(queue);
            break;
        case 2:
            //printf("\ntop->");
            display(queue);
            break;
        case 3:
            printf("\nDeleted element: %d\n", dequeue(&queue));
            break;
        default:
            printf("\nExiting...\n");
        }
        printf("----------------------------\n");
    } while (choice >= 1 && choice <= 3);
    return 0;
}
void push(Stack **Stack_top, int num)
{
    Stack *temp = (Stack *)malloc(sizeof(Stack));
    temp->data = num;
    temp->link = *Stack_top;
    *Stack_top = temp;
}
int pop(Stack **Stack_top)
{
    if (isEmpty(*Stack_top))
    {
        printf("\nUnderflow!");
        return -999;
    }
    Stack *temp = (*Stack_top);
    *Stack_top = (*Stack_top)->link;
    int val = temp->data;
    free(temp);
    return val;
}
int isEmpty(Stack *Stack_top)
{
    if (!Stack_top)
        return 1;
    return 0;
}
void display(Stack *Stack_top)
{
    if (isEmpty(Stack_top))
    {
        printf("\b\b \n");
        return;
    }
    int temp = pop(&Stack_top);
    printf("%d->", temp);
    display(Stack_top);
    push(&Stack_top, temp);
}
void enqueue(Stack **Stack_top, int num)
{
    if (isEmpty(*Stack_top))
    {
        push(Stack_top, num);
        return;
    }
    int temp = pop(Stack_top);
    enqueue(Stack_top, num);
    push(Stack_top, temp);
}
int dequeue(Stack **Stack_top)
{
    return pop(Stack_top);
}
