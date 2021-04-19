#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define ll long long 

vector<ll> max_prizes(long long n,ll &count)
{
    ll n2=ceil(n/2);
    vector<ll> v;
    ll sum=0;
    v.push_back(0);
    for(ll i=1;i<n2+1;i++)
    {
        if(sum+i<=n)
        {
            sum+=i;
            v.push_back(i);
            count++;
        }
    }
    ll n1=n-sum;
    v[count]+=n1;
    
    return v;
    
}
int main()
{   
    ll n;
    cin>>n;
    ll count=0;
    vector<ll> v=max_prizes(n,count);
    cout<<count<<endl;
    for(long j=1;j<count+1;j++)
    {
        cout<<v[j]<<" ";
    }
    return 0;
}
