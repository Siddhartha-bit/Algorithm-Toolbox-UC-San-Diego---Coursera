#include <iostream>
using namespace std;
#define ll long long int 

long long pisano(ll m)
{
  ll d;
  ll f0=0;
  ll f1=1;
  ll current=0;
  if(m==1)
  {
      return m;
  }
  else
  {
      for(long long i=2;i<m*m;i++)
      {
          current=(f0+f1)%m;
          f0=f1;
          f1=current;
          if(f1==0 && f0==1)
          {
             d=i;
             return d;
          }
      }
  }
}

ll fib(ll n,ll m)
{
    ll c=pisano(m);
    n=n%c;
    ll f0=0;
    ll f1=1;
    ll current=0;
    if(n<=1)
    {
        return n;
    }
    for(ll i=2;i<n+1;i++)
    {
        current=(f0+f1)%m;
        f0=f1;
        f1=current;
    }
   return f1;
}
int main()
{
    long long a;
    long long b;
    cin>>a>>b;
    ll d=fib(a,b);
    cout<<d<<endl;
    return 0;
}
