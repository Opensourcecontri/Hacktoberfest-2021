#include<stdio.h>
#include<conio.h>
void main()
{
int i,j,A[10];
printf("Enter the value of array");
for(i=0;i<10;i++)
{
scanf("%d",&A[i]);
}
for(i=0;i<10;i++)
{
printf("Element of the array is %d\n",A[i]);
}
for(i=0;i<10;i++)
{
for(j=i+1;j<10;j++)
{
    if (A[i]<A[j])
    {
        A[i]=A[j];
    }
}}
printf("Largest value is %d",A[0]);
getch();
}
