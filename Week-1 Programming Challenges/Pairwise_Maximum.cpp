#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define I -32767

void Max_pairwise_product(const vector<int> &numbers)
{ 
    long long  max=I;
    long long result;
    long long max2=I;
    int max_index1=-1;
    int max_index2=-1;
    int n=numbers.size();
    for(int i=0;i<n;i++)
    { 
        if(numbers[i]>max)
        {
            max=numbers[i];
            max_index1=i;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(numbers[i]>max2 && i!=max_index1)
        {
            max2=numbers[i];
            max_index2=i;
        }
    }
    result=(max*max2);
    cout<<result<<endl;
}



int main()
{
    int n;
    cin>>n;
    vector<int> num;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        num.push_back(t);
    }
    Max_pairwise_product(num);
    return 0;
}
