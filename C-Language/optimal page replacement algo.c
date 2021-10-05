#include<stdio.h>
 int n;
 main()
 {
               int seq[30],fr[5],pos[5],find,flag,max,i,j,m,k,t,s;
                int count=1,pf=0,p=0;
               float pfr; 
                   clrscr();
                    printf("Enter maximum limit of the sequence: "); 
                    scanf("%d",&max);
                    printf("\nEnter the sequence: ");
                    for(i=0;i<max;i++)
                   scanf("%d",&seq[i]);
                   printf("\nEnter no. of frames: ");
                        scanf("%d",&n); 
                      fr[0]=seq[0];
                             pf++;
                       printf("%d\t",fr[0]); i=1; 
                     while(count<n) 
                         {
                              flag=1;
                               p++; 
                           for(j=0;j<i;j++) 
                              {
                                      if(seq[i]==seq[j]) flag=0;
                                 } 
                                 if(flag!=0) { fr[count]=seq[i]; 
                                  printf("%d\t",fr[count]);
                                   count++; 
                                    pf++; 
                            }
                            i++; 
                     }
                        printf("\n");
                 for(i=p;i<max;i++) 
                       {
                              flag=1;
                    for(j=0;j<n;j++) 
                               {
                                  if(seq[i]==fr[j]) flag=0;
                                }
                                if(flag!=0)
                                {
                                    for(j=0;j<n;j++)
                                        {
                                              m=fr[j];
                                             for(k=i;k<max;k++)
                                       {
                                           if(seq[k]==m)
                                              {
                                                    pos[j]=k;
                                                    break;
                                               } 
                                                else pos[j]=1;
                                        } 
                                 }
                             for(k=0;k<n;k++) 
                               {
                                     if(pos[k]==1) flag=0;
                                }
                                       if(flag!=0) s=findmax(pos);
                                      if(flag==0)
                                    {
                                         for(k=0;k<n;k++) 
                                        {
                                          if(pos[k]==1)
                                              {
                                                   s=k; break;
                                               }
                                       }
                                 }
                                fr[s]=seq[i];
                                for(k=0;k<n;k++) 
                                printf("%d\t",fr[k]);
                                pf++;
                                printf("\n");
                          }  }     
                          pfr=(float)pf/(float)max; 
                          printf("\nThe no. of page faults are %d",pf);
                           printf("\nPage fault rate %f",pfr);
                           getch(); 
       }
         int findmax(int a[])
           {   
                   int max,i,k=0;
                    max=a[0]; 
                    for(i=0;i<n;i++) 
                          {
                              if(max<a[i]) max=a[i];
                                 k=i;
                           }  }
                         return k; 
}
