//bismillahir rahmanir rahim
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,op,num;
    cout<<"enter the number of elements for your queue: ";
    cin>>n;

    int queue[n],front=0,present_pos=0;
    memset(queue,-1,sizeof queue);

    cout<<"enter the number of your operations: ";
    cin>>op;

    for(int i=0;i<op;i++)
    {
        string s;
        cin>>s;
        if(s=="push")
        {
         cin>>num;
         if(queue[present_pos]==-1)
         {
             queue[present_pos]=num;
             cout<<"the value is added at "<<present_pos<<" position of queue.\n";
             ++present_pos;
             if(present_pos==n)
                present_pos=0;
         }
         else
             cout<<"queue is full\n";
        }
        else if(s=="pop")
        {
             if(queue[front]!=-1)
             {
              queue[front]=-1;
              cout<<"value is popped from position "<<front<<" of the queue\n";
              ++front;
              if(front==n)
                front=0;
             }
             else
                cout<<"queue is totally empty\n";
        }
    }
    return 0;
}
