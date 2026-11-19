#include<stdio.h>
#define size 100
int popneg(void);
int p=-1,n=-1;
int stackpos[size],stackneg[size];
void pushpos(int a)
{
    stackpos[++p]=a;
}
void pushneg(int a)
{
    stackneg[++n]=a;
}
int poppos()
{
    if(p>=0)
    {
        int b= stackpos[p];
        p--;
        return b;
    }
   
}
int popneg(void)
{
    if(n>=0)
    {
        int b=stackneg[n];
        n--;
        return b;
    }
   
}
int main()
{
    int t,n,m,l,r,ll,rr;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&n,&m,&l,&r);
        
        for(int i=l;i<0;i++)
        {
            pushneg(i);

        }
    
           for(int j=r;j>0;j--)
           {
            pushpos(j);
           }
        
        int k=1;
        ll=rr=0;
        while(m--)
        {    
           if(k%2==1) {
            if(n==-1){ll=stackneg[0];m++;}
                    else ll=popneg();}                
             else  {
                if(p==-1){rr=stackpos[0];m++;} else rr=poppos();}
             k++;      
        }
        printf("%d %d\n",ll,rr);
         p=-1;
         n=-1;

        
    }
   
}