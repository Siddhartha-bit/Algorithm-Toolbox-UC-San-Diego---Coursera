#include <iostream>
using namespace std;
#define ll long long int 

long long GCD(long long a,long long b)
{
  if(b==0)
  {
      return a;
  }
  GCD(b,a%b);
}
int main()
{
    long long a;
    long long b;
    cin>>a>>b;
    long long int c=GCD(a,b);
    long long d=(a*b)/c;
    cout<<d<<endl;
    return 0;
}
