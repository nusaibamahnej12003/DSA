#include<stdio.h>
#define size 20
int t=-1,j=-1;
int stack[size];
int stack2[20];
                            void push(int a)
                            {
                            stack[++t]=a;
                            }
                            int pop(void)
                            {  
                                int p=stack[t];
                                t--;
                                return p;
                                
                            }
                              void deletemin(int min)
                                                
                             {
                                for(int i=t;i>=0;i--)
                              {
                                 if(stack[i]!=min)
                                {stack2[++j]=pop();
                                }
                                 else
                             break;
                            }
                            pop();
                         for(int i=j;i>=0;i--)
                                {
                                stack[++t]=stack2[i];
                               }
                         }
                            void display(void)
                            {
                                for(int j=0;j<=t;j++)
                                {
                                    printf("%d ",stack[j]);
                                }
                            }
    int main()
    {
      int n,num,min; 
           printf("How many number you want to push :");
           scanf("%d",&n);
           while(n--)
           {
            scanf("%d",&num);
            push(num);
           }
             min=stack[0];
        for(int i=0;i<=t;i++)
        {
          
            if(stack[i]<min)
            {
               min=stack[i];
            }
        }
   deletemin(min);
   display();
 

    }

