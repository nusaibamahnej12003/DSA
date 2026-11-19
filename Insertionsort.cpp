#include<iostream>
using namespace std;
int main()
{
    int a[]={2,7,4,8,1,10,9};


    
    int n=sizeof(a)/sizeof(a[0]);
    int temp;
    for(int i=1;i<n;i++)
    {
        temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    
    for(int x:a)
    {
        cout<<x<<" ";
    }
}