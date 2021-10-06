#include<stdio.h>
void insertionsort(int ar[],int size);
int main()
{
    int ar[50],size,i;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    printf("Enter the array:\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&ar[i]);
    }
    insertionsort(ar,size);
    printf("Array after insertion sort:\n");
    for(i=0;i<size;i++)
    {
        printf("%d \n",ar[i]);
    }
    return 0;
}
void insertionsort(int ar[],int size)
{
    int i,j,temp;
    for(i=0;i<size;i++)
    {
        j=i;
        while((ar[j-1]>ar[j])&&j!=0)
        {
            temp=ar[j];
            ar[j]=ar[j-1];
            ar[j-1]=temp;
            j--;
        }
    }
}
