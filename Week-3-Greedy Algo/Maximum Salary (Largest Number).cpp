#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 


int myCompare(string X, string Y) 
{ 
	
	string XY = X+(Y); 
	string YX = Y+(X); 
    return XY>YX;
}


void findmax(vector<string> v)
{
    sort(v.begin(), v.end(), myCompare); 
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
    }
}

int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    findmax(v);
    return 0;
}
