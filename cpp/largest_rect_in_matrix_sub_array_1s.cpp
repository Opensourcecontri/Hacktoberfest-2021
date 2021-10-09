#include <bits/stdc++.h>
using namespace std;
int findLargestRectInHist(vector<int>&a)
{
    int n = a.size(),max_area=INT_MIN,i=0;
    stack<int>s;
    while(i<n)
    {
        if(s.empty() || a[s.top()]<=a[i])
        {
            s.push(i++);
        }
        else
        {
            while(!s.empty() && a[s.top()]>a[i])
            {
                int top = s.top();
                s.pop();
                int area = a[top]*(s.empty() ? i:i- s.top() -1);
                max_area = max(max_area,area);
            }
            
        }
    }
    while(!s.empty())
    {
         int top = s.top();
         s.pop();
         int area = a[top]*(s.empty() ? i:i-s.top()-1);
         max_area = max(max_area,area);
    }
    return max_area;
}
int main()
{
    vector<vector<int>>arr={ { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 }};
    
    vector<vector<int>>col(arr.size(),vector<int>(arr[0].size(),0));
    for(int i=0;i<arr[0].size();++i)
    {
        col[0][i]=arr[0][i];
    }
    for(int i=1;i<arr.size();++i)
    {
        for(int j=0;j<arr[0].size();++j)
        {
            if(arr[i][j])
            {
                col[i][j]=1+col[i-1][j];
            }
        }
    }
    int max_area=INT_MIN;
    for(int i=0 ; i < arr.size() ;++i)
    {
        max_area = max(max_area,findLargestRectInHist(col[i]));
    }
    cout<<"Largest Rectangle Area : "<<max_area<<endl;
    return 0;
}