#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long 
using namespace std;

int main()
{
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<v.size();i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll count=1;
    ll max=0;
    for(ll i=0;i<v.size();i++)
    {
        if(v[i-1]==v[i])
        {
            count++;
            if(max<count)
            {
                max=count;
            }
        }
        else
        {
          count=1;  
        }
    }
    (max>n/2)?cout<<1:cout<<0;
}