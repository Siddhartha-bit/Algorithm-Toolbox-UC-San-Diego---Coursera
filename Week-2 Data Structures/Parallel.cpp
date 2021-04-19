#include <iostream>
#include <utility>
#include <algorithm>
#define ll long long
using namespace std;

int parent(int n)
{
    return (n-1)/2;
}

bool mycmp(pair<int,ll> a, pair<int,ll> b)
{
    if(a.second==b.second)
    {
        return a.first<b.first;
    }
}
void heapifyd(pair<int,ll> finish[],int i,int n)
{
    int minimum=i;
    int l=2*i+1;
    int r=2*i+2;
    
    if(l<n && finish[minimum].second>finish[l].second)
    {
        minimum=l;
    }
    if(l<n && finish[minimum].second==finish[l].second)
    {
        if(finish[minimum].first>finish[l].first)
        {
            minimum=l;
        }
    }
    if(r<n && finish[minimum].second>finish[r].second)
    {
        minimum=r;
    }
    
    if(r<n && finish[minimum].second==finish[r].second)
    {
        if(finish[minimum].first>finish[r].first)
        {
            minimum=r;
        }
    }
    if(minimum!=i)
    {
        swap(finish[i],finish[minimum]);
        if(finish[l].second==finish[r].second)
        {
            if(finish[l].first>finish[r].first)
            {
                swap(finish[l],finish[r]);
            }
        }
        
        heapifyd(finish,minimum,n);
    }
}

void heapdelete(pair<int,ll> finish[],int &n)
{
    finish[0]=finish[n-1];
    n=n-1;
    heapifyd(finish,0,n);
}

void heapifyi(pair<int,ll> finish[], int i,int n)
{
    int paren=parent(i);
    
    if(finish[i].second<finish[paren].second)
    {
        swap(finish[i],finish[paren]);
        heapifyi(finish,paren,n);
    }
}

void insert(pair<int,ll> finish[], int &n,int k1,int k2)
{
    n=n+1;
    finish[n-1].first=k1;
    finish[n-1].second=k2;
    
    heapifyi(finish,n-1,n);
}



int main()
{
    int n;
    int m;
    cin>>n;
    cin>>m;
    int h1=0,h2=0;
    ll times[m];
    for(int i=0;i<m;i++)
    {
        cin>>times[i];
    }
    pair<int,ll> finish[n];
    pair<int,ll> output[m];
    int i=0;
    if(m<n)
    {
        for(i=0;i<m;i++)
        {
            output[i].first=i;
            output[i].second=0;
            finish[i].first=i;
            finish[i].second=times[i];
        }
    }
    
    else
    {
        for(i=0;(i<n && m>=n);i++)
        {
            output[i].first=i;
            output[i].second=0;
            finish[i].first=i;
            finish[i].second=times[i];
        }
    }
    for(int j=parent(i-1);j>=0;j--)
    {
        heapifyd(finish,j,n);
    }
    
    for(int j=i;j<m;j++)
    {
        pair<int,ll> p=finish[0];
        heapdelete(finish,n);
        output[j].first=p.first;
        output[j].second=p.second;
        insert(finish,n,p.first,(p.second+times[i]));
    }
    
    for(int l=0;l<m;l++)
    {
        cout<<output[l].first<<" "<<output[l].second<<endl;
    }

    return 0;
}
