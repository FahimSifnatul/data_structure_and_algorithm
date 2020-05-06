//bismillahir rahmanir rahim
//dfs for undirected graph
#include<bits/stdc++.h>
using namespace std;

int dfs(int src,int dis[],vector<int>node[])
{
    int u,v;
    u=src;
    v=node[src].size();
    for(int i=0;i<v;i++)
    {
        if(dis[node[u][i]]==-1)
        {
            dis[node[u][i]]=dis[u]+1;
            dfs(node[u][i],dis,node);
        }
    }
}

int main()
{
    int n,src,des,q;
    cout<<"node number : ";
    cin>>n;
    cout<<"query number : ";
    cin>>q;
    vector<int>node[n];
    int dis[n];
    cout<<"src des \n--- ---\n";
    for(int i=0;i<q;i++)
    {
        cin>>src>>des;
        node[src].push_back(des);
        node[des].push_back(src);
    }
    cout<<"enter the qeury number to find distance from node to destination : ";
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cout<<"src des : ";
        cin>>src>>des;
        memset(dis,-1,sizeof dis);//built in function to set all array element value to -1;
        //you can use for loop instead;
        dis[src]=0;
        dfs(src,dis,node);
        cout<<"the required distance from source to destination is "<<dis[des]<<endl;
    }
    return 0;
}






