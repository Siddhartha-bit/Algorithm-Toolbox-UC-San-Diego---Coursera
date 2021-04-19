#include <iostream>
using namespace std;
#define ll long long

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

ll Lastofmn(ll n1,ll n2)
{
    int sum=0;
    ll f0=0,f1=1,current=0;
    if(n1==0 && (n2==1 || n2==0) )
    {
         return n2;
    }
    for(int i=2;i<n1;i++)
    {   
        current=(f0+f1)%10;
        f0=f1;
        f1=current;
    }
    
    for(int i=n1;i<=n2;i++)
    {
        if(n1==0)
        {            
            i=i+2;
            n1=n1+2;
            sum++;
        }
        if(n1==1)
        {
            i=i+1;
            n1++;
            sum++;
        }
        current=(f0+f1)%10;
        f0=f1;
        f1=current;
        sum=(sum+current)%10;
    }
    return sum;  
}

int main()
{
    ll m,n;
    cin>>m>>n;
    ll c=pisano(10);
    ll m1=m%c;
    ll m2=n%c;
    if(m1<=m2)
    {
        ll sum1=Lastofmn(m1,m2);
        cout<<sum1<<endl;
    }
    else
    {
       ll sum1=Lastofmn(m1,m1+m2+1);
       cout<<(sum1)%10<<endl;
    }
    
    return 0;
}
