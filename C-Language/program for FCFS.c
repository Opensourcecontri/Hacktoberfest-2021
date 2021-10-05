#include<stdio.h>
#include<conio.h>
#define max 30
void main()
{
int i,j,n,bt[max],wt[max],tat[max];
float awt=0,atat=0;
printf("Enter the number of process");
scanf("%d",&n);
printf("Enter the bust time of the process");
for(i=0;i<1;i++)
{
scanf("%d",&bt[i]);
}
printf("process time \t bust time \t waiting time \t turn around time\n");
for(i=0;i<n;i++)
{
wt[i]=0;
tat[i]=0;
for(j=0;j<1;j++)
{
wt[i]=wt[i]+bt[j];
}
tat[i]=wt[i]+bt[i];

awt=awt+wt[i];
atat=atat+tat[i];
printf("%d \t %d \t %d \t %d",i+1,bt[i],wt[i],tat[i]);
awt=awt/n;
atat=atat/n;
printf("Average waiting time=%f\n",awt);
printf("Average turn around time=%f\n",atat);
getch();
}
}
