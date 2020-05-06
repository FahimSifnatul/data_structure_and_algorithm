//bismillahir rahmanir rahim
//kruskal's algorithm
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000000+7

struct val
{
    int n1,n2,cost;
    val(int a,int b,int c)
    {
        n1=a;
        n2=b;
        cost=c;
    }
};

bool comp(const val& a,const val& b)
{
  return a.cost<b.cost;
}

void makeset(int parent[],int n)
{
    for(int i=1;i<=n;i++)
        parent[i]=i;
}

int find(int n1,int parent[])
{
    if(parent[n1]==n1)return n1;
    else
    {
        parent[n1]=find(parent[n1],parent);
        return parent[n1];
    }
}

int Union(val node,int parent[])
{
    int u=find(node.n1,parent);
    int v=find(node.n2,parent);
    if(u!=v)
    {
        parent[v]=u;
        return 1;
    }
    return 0;
}

int main()
{
    int n,m,n1,n2,c;
    cin>>n>>m;
    vector<val>node,mst;
    int parent[n+1];
    makeset(parent,n);
    for(int i=0;i<m;i++)
    {
        cin>>n1>>n2>>c;
        node.push_back(val(n1,n2,c));
    }
    sort(node.begin(),node.end(),comp);
    int len=node.size();
    for(int i=0;i<len;i++)
    {
        int ret=Union(node[i],parent);
        if(ret==1)
        {
           mst.push_back(val(node[i].n1,node[i].n2,node[i].cost));
        }
    }
    /*after sorting, the value of node vector.....
    cout<<endl;
    for(int i=0;i<len;i++)
        cout<<node[i].n1<<' '<<node[i].n2<<' '<<node[i].cost<<endl;*/
    cout<<endl;
    len=mst.size();
    for(int i=0;i<len;i++)
        cout<<mst[i].n1<<' '<<mst[i].n2<<' '<<mst[i].cost<<endl;

    return 0;
}


/*
7 10
1 2 5
1 3 2
1 4 7
2 4 6
2 7 2
3 5 9
4 5 3
4 6 4
5 6 8
6 7 5
*/








