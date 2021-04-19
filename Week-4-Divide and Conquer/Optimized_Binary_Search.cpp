#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long

ll binary_search(vector<ll> input, ll key, ll low, ll high)
{
    ll mid;
    while(high-low>1)
    {
        mid=low+(high-low)/2;
        if(input[mid]<=key)
        {
            low=mid;
        }
        else
        {
            high=mid;
        }
    }
        if(input[low]==key)
        {
            return low;
        }
        else if(input[high]==key)
        {
            return high;
        }
        else
        {
            return -1;
        }
    
   
}


void binary(vector<ll> input, vector<ll> search,ll low, ll high)
{
    for(ll i=0;i<search.size();i++)
    {
        search[i]=binary_search(input,search[i],low,high);
    }
    for(ll i=0;i<search.size();i++)
    {
        cout<< search[i]<<" "; 
    }
}

int main()
{
    ll n;
    cin>>n;
    vector<ll> input(n);
    for(ll i=0;i<input.size();i++)
    {
        cin>>input[i];
    }
    ll k;
    cin>>k;
    vector<ll> search(k);
    for(ll i=0;i<search.size();i++)
    {
        cin>>search[i];
    }
    binary(input,search,0,n-1);
    
}