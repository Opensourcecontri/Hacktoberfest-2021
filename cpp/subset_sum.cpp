#include<bits/stdc++.h>
using namespace std;


bool found = false;

int subSetSum(vector<int> vec, int sum, int N, int currSum){
    cout<<currSum<<endl;

    if(currSum == sum){
        return sum;
    }


    if(N == 0){
        if(vec[N] == sum){
            return sum;
        }
        return -1;
    }

    if(vec[N] <= sum){
        sum = sum - vec[N-1];
    }

   currSum = vec[N-1] + subSetSum(vec, sum, N-1, currSum);
   currSum =  subSetSum(vec, sum, N-1, currSum) ;
    
}

int main(){
    vector<int> vect = {3, 34, 3, 12, 5, 2};
    int sum= 9;

   int res = subSetSum(vect, sum, vect.size(),0);

    if(res != -1){
        cout<<"found"<<endl;
    }else{
        cout<<"not found"<<endl;
    }

}