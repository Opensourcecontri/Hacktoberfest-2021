#include <bits/stdc++.h>
using namespace std;
void selection_sort (int arr[ ], int n) {
        // here is a temporary variable to store the position of minimum element
        int mnm;
        //this reduces the effective size of the array by one in each progessive iteration.
        for(int i = 0; i < n-1 ; i++)  {
           // assuming the first element to be the minimum of the unsorted array .
             mnm = i ;
          //this gives the effective size of the unsorted  array .
            for(int j = i+1; j < n ; j++ ) {
                if(arr[ j ] < arr[ mnm ])  {                //finds the minimum element
                mnm = j ;
                }
             }
          // putting minimum element on its proper position.
          swap ( arr[ mnm ], arr[ i ]) ;
        }
   }
int main()
{
    int n;
    cout<<"Enter size of an array."<<endl;
    cin>>n;
    cout<<endl<<"Enter array elements"<<endl;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"Here is your sorted array using Selection sort"<<endl;
    selection_sort(a,n);
    for(int i:a){
        cout<<i<<" ";
    }

    return 0;
 }
