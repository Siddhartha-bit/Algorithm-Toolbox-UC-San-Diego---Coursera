#include <iostream>
#include <queue>
using namespace std;

class process{
    public:
    int id;
    long long proc_time;
    
    process(int id, long long proc_time)
    {
         this->id=id;
         this->proc_time=proc_time;
    }
};

class process1
{
    public:
    int id1;
    long long proc_time1;
};


class myComparator { 
    public: 
        int operator() (const process& a, const process& b) 
        { 
            if(a.proc_time==b.proc_time)
            {
                return a.id>b.id; 
            }
            return a.proc_time>b.proc_time;
        } 
};

int main()
{
    priority_queue<process, vector<process> ,myComparator> finish;
    int n;
    int m;
    cin>>n;
    cin>>m;
    long long times[m];
    process1 output[m];
    for(int i=0;i<m;i++)
    {
        cin>>times[i];
    }
    
    //int i=0;
    //int j=i;
    /*if(m<=n)
    {
        for(i=0;i<m;i++)
        {
            output[i].id1=j;
            output[i].proc_time1=0;
            if(times[i]==0)
            {
                j--;
            }
            j++;
            //finish.push(process(i,times[i]));
        }
    }
    
    else
    {
        for(i=0;i<n;i++)
        {
            output[i].id1=j;
            output[i].proc_time1=0;
            if(times[i]==0)
            {
                if(j!=0)
                {
                    j--; 
                }
            }
            else
            {
                finish.push(process(j,times[i]));
                j++;
            }
        }
    }*/
    for(int i=0;i<n;i++)
    {
        finish.push(process(i,0));
    }
    
    for(int j=0;j<m;j++)
    {
        
        process p=finish.top();
        finish.pop();
        output[j].id1=p.id;
        output[j].proc_time1=p.proc_time;
        long long t=(p.proc_time)+times[j];
        finish.push(process(p.id,t));
    }
    
    for(int l=0;l<m;l++)
    {
        cout<<output[l].id1<<" "<<output[l].proc_time1<<endl;
    }
    
    return 0;
}
