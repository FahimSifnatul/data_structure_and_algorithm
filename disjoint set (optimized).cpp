#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000000+7
int cnt;
bool par[MAX];

int find(int node,int parent[],bool par[])
{
 if(par[node]==false)
 {
    par[node]=true;
    return node;
 }
 else if(par[node]==true and parent[node]==node)
    return node;
 else
 {
     parent[node]=find(parent[node],parent,par);
     par[node]=true;
     return parent[node];
 }
}

int Union(int n1,int n2,int parent[],bool par[])
{
 int u=find(n1,parent,par);
 int v=find(n2,parent,par);
 if(u!=v)
 {
    parent[v]=u;
    parent[u]=u;
    --cnt;
 }
}

int main()
{
 int n,m,n1,n2;
 cin>>n>>m;
 int parent[n+1];
 cnt=n;
 for(int i=0;i<m;i++)
 {
     cin>>n1>>n2;
     Union(n1,n2,parent,par);
 }

 cout<<"the number of subgraphs are "<<cnt<<endl;
 return 0;
}

