#include <iostream>
using namespace std;

int main()
{
    long long a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<min(min(min(a,b),c),d)<<endl;
    return 0;
}
