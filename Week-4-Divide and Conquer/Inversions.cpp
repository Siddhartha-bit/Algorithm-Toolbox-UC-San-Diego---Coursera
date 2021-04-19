#include <iostream>
using namespace std;
#define ll long long

int Merge(ll arr[], int low, int mid, int high)
{
    int count=0;
    int n1=mid-low+1;
    int n2=high-mid;
    
    ll L[n1],R[n2];
    
    for(ll i=0;i<n1;i++)
    {
        L[i]=arr[low+i];
    }
    for(ll j=0;j<n2;j++)
    {
        R[j]=arr[mid+1+j];
    }
    ll i=0;
    ll j=0;
    ll k=low;
    while(i<n1 && j<n2)
    {
      
      if(L[i]<=R[j])
      {
          arr[k]=L[i];
          i++;
      }
      else
      {
          arr[k]=R[j];
          j++;
          count=count+mid-i+1;
      }
      k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
    return count;
}

int MergeSort(ll a[], int low, int high)
{
    int finalcount=0;
    if(low<high)
    {
        int mid=(high+low)/2;
        
        int cx=MergeSort(a,low,mid);
        int cy=MergeSort(a,mid+1,high);
        int fxy=Merge(a,low,mid,high);
        finalcount=(fxy+cx+cy);
    }
    return finalcount;
}

int main()
{
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int Total_inversions=MergeSort(arr,0,n-1);
    cout<<Total_inversions<<endl;
    return 0;
}