#include<iostream>
using namespace std;
int main()
{
    int a[]={2,7,4,8,1,10,9};
    int n=sizeof(a)/sizeof(a[0]);
    int temp,i,j;
    for(i=0;i<n-1;i++)
    {
        int min=i;
        for(j=i+1;j<n;j++)
        {
        
            if(a[j]<a[min])
            {
              min=j;
            }
        
        }
     temp=a[i];
     a[i]=a[min];
     a[min]=temp;
    }
    for(int x:a)
    {
        cout<<x<<" ";
    }
}