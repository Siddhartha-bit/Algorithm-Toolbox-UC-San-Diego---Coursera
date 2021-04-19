#include <iostream>
using namespace std;
#define ll long long

int Merge(ll arr[], ll temp[],int low, int mid, int high)
{
    int count=0;
    int i,j,k;
    
    i=low;
    j=mid;
    k=low;
    
    while ((i <= mid - 1) && (j <= high)) 
    { 
        if (arr[i] <= arr[j]) 
        { 
            temp[k++] = arr[i++]; 
        } 
        else 
        { 
            temp[k++] = arr[j++]; 
            count = count + (mid - i); 
        } 
    } 
  
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
 
    while (j <= high) 
        temp[k++] = arr[j++]; 
  
    for (i = low; i <= high; i++) 
        arr[i] = temp[i]; 
  
    return count; 
}

int MergeSort(ll a[], ll temp[], int low, int high)
{
    int finalcount=0;
    if(low<high)
    {
        int mid=(high+low)/2;
        
        int cx=MergeSort(a,temp,low,mid);
        int cy=MergeSort(a,temp,mid+1,high);
        int fxy=Merge(a,temp,low,mid,high);
        finalcount=fxy+cx+cy;
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
    ll temp[n];
    int Total_inversions=MergeSort(arr,temp,0,n-1);
    cout<<Total_inversions<<endl;
    return 0;
}