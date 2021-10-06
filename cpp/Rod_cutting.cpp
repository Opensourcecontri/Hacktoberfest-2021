#include <bits/stdc++.h>
using namespace std;
//Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if the length of the rod is 8 and the values of different pieces are given as the following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

//Unbound Knapsack-DP Approach
int maxcostdp(int n,int price[],int length[])
{
    int dp[n+1][n+1];

    //Initialisation
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    {if(i==0 || j==0) 
    dp[i][j] =0;
    }

    //Main solution
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)

    {if (length[i-1]<=j)
      dp[i][j] = max(price[i-1]+dp[i][j-length[i-1]], dp[i-1][j]);

    else 
      dp[i][j] = dp[i-1][j];
    }
    return dp[n][n];
}

int main()
{
    int n;
    //max length of rod
    cin>>n;
    int price[n];
    //assuming price is given for each length
    for(int i=0;i<n;i++)
    cin>>price[i];
    // price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int length[n];
    for (int i = 0; i < n; i++)
    {
        length[i] = i + 1;
    }

    // Function Call
    cout << "Maximum obtained value  is "
         << maxcostdp(n,price, length) << endl;
    return 0;
}
