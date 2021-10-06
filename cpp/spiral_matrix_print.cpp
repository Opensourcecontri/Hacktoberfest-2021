#include <iostream>
using namespace std;

int main()
{
     int m, n;
     cout << "Enter the rows and column for matrix: ";
     cin >> m >> n;
     cout << "Enter the elements of matrix: " << endl;
     int array[m][n];
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               cin >> array[i][j];
          }
     }
     int startrow = 0, endrow = n - 1, startcol = 0, endcol = m - 1;

     while (startrow <= endrow && startcol <= endcol)
     {
          for (int i = startcol; i <= endcol; i++)
          {
               cout << array[startrow][i] << " ";
          }
          startrow++;
          for (int i = startrow; i <= endrow; i++)
          {
               cout << array[i][endcol] << " ";
          }
          endcol--;
          for (int i = endcol; i >= startcol; i--)
          {
               cout << array[endrow][i] << " ";
          }
          endrow--;
          for (int i = endrow; i >= startrow; i--)
          {
               cout << array[i][startcol] << " ";
          }
          startcol++;
     }
}
