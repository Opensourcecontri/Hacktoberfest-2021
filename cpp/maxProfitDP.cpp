#include<bits/stdc++.h>
using namespace std;

//ap-1
int maxProfit1(int * arr, int totalLen){
    if(totalLen== 0) return 0;

    int best =0;
    for(int len =1; len <= totalLen; len++){
        int netProfit = arr[len] + maxProfit1(arr, totalLen-1);
        best = max(best, netProfit);
    }
    return best;
}

//ap-2 --> memoization

int memo[1000];

int maxProfit(int * arr, int totalLen){
    if(totalLen==0) return 0;

    if(memo[totalLen]!=-1) return memo[totalLen];

    int best = 0;
    for(int len =1; len<=totalLen; len++){
        int netProfit = arr[len] + maxProfit(arr, totalLen-len);
        best = max(best, netProfit);
    }
    memo[totalLen]=best;
    return best;
}

//dp
int mazProfit_bu(int *arr, int totalLen){
    int dp[100]={};
    
    for(int len =1; len<= totalLen; len++){
        int best =0;
        for(int cut=1; cut<=len; cut++){
            best = max(best, arr[cut] + dp[len-cut]);
        }
        dp[len]=best;
    }
    return dp[totalLen];
}

int main(){
    int priceOfeachLen[100];
    int totalLen;
    cin>>totalLen;
    for(int i=1; i<=totalLen; i++){
        cin>>priceOfeachLen[i];
    }
    for(int i=0; i<=totalLen; i++){
        memo[i]=-1;
    }
    // int ans = maxProfit(priceOfeachLen, totalLen);
    int ans = mazProfit_bu(priceOfeachLen, totalLen);
    cout<<ans;
    return 0;
}