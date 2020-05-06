//bismillahir rahmanir rahim
//dijkstra algorithm implementation for undirected weighted graph
#include<bits/stdc++.h>
using namespace std;

int bfs(int src,int dis[],vector<int>cost[],vector<int>node[])
{
    int u,v;
    queue<int>q;
    dis[src]=0;
    q.push(src);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        v=node[u].size();
        for(int i=0;i<v;i++)
        {
            if(dis[u]+cost[u][i]<dis[node[u][i]])
            {
                dis[node[u][i]]=dis[u]+cost[u][i];
                q.push(node[u][i]);
            }
        }
    }
    return 0;
}

int main()
{
    int n,src,des,q,weight;
    cout<<"node number : ";
    cin>>n;
    cout<<"query number : ";
    cin>>q;
    vector<int>node[n],cost[n];
    int dis[n];
    cout<<"src des weight\n--- --- ------\n";
    for(int i=0;i<q;i++)
    {
        cin>>src>>des>>weight;
        node[src].push_back(des);
        node[des].push_back(src);
        cost[src].push_back(weight);
        cost[des].push_back(weight);
    }
    cout<<"enter the qeury number to find distance from node to destination : ";
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cout<<"src des : ";
        cin>>src>>des;
        for(int i=0;i<n;i++)
            dis[i]=99999999;//initializing the array value by a infinite number. here assume that 999999999 is the infinite number.
        bfs(src,dis,cost,node);
        cout<<"the shortest distance from source to destination is "<<dis[des]<<endl;
    }
    return 0;
}










