//bismillahir rahmanir rahim
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"enter the number of elements of array: ";
    cin>>n;
    int a[n];
    cout<<"\nenter the elements or the array:\n";
    for(int i=0;i<n;i++)
    {
     cout<<"element no. "<<i+1<<": ";
     cin>>a[i];
    }
    //selection sort
    //sorting in ascending order
    int loc,minimum;
    for(int i=0;i<n;i++)
    {
        loc=i;
        minimum=a[i];
        for(int j=i+1;j<n;j++)
        {
          if(a[j]<minimum)
          {
              loc=j;
              minimum=a[j];
          }
        }
        swap(a[i],a[loc]);
    }
    cout<<"\nAfter sorting:\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    return 0;
}
