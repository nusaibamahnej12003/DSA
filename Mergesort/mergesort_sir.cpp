#include<iostream>
using namespace std;
int a[7]={6,10,3,1,15,6,20};
int l[7];
int r[7];
void marge(int low,int mid,int high)
{
   int n1=mid-low+1;
   int n2=high-mid;
   for(int i=1;i<=n1;i++)
   {
    l[i]=a[low+i-1];
   }
   for(int j=1;j<=n2;j++)
   {
    r[j]=a[mid+j];
   }
   l[n1+1]=10000;
   r[n2+1]=10000;
   int i=1,j=1;
   for(int k=low;k<=high;)
   {
    if(l[i]<r[j])
    {
        a[k++]=l[i++];
    }
    else
    {
        a[k++]=r[j++];
    }
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
