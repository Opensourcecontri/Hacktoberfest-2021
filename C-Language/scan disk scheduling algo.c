#include<stdio.h>
 main()
 {
           int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum=0;
             clrscr();
              printf("enter the no of tracks to be traveresed");
             scanf("%d'",&n);
              printf("enter the position of head"); 
              scanf("%d",&h);
              t[0]=0;t[1]=h;
              printf("enter the tracks");
              for(i=2;i<n+2;i++)
              scanf("%d",&t[i]);
                for(i=0;i<n+2;i++) 
                {
                       for(j=0;j<(n+2)-i-1;j++)
                            { 
                               if(t[j]>t[j+1])
                                     {
                                            temp=t[j]; t[j]=t[j+1];
                                               t[j+1]=temp; 
        }     }    }
              for(i=0;i<n+2;i++)
                if(t[i]==h) 
                               j=i;k=i;
            p=0;
               while(t[j]!=0)
                  {
                      atr[p]=t[j];
                       j--; p++;
                  }
                 atr[p]=t[j];
                for(p=k+1;p<n+2;p++,k++) atr[p]=t[k+1]; 
                 for(j=0;j<n+1;j++) 
                      {
                         if(atr[j]>atr[j+1])
                                         d[j]=atr[j]-atr[j+1];
                           else 
                                          d[j]=atr[j+1]-atr[j];
                                   sum+=d[j];
                            }
                         printf("\nAverage header movements:%f",(float)sum/n); 
                         getch(); }
