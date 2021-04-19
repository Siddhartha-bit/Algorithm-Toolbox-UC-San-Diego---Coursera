#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
  
void swap(ll *a, ll *b) 
{ 
    ll temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  

void printarr(ll a[], ll n) 
{ 
    for (int i = 0; i < n; ++i) 
    {
        cout<<a[i]<<" ";
    }
} 

void partition(ll a[], ll low, ll high, ll &i, ll &j) 
{ 
    
    if (high - low <= 1) 
    { 
        if (a[high] < a[low]) 
            swap(&a[high], &a[low]); 
        i = low; 
        j = high; 
        return; 
    } 
  
    ll mid = low; 
    ll pivot = a[high]; 
    while (mid <= high) 
    { 
        if (a[mid]<pivot) 
            swap(&a[low++], &a[mid++]); 
        else if (a[mid]==pivot) 
            mid++; 
        else if (a[mid]>pivot) 
            swap(&a[mid], &a[high--]); 
    } 
  
 
    i = low-1; 
    j = mid; 
} 
  

void RandomizedQuickSort(ll a[], ll low, ll high) 
{ 
    if (low>=high) 
        return; 
  
    ll i, j; 
    partition(a, low, high, i, j); 
    RandomizedQuickSort(a, low, i); 
    RandomizedQuickSort(a, j, high); 
} 
  

int main() 
{ 
    ll n;
    cin>>n;
    ll a[n];
    ll size =n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    RandomizedQuickSort(a, 0, size - 1); 
    printarr(a, size); 
    return 0; 
} 