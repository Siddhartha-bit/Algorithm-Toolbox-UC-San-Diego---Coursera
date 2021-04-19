#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void Maxwindowelement(vector<int> input, int n, int m)
{
    deque<int> Q;
    int i;
    
    for(i=0;i<m;i++)
    {
        while((!Q.empty()) && input[i]>=input[Q.back()])
        {
            Q.pop_back();
        }
        
        Q.push_back(i);
    }
    
    for(;i<n;i++)
    {
        cout<<input[Q.front()]<<" ";
        
        while((!Q.empty()) && Q.front()<=i-m)
        {
            Q.pop_front();
        }
        
        while((!Q.empty()) && input[i]>=input[Q.back()])
        {
            Q.pop_back();
        }
        
        Q.push_back(i);
    }
    
    cout<<input[Q.front()];
}

int main()
{
    int n;
    int m;
    cin>>n;
    vector<int> input(n);
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    cin>>m;
    Maxwindowelement(input,n,m);
    return 0;
}
