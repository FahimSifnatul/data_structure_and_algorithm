//bismillahir rahmanir rahim
//this is not a pure deque code. actually i am running short of time. pushfront and pushback property of deque is not added here.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,op,num;
    cout<<"enter the number of elements for your queue: ";
    cin>>n;

    int queue[n],front=0,rear=0;
    memset(queue,-1,sizeof queue);

    cout<<"enter the number of your operations: ";
    cin>>op;

    for(int i=0;i<op;i++)
    {
        string s;
        cin>>s;
        if(s=="pushback")
        {
         cin>>num;
         if(queue[rear]==-1)
         {
             queue[rear]=num;
             cout<<"the value is added at "<<rear<<" position of queue.\n";
             ++rear;
             if(rear==n)
               rear=0;
         }
         else
             cout<<"queue is full\n";
        }
        else if(s=="pushfront")
        {
         cin>>num;
         if(queue[front]==-1)
         {
             queue[front]=num;
             cout<<"the value is added at "<<front<<" position of queue.\n";
             --front;
             if(front==-1)
                front=n-1;
         }
         else
             cout<<"queue is full\n";
        }
        else if(s=="popfront")
        {
            ++front;
            if(front==n)
                front=0;
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
                //cout<<front<<endl;
        }
        else if(s=="popback")
        {
            --rear;
            if(rear==-1)
                rear=0;
             if(queue[rear]!=-1)
             {
              queue[rear]=-1;
              cout<<"value is popped from position "<<rear<<" of the queue\n";
              --rear;
              if(rear==-1)
                rear=n-1;
             }
             else
                cout<<"queue is totally empty\n";
        }
    }
    return 0;
}

