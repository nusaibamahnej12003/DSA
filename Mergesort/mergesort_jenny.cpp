#include<iostream>
using namespace std;
int a[7]={6,10,3,1,15,6,20};
int b[7];
void marge(int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
    }
   
        while(j<=high)
        {
         b[k++]=a[j++];
        }
        while(i<=mid)
        {
        b[k++]=a[i++];
        }
    
    for(int k=low;k<=high;k++)
    {
        a[k]=b[k];
    }
}
void margesort(int low,int high)
  {
     if(low<high)
     {
        int mid =(low+high)/2;
        margesort(low,mid);
        margesort(mid+1,high);
        marge(low,mid,high);
     }
  }
int main()
{
    int low=0;
    int high =6;
    margesort(low,high);
    for(int i=0;i<7;i++)
    {
        cout<<a[i]<<" ";
    }
}
