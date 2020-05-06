//bismillahir rahmanir rahim
#include<bits/stdc++.h>
using namespace std;
int ma=-9000;

int partition(int node,int a[],int tree[],int left,int right)
{
    if(left<right)
    {
     int mid=(left+right)/2;
     partition(2*node,a,tree,left,mid);
     partition(2*node+1,a,tree,mid+1,right);
     tree[node]=tree[2*node]+tree[2*node+1];
     ma=max(ma,tree[node]);
    }
    else if(left==right)
    {
        ma=max(ma,a[left]);
        return tree[node]=a[left];
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    int tree[3*n];
    memset(tree,-1,sizeof tree);
    for(int i=0;i<n;i++)
        cin>>a[i];

    partition(1,a,tree,0,n-1);

    for(int i=1;i<3*n;i++)
    {
        if(tree[i]==-1)break;
        else cout<<tree[i]<<' ';
    }
    cout<<endl<<ma<<endl;
    return 0;
}





