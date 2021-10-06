#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll int n;
    cin>>n;
    ll int v[n];
    for(ll int i=0;i<n;i++)
    cin>>v[i];
    if(n>1)
    {
        ll int f[n],b[n],ans[n],m=LONG_LONG_MAX;
        f[0]=v[0];
        b[n-1]=v[n-1];
        for(ll int i=1;i<n;i++)
        {                                   // finding out array f(front) and b(back)
            f[i]=__gcd(f[i-1],v[i]);
            b[n-1-i]=__gcd(b[n-i],v[n-1-i]);
        }
        ll sum = 0;
        for(ll int i=0;i<n;i++)             // sum of all the elements in an array
        sum+=v[i];
        ans[0]=b[1];                        // set up initial condition of the array
        ans[n-1]=f[n-2];                    // set up final condition of the array
        for(int i=1;i<(n-1);i++)
        ans[i]=__gcd(f[i-1],b[i+1]);        // find out GCD of all the numbers except one
        ll int tmp = LONG_LONG_MAX,tmp2;
        for(ll int i=0;i<n;i++)
        {
            tmp2 = (sum - v[i])/ans[i];
            tmp=min(tmp2,tmp);              // finding minimum number of notes required
        }
        cout<<tmp+1;
    }
    else
    cout<<"1";                              // if a single element is present the the number of notes required will be 1
    cout<<"\n";
}
int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
