#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int top = -1;
char *stack;
int size = 0;

char parentheses[2][3] = {
    {'(', '[', '{'},
    {')', ']', '}'}};

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(int value)
{
    if (top != size)
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

int checkPair(char opening, char closing)
{
    int A = opening == '(' && closing == ')';
    int B = opening == '[' && closing == ']';
    int C = opening == '{' && closing == '}';

    if (A || B || C)
        return 1;

    else
        return 0;
}

void printResult(int mismatch)
{
    if (!isEmpty())
        mismatch = 1;

    if (mismatch)
        printf("\nInvalid Expression\n");

    else
        printf("\nValid Expression\n");
}

int main()
{
    char string[50];
    printf("Enter the expression : ");
    scanf("%[^\n]", string);

    size = strlen(string);
    stack = (char *)calloc(size, sizeof(char));

    int mismatch = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (string[i] == parentheses[0][j])
            {
                push(string[i]);
            }
            if (string[i] == parentheses[1][j] && !checkPair(pop(), parentheses[1][j]))
                mismatch = 1;
        }
    }

    printResult(mismatch);
    return 0;
}
