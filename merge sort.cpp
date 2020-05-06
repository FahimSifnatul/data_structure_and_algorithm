//bismillahir rahmanir rahim
#include<bits/stdc++.h>
using namespace std;

int merge(int a[],int left,int mid,int right)
{
    //this function will merge left part and right part
    int n1=mid-left+1,n2=right-mid;//n1 is for left part array size and n2 is for right part array size
    int left_temp[n1],right_temp[n2];
    for(int i=0;i<n1;i++)
        left_temp[i]=a[left+i];
    for(int i=0;i<n2;i++)
        right_temp[i]=a[mid+1+i];
    int i=0,j=0,k=left;
    while(i<n1 and j<n2)
    {
     if(left_temp[i]<right_temp[i])
     {
         a[k]=left_temp[i];
         ++i;
     }
     else
     {
         a[k]=right_temp[j];
         ++j;
     }
     ++k;
    }
    while(i<n1)
    {
        a[k]=left_temp[i];
        ++i;
        ++k;
    }
    while(j<n2)
    {
        a[k]=right_temp[j];
        ++j;
        ++k;
    }
}

int merge_sort(int a[],int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        merge_sort(a,left,mid);//left part dividing
        merge_sort(a,mid+1,right);//right part dividing
        merge(a,left,mid,right);//conquering gradually.
    }
}

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

    //merge sort
    //this sorting is based on divide and conquer technique.
    //you will find a nice picture about merge_sort (divide and conquer) algorithm at https://goo.gl/mhbpaU
    //sorting in ascending order
    merge_sort(a,0,n-1);

    cout<<"\nAfter sorting:\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    return 0;
}


