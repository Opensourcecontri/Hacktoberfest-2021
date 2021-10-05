#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
  char str[10][10];
  int n,i;
  printf("how many values do you want to enter");
  scanf("%d",&n);
  printf("Enter the name");
  for(i=0;i<n;i++)
  {
  scanf("%s",str[i]);
  }
  for(i=0;i<n;i++)
  {
  printf("%s\n",str[i]);
  }
  getch();
  }

