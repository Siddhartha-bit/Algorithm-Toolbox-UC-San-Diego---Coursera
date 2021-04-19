#include <iostream>
using namespace std;
void Fib(long long n)
{ 
    long long sum=0;
    long long d=0;
    long long arr[n+1];
    arr[0]=0;
    arr[1]=1; 
    if(n==0 || n==1) 
    {
        cout<<n<<endl;
        return;
    }
    else
    {
     for(long long  i=2;i<=n;i++)
     {
         arr[i]=(arr[i-1]+arr[i-2])%10;
         if(arr[i]==0 && arr[i-1]==1)
         {
             d=i;
             break;
         }
     }
    }
        for(long long i=0;i<n+1;i++)
        {
            sum=(sum+arr[i])%10;
        }
    cout<<sum<<endl;
}

int main()
{
    long long int n;
    cin>>n;
    if(n>=60)
    {
        n=n%60;
    }
    
    Fib(n);
    return 0;
}