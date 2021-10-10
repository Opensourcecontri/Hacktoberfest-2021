#include<iostream>
using namespace std;

int main()
{
    int n,s;
    cout<<"enter size";
    cin>>n;
    int arr[n];
    cout<<"enter elems";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"enter sum";
    cin>>s;
    int currsum=0, start,End,j=0,i=0;

    while(j<n && currsum+arr[j]<=s)
        {
            currsum=currsum+arr[j];
            End=j;
            j++;
        }
    if(currsum==s)
        {
           cout<<start<<" "<<j;
           return 0;
        }

     while(j<n)
        {
            currsum=currsum+arr[j];
            while(currsum>s)
            {
                currsum=currsum-arr[i];
                i++;
            }
            if(currsum==s)
            {
                start=i;
                End=j;
                break;
            }
            j++;
        }
        cout<<start<<" "<<End;


    return 0;
}
