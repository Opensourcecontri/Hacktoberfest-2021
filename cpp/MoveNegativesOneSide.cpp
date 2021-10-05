#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,i;
  cin>>n;
  int arr[n];
  for(i=0;i<n;i++){
    cin>>arr[i];
  }
  int beg=0;
	i=0;
	while (i<n)
	{
		if (arr[i]<0)
		{
			int temp=arr[i];
			arr[i] = arr[beg];
			arr[beg] = temp;
			beg++;
		}
		i++;
	}
  for(i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
}
