#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
#define ll long long

class point
{
    public:
    ll fir;
    ll sec;
};
bool mycmp(pair<ll,int> &a, pair<ll,int> &b)
{
    if(a.first==b.first)
    {
        return a.second<b.second;
    }
    return a.first<b.first;
}

void PointsAndSegments(vector<point> a, vector<ll> points)
{
    vector<pair<ll,int>> output;
    for(ll i=0;i<a.size();i++)
    {
        output.push_back(make_pair(a[i].fir,1));
        output.push_back(make_pair(a[i].sec,3));
    }
    for(ll i=0;i<points.size();i++)
    {
        output.push_back(make_pair(points[i],2));
    }
    ll n1=points.size();
    
    unordered_map<ll,ll> final;
    sort(output.begin(),output.end(),mycmp);
    
    ll count=0;
    for(ll i=0;i<output.size();i++)
    {
       
        if(output[i].second==1)
        {
            count++;
        }
        if(output[i].second==3)
        {
            count--;
        }
        if(output[i].second==2)
        {
            final[output[i].first]=count;
        }
    }
    for(ll i=0;i<points.size();i++)
    {
        cout<<final[points[i]]<<" ";
    }
}

int main()
{
    ll s;
    cin>>s;
    ll p;
    cin>>p;
    vector<ll> points(p);
    vector<point> a(s);
    for(ll i=0;i<a.size();i++)
    {
        cin>>a[i].fir>>a[i].sec;
    }
    for(ll i=0;i<p;i++)
    {
        cin>>points[i];
    }
    PointsAndSegments(a,points);
    return 0;
}
