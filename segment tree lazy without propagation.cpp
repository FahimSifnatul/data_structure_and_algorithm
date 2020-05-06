#include<bits/stdc++.h>
using namespace std;

#define ll         long long int
#define ull        unsigned long long int
#define fastio     ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define sf(a)      scanf("%d",&a)
#define sfl(a)     scanf("%lld",&a)
#define sfd(a)     scanf("%lf",&a)
#define sfs(a)     scanf("%s",a)
#define sfc(a)     scanf("%c",&a)
#define p(a)       printf(a)
#define pf(a)      printf("%d",a)
#define pfl(a)     printf("%lld",a)
#define pfd(a)     printf("%lf",a)
#define pfc(a)     printf("%c",a)
#define pfs(a)     printf("%s",s)
#define ci(a)      cin>>a
#define co(a)      cout<<a
#define pb(a)      push_back(a)
#define newline    printf("\n")
#define ret        return 0
#define pi         acos(-1.0)
#define mod        1000000007

#define loopi(n) for(int i=0;i<n;i++)
#define loopd(n) for(int i=n-1;i>=0;i--)
ll tree[300015],lazy[300015],n,q;

ll update(ll node,ll left,ll right,ll i,ll j,ll x)
{
    if(left > j or right < i)return 0;
    if(lazy[node])
    {
        tree[node] += (right-left+1)*lazy[node];
        if(left < right)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(left >= i and right <= j)
    {
        if(left < right)
        {
            lazy[2*node] += x;
            lazy[2*node+1] += x;
        }
        return tree[node] += (right-left+1)*x;
    }
    ll mid = (left+right)>>1;
    ll l = node<<1;
    ll r = (node<<1)+1;
    update(l,left,mid,i,j,x);
    update(r,mid+1,right,i,j,x);
    tree[node] = tree[l] + tree[r];
}

ll query(ll node,ll left,ll right,ll i,ll j)
{
    if(left > j or right < i)return 0;
    if(lazy[node])
    {
        tree[node] += (right-left+1)*lazy[node];
        if(left < right)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    ll mid = (left+right)/2;
    if(left >= i and right <= j) return tree[node];
    return query(2*node,left,mid,i,j) + query(2*node+1,mid+1,right,i,j);
}

int main()
{
    int t;
    sf(t);
    while(t--)
    {
        sfl(n),sfl(q);
        --n;
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
    while(q--)
    {
        ll Q,i,j,x;
        sfl(Q),sfl(i),sfl(j);
        --i,--j;
        if(Q)
        {
            pfl(query(1,0,n,i,j));
            newline;
        }
        else
        {
            sfl(x);
            update(1,0,n,i,j,x);
        }
        //printf("%d.....\n",tree[1]);
    }
    }
    ret;
}











