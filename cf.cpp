
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
long long fun(long long num,long long l)
{

    if(num<3)
        {
        l=l+(num*3);
        return l;
        }
    else{
      int i=0,p=0;
      while(p<num)
        {
            i++;
            p=pow(3,i);
        }
        if(p!=num)i--;{p=pow(3,i);}

    l=l+pow(3,i+1)+i*(pow(3,i-1));
    num = num-p; 

  fun(num,l);
}
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long ans = fun(n,0);
        
    cout<<ans<<endl;
    }
    
}