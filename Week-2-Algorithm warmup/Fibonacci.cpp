#include <iostream>
using namespace std;
void Fib(int n)
{ 
    int arr[n+1];
    arr[0]=0;
    arr[1]=1; 
    if(n==0 || n==1)
    {
        cout<<n<<endl;
        return;
    }
    else
    {
     for(int i=2;i<n+1;i++)
     {
         arr[i]=arr[i-1]+arr[i-2];
     }
    }
 
    cout<<arr[n]<<endl;
}

int main()
{
    int n;
    cin>>n;
    Fib(n);
    return 0;
}