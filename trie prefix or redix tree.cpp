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
struct node
{
    bool end;
    node *next[26];
    node()
    {
        end = false;
        loopi(26)next[i] = nullptr;
    }
}*root = new node;

int insert(char s[],int len)
{
    node *curr = root;
    for(int i=0;i<len;i++)
    {
        int id = s[i] - 'a';
        if(curr->next[id] == nullptr)
        {
            curr->next[id] = new node;
        }
        curr = curr->next[id];
    }
    curr->end = true;
}

int search(char s[],int len)
{
    node *curr = root;
    for(int i=0;i<len;i++)
    {
        int id = s[i] - 'a';
        if(curr->next[id] == nullptr)
            return 0;
        curr = curr->next[id];
    }
    return curr->end;
}

// HERE one function is left still. DELETE function. on the basis of problem, the del function should be written.

int main()
{
    int n;
    char s[100000];
    p("Enter the number of strings to insert into dictionary: ");
    sf(n);
    p("Enter the strings one by one upto n lines:\n");
    while(n--)
    {
        sfs(s);
        insert(s,strlen(s));
    }
    p("Enter the number of query strings to find out in dictionary: ");
    sf(n);
    while(n--)
    {
        sfs(s);
        search(s,strlen(s)) ? p("Found\n") : p("Not found\n");
    }
    newline;
    ret;
}


















