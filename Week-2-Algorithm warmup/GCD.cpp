#include<iostream>
using namespace std;
long long GCD(long long a, long long b)
{
    if(b==0)
    {
        return a;
    }
    GCD(b,a%b);
}
int main()
{
    long long a,b;
    cin>>a>>b;
    long long c=GCD(a,b);
    cout<<c<<endl;
    return 0;
}