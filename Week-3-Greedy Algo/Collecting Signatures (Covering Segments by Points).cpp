#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long 

class segments
{
    public:
    ll start,end;
};

bool cmp(segments &a, segments &b)
{
  return a.end<b.end;    
}

void cover_seg_points(vector<segments> &segment)
{
    sort(segment.begin(),segment.end(),cmp);
    
    vector<ll>points;
    ll point=segment[0].end;
    points.push_back(point);
    
    for(int i=1;i<segment.size();i++)
    {
        if(point<segment[i].start || point>segment[i].end)
        {
            points.push_back(segment[i].end);
            point=segment[i].end;

        }
    }
    cout<<points.size()<<endl;
    for(int i =0;i<points.size();i++)
    {
        cout<<points[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    vector<segments> segment(n);
    for(int i=0;i<segment.size();i++)
    {
        cin>>segment[i].start>>segment[i].end;
    }
    cover_seg_points(segment);
    return 0;
}

