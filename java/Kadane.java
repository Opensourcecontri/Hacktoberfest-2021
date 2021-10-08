class Kadane{
    
    int maxSubarraySum(int arr[], int n){
        int maxSum = arr[0];
        int currSum = arr[0];
        for(int i = 1; i < n ; i++) {
            currSum = Math.max(currSum + arr[i], arr[i]);
            maxSum = Math.max(currSum, maxSum);
        }
        return maxSum;
    }
    
}
