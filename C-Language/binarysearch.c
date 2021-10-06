#include<stdio.h>
int main()
{
    int ar[30],n,s,i,strt=0,mid,end,flag=0;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    end=n-1;
    printf("Enter the array elements in ascending order:\n");
    for ( i=0;i<n;i++)
        scanf("%d",&ar[i]);
    printf("Enter the number to be searched for :");
    scanf("%d",&s);
    printf("The array is:\n");
    for(i=0;i<n;i++)
        printf("%d\n",ar[i]);
    while(strt<=end)
    {
        if(ar[mid]==s)
            {
                printf("The element is found and is in index:%d",mid);
                flag=1;
                break;
            }
        else if(s<ar[mid])
            {
                end=mid-1;
                mid=(strt+end)/2;
            }
        else if(s>ar[mid])
            {
                strt=mid+1;
                mid=(strt+end)/2;
            }
    }
    if(flag==0)
        printf("Element not found.");
    return 0;


}
