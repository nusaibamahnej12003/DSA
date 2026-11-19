//post expression solVing..
#include<stdio.h>

#include<ctype.h>
char pop(void);

#define size 20
char stack1[size],t=-1;
int push(char a)
{
    if(t==size-1)
    {
     printf("*******Stack Overflow********\n");
     return 0;
    }
    else{
        if(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'||a=='8'||a=='9')
       {
        int p=a-'0';
         t++;
        stack1[t]=a;}
       else if(a=='+'||a=='-'||a=='/'||a=='*')
        {
            pop();
            char x=pop();
            char y=pop();
            if(a=='+')
            {
                int z=y+x;
                push(z);
            }
           else if(a=='-')
            {
                push(y-x);
            }
           else if(a=='/')
            {
                push(y/x);
            }
           else if(a=='*')
            {
                push(y*x);
            }
          
        }
    }
}
char pop(void)
{
    if(t<0)
    {
     printf("********Stack Underflow*******\n");
     return 0;
    }
    else{
    
      return stack1[t];
       t--;
    }

}
void display(void)
{
    printf("The stack is :\n");
    for(int i=t;i>=0;i--)
    {
        printf("%d\n",stack1[i]);
    }

}

int main()
{
   char n,c, push_num;
   while(1)
   {
   printf(".......Enter your choice......... \n");
   printf("1.Posh\n");
   //printf("p.Pop\n");
   printf("2.Display\n");
   printf("3.Exit.........\n");
   fflush(stdin);
   scanf("%c",&n);
   if(n=='1')
   {

        printf("Enter your push digit = ");
        fflush(stdin);
        scanf("%c",&push_num);
        push(push_num);
    
   }
   else if(n=='2')
   {
    display();
   }
   else{
    printf("///////EXIT//////");
    break;
   }
}

}