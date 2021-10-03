//c++ program to find the all the maximum of all the subarray of size k in an array by sliding window maximum method.
#include<bits/stdc++.h>
using namespace std;
void printKmax(int arr[], int n, int k)
{
    std::deque<int> dq(k);

    int i;

    for (i = 0; i < k; i++)
    {
        // For every element, the previous smaller elements are useless so 
        // remove them from Qi 

        if ((!dq.empty()) && arr[i]<=arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for ( ; i < n; i++)
    {
        cout << arr[dq.front()] << " ";

        // Remove the elements which are out of this window
        while ((!dq.empty()) && dq.front()<=i-k)
        {
            dq.pop_front();
        }

        while ((!dq.empty()) && arr[i]>=arr[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);
        }
         // Print the maximum element of last window 
        cout << arr[dq.front()];
}
int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,1,4,5,2,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printKmax(arr, n, k);

    return 0;
}

