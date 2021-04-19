#include <iostream>
using namespace std;
#define ll long long 


void Fib(long long n)
{
    ll f0=0;
    ll f1=1;
    ll current=0;
    if(n==0)
    {
        cout<<0;
        return;
    }
    for(ll i=2;i<=n;i++)
    {
        current=(f0+f1)%10;
        f0=f1;
        f1=current;
    }
    ll sum=f1*(f1+f0);
    sum=sum%10;
    cout<<sum<<endl;
}

ll pisano(ll m)
{
    ll d;
    ll f0=0;
    ll f1=1;
    ll current=0;
    if(m==1)
    {
        return m;
    }
    for(ll i=2;i<m*m;i++)
    {
        current=(f0+f1)%m;
        f0=f1;
        f1=current;
        if(f0==1 && f1==0)
        {
            d=i;
            return d;
        }
    } 
}

int main()
{
    long long int n;
    cin>>n;
    ll n1=pisano(10);
    n=n%n1;
    Fib(n);
    return 0;
}