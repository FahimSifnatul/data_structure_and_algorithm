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
    //bubble sort
    //sorting in ascending order
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);//built-in swap function under algorithm header file
            }
        }
    }
    cout<<"\nAfter sorting:\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    return 0;
}








