#include <iostream>
using namespace std;

int main()
{
     int m, n;
     cout << "Enter the rows and coloumn size: ";
     cin >> m >> n;
     cout << "Enter the elements of matrix: " << endl;
     int array[m][n], transpose[n][m];
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               cin >> array[i][j];
          }
     }

     for (int i = 0; i < m; i++)
     {
          for (int j = 0; j < n; j++)
          {
               transpose[j][i] = array[i][j];
          }
     }
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               cout << transpose[i][j] << " ";
          }
          cout << endl;
     }
}
