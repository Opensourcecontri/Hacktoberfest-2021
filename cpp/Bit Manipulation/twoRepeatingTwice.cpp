#include <bits/stdc++.h>
using namespace std;

int setBit(int n, int pos)
{
     return ((n & (1 << pos)) != 0);
}

void twoUnique(int arr[], int n) //step 1
{
     int res = 0;
     for (int i = 0; i < n; i++)
     {
          res = res ^ arr[i];
     }

     int setbit = 0;    // for rightmost bit (1)
     int pos = 0;       // storing the ith pos
     int tempres = res; // this is when u get one value and u xor with that value to eliminate the duplicate to get second

     // 3 ^ 2 = 1 checking for 1
     while (setbit != 1)
     {
          setbit = res & 1; //for lastbit
          pos++;
          res = res >> 1; // right shift if not  1 at last digit
     }

     int newres = 0; // for first unique no
     for (int i = 0; i < n; i++)
     {
          // setBit in build function this is collecting the 1 at given pos in one side and xor with them
          if (setBit(arr[i], pos - 1))
          {
               //why pos 1 bcz at end we are pos++
               newres = newres ^ arr[i];
          }
     }

     cout << newres << endl;
     cout << (tempres ^ newres) << endl; // for getting the second number 3 ^ 2 ^ (2)
}

int main()
{
     int arr[8] = {5, 4, 1, 4, 3, 5, 1, 2};
     twoUnique(arr, 8);
     return 0;
}
