#include <bits/stdc++.h>
using namespace std;
int eggDropPuzzle(int eggs, int floors,vector<vector<int>>&dp)
{
    if(dp[eggs][floors]!=-1)
    {
        return dp[eggs][floors];
    }
    
    if(floors==0 || floors==1 || eggs==1)
    {
        dp[eggs][floors]=floors;
        return dp[eggs][floors];
    }

    int var,mini = INT_MAX;

    for(int i=1;i<=floors;++i)
    {
        var = max(eggDropPuzzle(eggs-1,i-1,dp),eggDropPuzzle(eggs,floors-i,dp));
        mini = min(mini,var);
    }

    dp[eggs][floors]=mini+1;
    return mini+1;
}
int main()
{
    int eggs=2,floors=36;
    vector<vector<int>>dp(eggs+1,vector<int>(floors+1,-1));
    cout<<eggDropPuzzle(2,36,dp)<<endl;
    return 0;
}