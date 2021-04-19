#include <iostream>
using namespace std;

int findcoins(int m)
{
    int coins=0;
    if(m>=10)
    {
        coins=coins+m/10;
        m=m%10;
    }
    
    if(m>=5 and m<10)
    {
        coins=coins+m/5;
        m=m%5;
    }
    
    if(m<5 and m>0)
    {
        coins+=m;
    }
    return coins;
}
int main()
{
    int n;
    cin>>n;
    int ans=findcoins(n);
    cout<<ans<<endl;
}