#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
  char str[10],temp;
  int i,j,len;
     printf("Enter the string");
         scanf("%s",&str);
           printf("%s\n",str);
             len=strlen(str);
               for(i=0;i<len-1;i++)
        {
          for(j=i+1;j<len;j++)
           {
            if(str[i]>str[j])
             {
              temp=str[j];
               str[j]=str[i];
                str[i]=temp;
                 }
                  }
                   }
                   printf("the alphabetical order of string is %s\n",str);
            getch();
                      }
