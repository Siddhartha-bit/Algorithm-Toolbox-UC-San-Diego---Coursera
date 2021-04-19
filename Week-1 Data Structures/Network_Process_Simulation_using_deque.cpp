#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class input
{
    public:
    long arrival_time;
    int proc_time;
};

int main()
{
    int size;
    cin>>size;
    int n;
    cin>>n;
    int count=0;
    if(n==0)
    {
        return 0;
    }
    vector<input> network(n);
    for(int i=0;i<n;i++)
    {
        cin>>network[i].arrival_time>>network[i].proc_time;
    }
    long sum=network[0].arrival_time;
    deque<long> proc_queue;
    for(int i=0;i<n;i++)
    {
        if(count<size)
        {
            int p=max(sum,network[i].arrival_time);
            cout<<p<<endl;
            sum+=network[i].proc_time;
            proc_queue.push_back(sum);
            count++;
        }
        else
        {
            if(network[i].arrival_time<proc_queue.front())
            {
                cout<<-1<<endl;
            }
            else if(network[i].arrival_time==proc_queue.front())
            {
                proc_queue.pop_front();
                cout<<sum<<endl;
                sum+=network[i].proc_time;
                proc_queue.push_back(sum);
            }
            else
            {
              proc_queue.pop_front();
              int c=max(sum,network[i].arrival_time);
              cout<<c<<endl;
              sum+=network[i].proc_time;
              proc_queue.push_back(sum);
            }
        }
    }
    return 0;
}
 