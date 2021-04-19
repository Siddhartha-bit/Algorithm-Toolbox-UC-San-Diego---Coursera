#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<long,long>> swaps;
int count=0;


void heapify(long input[], int n, int l)
{
    int minimum=l;
    int r=2*l+1;
    int q=2*l+2;
  
  
    if(r<n && input[minimum]>input[r])
    {
        minimum=r;
    }
    if(q<n && input[minimum]>input[q])
    {
        minimum=q;
    }
    if(minimum!=l)
    {
        swap(input[l],input[minimum]);
        count++;
        swaps.push_back(make_pair(l,minimum));
        heapify(input,n,minimum);
    }
    
    
}

int main()
{
    int n;
    cin>>n;
    int j;
    int l;
    int k=0;
    long input[n];
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    for(l=(n/2)-1;l>=0;l--)
    {
        heapify(input,n,l);
    }
    cout<<count<<endl;
    for(int i=0;i<swaps.size();i++)
    {
       cout<<swaps[i].first<<" "<<swaps[i].second<<endl;
    }

    return 0;
}

