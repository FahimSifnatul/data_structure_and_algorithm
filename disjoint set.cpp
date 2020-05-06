#include<bits/stdc++.h>
using namespace std;

void makeset(int n,int parent[])
{
    for(int i=0;i<=n;i++)
        parent[i]=i;
}

int find(int node,int parent[])
{
 if(parent[node]==node)return node;
 else
 {
     parent[node]=find(parent[node],parent);
     return parent[node];
 }
}

int Union(int n1,int n2,int parent[])
{
 int u=find(n1,parent);
 int v=find(n2,parent);
 if(u!=v) parent[v]=u;
}

int main()
{
 int n,m,n1,n2;
 cin>>n>>m;
 int parent[n+1];
 makeset(n,parent);
 for(int i=0;i<m;i++)
 {
     cin>>n1>>n2;
     Union(n1,n2,parent);
 }
 set<int>disjointset;
 for(int i=1;i<=n;i++)
    disjointset.insert(parent[i]);
    //cout<<parent[i]<<' ';
 cout<<"the number of subgraphs are "<<disjointset.size()<<endl;
 return 0;
}

/*
6 6
1 0
0 5
3 1
2 6
5 2
4 3
*/
