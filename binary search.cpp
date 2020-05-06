#include<bits/stdc++.h>
using namespace std;

vector<int>a;

int binarysearch(vector<int> a,int len,int pos)
{
 int begin=0,end=len-1,mid;
 while(begin<=end)
 {
  mid=(begin+end)/2;
  if(a[mid]==pos)
  {
     return mid;
  }
  else if(a[mid]>pos)
  {
      end=mid-1;
      mid=(begin+end)/2;
  }
  else
  {
      begin=mid+1;
      mid=(begin+end)/2;
  }
 }
 return -1;
}

int main()
{
    int n,x,temp;
    cin>>n>>x;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        a.push_back(temp);
    }
    sort(a.begin(),a.end());
    temp=a.size();
    int pos=binarysearch(a,temp,x);
    cout<<pos<<'\n';
}
