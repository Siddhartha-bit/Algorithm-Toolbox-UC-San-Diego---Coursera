#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

bool cmp(ll a,ll b)
{
    return a>b;
}

ll MaxRevenue(ll a[],ll b[],int n)
{
    sort(a,a+n,cmp);
    sort(b,b+n,cmp);
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i]*b[i];
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;
    ll a[n];
    ll b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    ll TotalRevenue=MaxRevenue(a,b,n);
    cout<<TotalRevenue<<endl;
    return 0;
}