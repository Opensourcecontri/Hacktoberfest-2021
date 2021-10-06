#include <bits/stdc++.h>
using namespace std;

void primeFactor(int n)
{

     int spf[n + 1] = {0};

     for (int i = 2; i <= n; i++)
     {
          spf[i] = i; // sabhi no. ko uska khudka prime factor de dena
     }

     for (int i = 2; i * i <= n; i++)
     {
          if (spf[i] == i)
          {
               for (int j = 2 * i; j <= n; j += i)
               {
                    if (spf[j] == j)
                    {
                         spf[j] = i;
                    }
               }
          }
     }

     while (n != 1)
     {
          cout << spf[n] << " ";
          n = n / spf[n];
     }
}
int main()
{
     int n;
     cin >> n;
     primeFactor(n);

     return 0;
}
