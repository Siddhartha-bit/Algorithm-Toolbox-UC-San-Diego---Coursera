#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class stacks
{
    
    vector<int> stack;
    public:
    void push(int value)
    {
        stack.push_back(value);
    }
    
    void pop()
    {
        if (stack.size()==0)
        {
            
        }
        else
        {
          stack.pop_back();  
        }
    }
    
    int top()
    {
        return stack.back();
    }
    int empty()
    {
        if(stack.size()==0)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    
};

int main()
{
    stacks s1;
    stacks s2;
    
    int numqueries;
    cin>>numqueries;
    
    string query;
    int value;
    
    for(int i=0;i<numqueries;i++)
    {
        cin>>query;
        if(query=="push")
        {
            cin>>value;
            s1.push(value);
            if(s2.empty())
            {
                s2.push(value);
            }
            else
            {
                if(s2.top()>=value)
                {
                    s2.push(s2.top());
                }
                else
                {
                    s2.push(value);
                }
            }
        }
        else if(query=="pop")
        {
            s1.pop();
            s2.pop();
        }
        else if(query=="max")
        {
            cout<<s2.top()<<endl;
        }
    }
    
    return 0;
}
