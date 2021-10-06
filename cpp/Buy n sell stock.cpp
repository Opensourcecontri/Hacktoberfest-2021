#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& p) {
        int mini = INT_MAX;
        int profit = 0;
        for(int i=0; i<p.size(); i++) {
            mini = min(mini, p[i]);
            int temp = p[i] - mini;
            profit = max(profit, temp);
        }
        return profit;
    }
int main() 
{
    int n,x;
    cin>>n;
    vector<int> p;
    for(int i=0; i<n; i++)
    {cin>>x;
    p.push_back(x);}
    cout<<"Maximum profit earned is "<<maxProfit(p);
    return 0;
}