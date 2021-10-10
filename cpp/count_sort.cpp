#include <iostream>
using namespace std;

void countsort(int arr[], int n)
{
    int k=arr[0];
    for(int i=0;i<n;i++)
    {
        k=max(k,arr[i]);
    }

    int Count[10]={0};
    for(int i=0;i<n;i++)
    {
        Count[arr[i]]++;
    }

    for(int i=1;i<=k;i++)
    {
        Count[i]+=Count[i-1];
    }

    int output[n];
    for(int i=n-1;i>=0;i--)
    {
        output[--Count[arr[i]]]=arr[i];
    }

    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}

int main()
{
    int arr[]={1,3,2,3,4,1,6,4,3};
    countsort(arr,9);

    for(int i=0;i<9;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
