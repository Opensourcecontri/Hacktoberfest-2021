#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    char S[50];
    cin>>t;
    while(t--)
    {
        int acount=0,bcount=0,ccount=0;
        cin>>S;
        for(int i=0;i<strlen(S);i++)
        {
            if(S[i]=='A') acount++;
            if(S[i]=='B') bcount++;
            if(S[i]=='C') ccount++;
     }
     if(acount+ccount==bcount) cout<<"YES"<<endl;
     else 
     cout<<"NO"<<endl;
 
    }
}