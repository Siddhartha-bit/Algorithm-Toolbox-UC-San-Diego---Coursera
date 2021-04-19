#include <iostream>
using namespace std;

int Minfuel(long arr[],int max_dist,int n)
{
    int current=0;
    int laststop;
    int num_refills=0;
    while(current <= n)
    {
        laststop=current;
        while(current <=n && (arr[current+1]-arr[laststop])<=max_dist)
        {
            current=current+1;
        }
        if(current==laststop)
        {
            return -1;
        }
        if(current<=n)
        {
            num_refills=num_refills+1;
        }
    }
    return num_refills;
}


int main()
{
  long d;
  int max_dist;
  int n;
  cin>>d;
  cin>>max_dist;
  cin>>n;
  long arr[n+2];
  arr[0]=0;
  arr[n+1]=d;
  for(int i=1;i<n+1;i++)
  {
      cin>>arr[i];
  }
  int total_refills=Minfuel(arr,max_dist,n);
  cout<<total_refills<<endl;
  return 0;
}
