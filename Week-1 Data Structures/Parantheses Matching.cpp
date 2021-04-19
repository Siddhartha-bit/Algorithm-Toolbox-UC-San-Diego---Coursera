#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
   string s;
   getline(cin,s);
   stack<char> s1;
   vector<char> index;
   
   for(int i=0;i<s.length();i++)
   {
       if((s[i]=='{') || (s[i]=='(') || (s[i]=='['))
       {
           s1.push(s[i]);
           index.push_back(i);
       }
       else if(s[i]=='}')
       {
           if(s1.empty())
           {
               cout<<i+1<<endl;
               return 0;
           }
           else if(s1.top()=='{')
           {
               s1.pop();
               index.erase((index.end()-1));
           }
           else
           {
               cout<<i+1<<endl;
               return 0;
           }
        }
        else if(s[i]==')')
        {
           if(s1.empty())
           {
               cout<<i+1<<endl;
               return 0;
           }
           else if(s1.top()=='(')
           {
               s1.pop();
               index.erase((index.end()-1));
           }
           else
           {
               cout<<i+1<<endl;
               return 0;
           }
        }
        else if(s[i]==']')
        {
           if(s1.empty())
           {
               cout<<i+1<<endl;
               return 0;
           }
           if(s1.top()=='[')
           {
               s1.pop();
               index.erase((index.end()-1));
           }
           
           else
           {
               cout<<i+1<<endl;
               return 0;
           }
        }
        else
        {
            
        }
       
   }
   if(index.empty())
   {
       cout<<"Success"<<endl;
   }
   else
   {
       cout<<index.front()+1<<endl;  
   }

return 0;
}
