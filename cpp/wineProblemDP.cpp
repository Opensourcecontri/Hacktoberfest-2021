#include<bits/stdc++.h>
using namespace std;

// APPROACH 1 -- GREEDY
int profit(int *bottles, int n){
    int year=1, profit=0;
    for(int i=0; i<n;){
        if(bottles[i]<bottles[n-1]){
            profit=profit+ year*bottles[i];
            i++;
            year++;
        }
        else{
            profit = profit + year*bottles[n-1];
            n--;
            year++;
        }
    }
    return profit; //this is the greedy approach of the solution
}

//APPROACH 2 
int cnt=0;
int maxProfit(int arr[], int be, int en, int year){
    if(be>en){
        return 0;
    }

    int q1 = arr[be] * year + maxProfit(arr, be+1, en, year+1);
    int q2 = arr[en] * year + maxProfit(arr, be, en-1, year+1);
    int ans = max(q1,q2);
    return ans;
}

//APPROACH -3
int memo[100][100];
int maxProfit3(int arr[], int be, int en, int year){
    ++cnt;
    if(be>en){
        return 0;
    }
    
    if(memo[be][en]!=-1) return memo[be][en];

    int q1 = arr[be] * year + maxProfit3(arr, be+1, en, year+1);
    int q2 = arr[en] * year + maxProfit3(arr, be, en-1, year+1);
    int ans = max(q1,q2);
    memo[be][en] = ans;
    return ans;
}

//APPROACH - 4 DP
int maxProfitDP(int *arr, int n){
    int dp[100][100]={};
    int year = n;
    for(int i=0; i<n; i++){
        dp[i][i]= year * arr[i];
    }
    year--;

    for(int len=2; len<=n; len++){
        int srt =0;
        int end = n-len;
        while(srt<=end){
            int endwindow = srt+ len -1;
            dp[srt][endwindow]= max(
                arr[srt]*year + dp[srt+1][endwindow],
                arr[endwindow]*year + dp[srt][endwindow-1]
        );
            srt++;
        }
        year--;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<setw(3)<< dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return dp[0][n-1];
}

int main(){
    // int bottles[]={1,4,2,3};
    // int ans = profit(bottles, 4);
    int arr[100];
    int n; cin>>n; //no of bottles
    for(int i=0; i<n; i++){
        cin>>arr[i]; //price of the bottles
    }
    // int ans = maxProfit(arr, 0,n-1,1);
    // ap-3 memo
    // cnt = 0;
    // memset(memo, -1, sizeof(memo));
    // int ans = maxProfit3(arr, 0, n-1, 1);
    // ap-4 dp
    int ans = maxProfitDP(arr, n);
    cout<<ans<<"\n"; 
    // cout<<cnt;
    return 0;
}