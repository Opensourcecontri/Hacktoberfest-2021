
// Calculate the a to the power b

// Naive Approach


#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,x=0;
    cin>>a>>b;
    x = pow(a,b);
    cout<<x<<endl;
    return 0;
}




// Better Approach 
#include <bits/stdc++.h>
using namespace std;
int main()
{
        long long int a,b,m,x,y = 1,ans=1;
        m = 1000000007;
        cin>>a>>b;
        x = b;
        while(x){
            if(x%2==0){
                a = a*a%m;
                x /= 2;
            }
            else{
                y = y*a%m;
                x = x-1;
            }
        }
        cout<<y<<endl;
    return 0;
}
