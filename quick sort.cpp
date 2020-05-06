//bismillahir rahmanir rahim
#include<bits/stdc++.h>
using namespace std;

int quick_sort(int a[],int left,int right)
{
    int pivot=a[left];
    int i=left+1,j=right;
    while(i<=j)
    {
        while(i<=right)
        {
            if(a[i]>pivot)
            {
                break;
            }
            ++i;
        }
        while(j>left)
        {
            if(a[j]<pivot)
            {
                break;
            }
            --j;
        }
        if(i<=j)
        {
            swap(a[i],a[j]);
        }
    }
    swap(a[left],a[j]);
    return j;
}

int quick(int a[],int left,int right)
{
  if(left<right)
  {
    int j=quick_sort(a,left,right);
    quick(a,left,j-1);
    quick(a,j+1,right);
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

    //quick sort
    //this sorting is based on divide and conquer technique.
    //you will find a nice picture about merge_sort (divide and conquer) algorithm at https://goo.gl/mhbpaU
    //sorting in ascending order
    quick(a,0,n-1);

    cout<<"\nAfter sorting:\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    return 0;
}



