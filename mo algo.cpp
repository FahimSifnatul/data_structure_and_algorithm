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
#define pfs(a)     printf("%s",a)
#define ci(a)      cin>>a
#define co(a)      cout<<a
#define pb(a)      push_back(a)
#define newline    printf("\n")
#define ret        return 0
#define pi         acos(-1.0)
#define mod        1000000007

#define loopi(n) for(int i=0;i<n;i++)
#define loopd(n) for(int i=n-1;i>=0;i--)
int l = 0, r = -1, sum = 0, ans[50005], a[50005];

struct val
{
  int left, right, id, block;
} q[50005];

void add(int x)
{
    sum += a[x];
}

void remove(int x)
{
    sum -= a[x];
}

bool cmp(val a, val b)
{
    return a.block == b.block ? a.right < b.right : a.block < b.block;
}

int main() {
  int n;
  sf(n);
  int k = sqrt(n);
  loopi(n)sf(a[i]);
  int Q;
  sf(Q);
  for(int i = 0; i < Q; i++)
  {
    sf(q[i].left),sf(q[i].right);
    q[i].id = i;
    q[i].block = q[i].left / k;
  }
  sort(q,q+n,cmp);
  for(int i = 0; i < Q; i++)
  {
    while(l > q[i].left)  add(--l);
    while(r < q[i].right) add(++r);
    while(l < q[i].left)  remove(l++);
    while(r > q[i].right) remove(r--);
    ans[q[i].id] = sum;
  }
  loopi(Q)
    pf(ans[i]),newline;
  ret;
}








