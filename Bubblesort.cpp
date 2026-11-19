#include<iostream>
using namespace std;
int main()
{
    int a[]={2,7,4,8,1,10,9};
    int n=sizeof(a)/sizeof(a[0]);
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
          if(a[j]>a[j+1])
          {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
          }
        }
    }
    for(int x:a)
    {
        cout<<x<<" ";
    }
}