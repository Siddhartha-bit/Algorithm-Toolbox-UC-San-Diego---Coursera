#include <bits/stdc++.h>
using namespace std;
#define ll long long 
class Item
{
    public:
    ll value;
    ll weight;
};

bool cmp(Item a,Item b)
{
  double r1=(double)a.value/a.weight;
  double r2=(double)b.value/b.weight;
  return r1>r2;
}

double knapsack(Item arr[],int N,ll W)
{
    sort(arr,arr+N,cmp);
    double final_val=0;
    int currentWeight=0;
    for(int i=0;i<N;i++)
    {
        if(currentWeight+arr[i].weight<=W)
        {
            currentWeight=currentWeight+arr[i].weight;
            final_val=final_val+arr[i].value;
        }
        else 
        {
            ll rem_weight=W-currentWeight;
            final_val+=(arr[i].value)*((double)rem_weight/arr[i].weight);
            break;
        }
        
    }
    return final_val;
}

int main()
{
    int N;
    ll W;
    cin>>N>>W;
    Item arr[N];
    for(int i=0;i<N;i++)
    {
     cin>>arr[i].value>>arr[i].weight;   
    }
    double value=knapsack(arr,N,W);
    cout<<fixed<<setprecision(4)<<value<<endl;
}