//bismillahir rahmanir rahim
#include<bits/stdc++.h>
using namespace std;

struct val
{
 int node,cost;
 val(int a,int b)
 {
     node=a;
     cost=b;
 }
};

struct comp
{
    bool operator()(const val& a,const val& b)
    {
      return a.cost>b.cost;
    }
};

int dijkstra(int src,int dis[],vector<val> data[])
{
 int u,len;
 dis[src]=0;
 priority_queue<val,vector<val>,comp>q;
 q.push(val(src,0));
 while(!q.empty())
 {
     u=q.top().node;
     q.pop();
     len=data[u].size();
     for(int i=0;i<len;i++)
     {
         if(dis[u]+data[u][i].cost<dis[data[u][i].node])
         {
          dis[data[u][i].node]=dis[u]+data[u][i].cost;
          q.push(val(data[u][i].node,dis[data[u][i].node]));
         }
     }
 }
 return 0;
}

int main()
{
    int n,m,c,n1,n2,src,des;
    cout<<"input : node_number>>edge_number\n";
    cin>>n>>m;
    vector<val>data[n];
    int dis[n];

    for(int i=0;i<m;i++)
    {
        cin>>n1>>n2>>c;
        data[n1].push_back(val(n2,c));
        data[n2].push_back(val(n1,c));
        //cout<<data[n1][0].cost<<endl;
    }
    for(int i=0;i<5;i++)
    {
    cout<<"input the source and destination node :\n";
    cin>>src>>des;
    for(int i=0;i<n;i++)
       dis[i]=10e8;
    dijkstra(src,dis,data);
    cout<<"the shortest distance between source and node is "<<dis[des]<<endl;
    }
    return 0;
}


/*
6 8
0 1 1
0 3 4
0 5 3
1 2 2
2 3 6
2 4 7
3 4 7
4 5 5
*/






