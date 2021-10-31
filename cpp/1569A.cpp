#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        int flag=0;
        cin>>n;
        char s[n];
        cin>>s;
        for(int i=0;i<=n;i++)
        {
            //cout<<s[i]<<endl;
            if((s[i]=='a'&& s[i+1]=='b')|| s[i]=='b'&&s[i+1]=='a')
            {
               cout<<i+1<<" "<<i+2<<endl;
               flag=1;
               break;
            }
        }
        if(flag==0)
        cout<<"-1"<<" "<<"-1"<<endl;
    }
}