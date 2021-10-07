
//Write a program to reverse an array elements

// Naive Approach
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin >> t;
    while(t--)
    {
        int n,cnt=0;
        cin>>n;
        int a[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        reverse(a,a+n);
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
	
	return 0;
}

//T.C = O(n)
//S.C = O(n)   


// This is my another solution Approach for Reverse an array

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin >> t;
    while(t--)
    {
        int n,cnt=0;
        cin>>n;
        int a[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        // Initialise two pointer start and end 
        int start = 0, end = n-1; 
        
        // My Array Elements what i am taking in example
      
        //index 0 1 2 3 4 5
        //value 1 2 3 4 5 6
        
        //1st iteration   start = 0, end = 5
        
        //index 0 1 2 3 4 5
        //value 6 2 3 4 5 1
        
        //2nd iteration   start = 1, end = 4
        
        //index 0 1 2 3 4 5
        //value 6 5 3 4 2 1
        
        //3rd iteration   start = 2, end = 3
        
        //index 0 1 2 3 4 5
        //value 6 5 4 3 2 1

        //4th iteration   start = 3, end = 2 which is not satisfy the condition         
        while(start<end){
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;
            start++;
            end--;
        }
            
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
	
	return 0;
}

//T.C = O(n)
//S.C = O(n)

