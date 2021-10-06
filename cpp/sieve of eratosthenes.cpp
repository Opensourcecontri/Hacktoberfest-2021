#include <bits/stdc++.h>
using namespace std;

void primeSieve(int n)
{
     int prime[n + 1] = {0};

     for (int i = 2; i * i <= n; i++)
     {
          if (prime[i] == 0)
          {
               for (int j = 2 * i; j <= n; j += i)
               {
                    prime[j] = 1;
               }
          }
     }

     // for (int i = 2; i <= n; i++)
     // {
     //      if (prime[i] == 0)
     //      {
     //           for (int j = i * i; j <= n; j += i)
     //           {
     //                prime[j] = 1;
     //           }
     //      }
     // }

     for (int i = 2; i <= n; i++)
     {
          if (prime[i] == 0)
          {
               cout << i << " ";
          }
          // cout << i << " " << prime[i]<<endl;
     }
     cout << endl;
}

int main()
{

     int n;
     cin >> n;

     primeSieve(n);

     return 0;
}
