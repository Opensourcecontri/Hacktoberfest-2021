#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top = -1;
char *stack;
int size = 0;

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (top == size)
        return 1;
    else
        return 0;
}

void push(int value)
{
    if (!isFull())
    {
        top++;
        stack[top] = value;
    }
}

char pop()
{
    if (!isEmpty())
    {
        char temp = stack[top];
        top--;
        return temp;
    }
}

void printOutput(int palindrome, char *string)
{

    printf("\nOutput : This string is ");

    if (palindrome != 1)
        printf("not ");

    printf("a palindrome\n");
}

int main()
{
    char string[50];
    printf("Enter the string : ");
    scanf("%s", string);
    printf("\nInput : %s \n", string);
    size = strlen(string);

    stack = (char *)calloc(size / 2, sizeof(char));

    int i;
    int palindrome = 1;
    for (i = 0; i < size / 2; i++)
    {
        push(string[i]);
    }

    if (size % 2 == 1)
        i++;

    int j = i;
    while (string[j] != '\0')
    {
        char temp = pop();
        if (temp != string[j])
            palindrome = 0;
        j++;
    }

    printOutput(palindrome, string);

    return 0;
}