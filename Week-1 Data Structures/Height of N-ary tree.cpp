#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int fillheight(int arr[],int p,int height[],int visited[])
{
    
    if(visited[p])
    {
        return height[p];
    }
    
    
    if(arr[p]==-1)
    {
        visited[p]=1;
        height[p]=1;
        return height[p];
    }
    
    
    visited[p]=1;
    height[p]=1+fillheight(arr,arr[p],height,visited);
    return height[p];
}

int findheight(int arr[],int n)
{
    int max_height=0;
    int height[n];
    int visited[n];
    
    memset(visited,0,sizeof(visited));
    memset(height,0,sizeof(height));
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            height[i]=fillheight(arr,i,height,visited);
        }
        max_height=max(max_height,height[i]);
    }
   return max_height; 
}

int main()
{
    int n;
    cin>>n;
    int in_tree[n];
    for(int i=0;i<n;i++)
    {
        cin>>in_tree[i];
    }
    int Total_height=findheight(in_tree,n);
    cout<<Total_height<<endl;
    return 0;
}
