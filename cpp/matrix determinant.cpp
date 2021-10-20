#include<iostream>
#include<algorithm>
#include<cmath>
#define fr(i,n) for(int i=0;i<n;i++)
#define pr cout<<
#define en <<endl
#define sp <<' '
#define MOD 998244353
using namespace std;
typedef long long ll;

ll mat[31][31],adj[31][31],N;

int modInv(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1, t;
    while (a > 1)
    {
        // Update y and x
        t = y;
        y = x - (a/m0) * y;
        x = t;
        t = m0;
        // m is remainder now, process same as Euclid's algo
        m0 = a % m0;
		a = t;
    }
    if (x < 0)
       x += m;
    return x;
}

int determinantOfMatrix(ll mat[31][31],int n)   
{   
    ll num1,num2,det = 1,index,total = 1;   
	
    for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			num1 = mat[i][i];
			num2 = mat[j][i];
			for(int k = i; k < n; k++)
			{
				mat[j][k] = ((num1 * mat[j][k]) - (num2 * mat[i][k]))%MOD;
			}
			total = (total * num1)%MOD;
		}
	}  
    for(int i = 0; i < n; i++)
    {   
        det =( det * mat[i][i])%MOD;
    }
	// pr det sp<<total sp<<modInv(total,MOD) en;
	if(total<0)
	{
		total=-total;
		det=-det;
	}
    return (det*modInv(total,MOD))%MOD;
}

main()
{
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	fr(i,n)fr(j,n)
		cin>>mat[i][j];
	
	pr determinantOfMatrix(mat,n);
	
	
}


