#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{   
    long long n;
    cin>>n;
    long long count=0;
    vector<long long> v;
    long long sum=0;
    v.push_back(0);
    long long i=1;
    while(sum+i<=n)
    {
        sum+=i;
        v.push_back(i);
        count=count+1;
        i=i+1;
    }
    long long n1=n-sum;
    v[count]+=n1;
    cout<<count<<endl;
    for(long j=1;j<count+1;j++)
    {
        cout<<v[j]<<" ";
    }
    return 0;
}
