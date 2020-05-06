//bismillahir rahmanir rahim
#include<bits/stdc++.h>
using namespace std;

int binarysearch(int a[],int left,int right,int data)
{
 int mid=(left+right)/2;
 if(left>right)
    return -1;
 else if(a[mid]==data)
    return mid;
 else if(a[mid]>data)
 {
     right=mid-1;
     binarysearch(a,left,right,data);
 }
 else if(a[mid]<data)
 {
     left=mid+1;
     binarysearch(a,left,right,data);
 }
}

int main()
{
   int n,data;
   cout<<"number of element : ";
   cin>>n;
   int a[n];
   cout<<"Input : ";
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   cout<<"finding value : ";
   cin>>data;
   int result=binarysearch(a,0,n-1,data);
   if(result==-1)
    cout<<"not found";
   else
    cout<<"found at "<<result;
    cout<<'\n';
   return 0;
}

