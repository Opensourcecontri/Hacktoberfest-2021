#include<bits/stdc++.h>
using namespace std;
 
int main()
{
   int t,a,b,c;
   cin>>t;
   while(t--)
   {
       cin>>a>>b>>c;
       int total = a+(b*2)+(3*c);
       int min = total /2;
       int ans = total-min;
       cout<<abs(ans-min)<<endl;
   }
}