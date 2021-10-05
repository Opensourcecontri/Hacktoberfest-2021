#include<stdio.h>
#include<conio.h>
void main()
{
int var=9;
int *ptr1;
int **ptr2;
ptr1=&var;
ptr2=&ptr1;
   printf("value of var=%d\n",var);
     printf("address of var=%p\n",&var);
       printf("value of ptr1=%d\n",*ptr1);
         printf("address of ptr1=%p\n",&*ptr1);
           printf("value of ptr2=%d\n",**ptr2);
               printf("address of ptr2=%p\n",&**ptr2);
getch();

