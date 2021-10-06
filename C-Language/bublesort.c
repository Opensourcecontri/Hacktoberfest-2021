#include<stdio.h>
void bubblesort(int ar[],int size)
{
    int i,j,temp;
    for(i=size-1;i>=0;i--)
        for(j=0;j<i;j++)
        {
            if(ar[j]>ar[j+1])
            {
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
}
int main()
{
    int ar[50],size,i;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    printf("Enter the array elements:\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&ar[i]);
    }
    bubblesort(ar,size);
    printf("The sorted array is:\n");
    for(i=0;i<size;i++)
    {
        printf("%d\n",ar[i]);
    }
    return 0;
}