#include<stdio.h>
#define size 20
int stack[size],t=-1;
int push(int a)
{
    if(t==size-1)
    {
     printf("*******Stack Overflow********\n");
     return 0;
    }
    else{
        t++;
        stack[t]=a;
    }
}
void pop(void)
{
    if(t<0)
    {
     printf("********Stack Underflow*******\n");
     return;
    }
    else{
        t--;
    }

}
void display(void)
{
    printf("The stack is :\n");
    for(int i=t;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }

}

int main()
{
    char n,c;
   int push_num,num;
   while(1)
   {
   printf(".......Enter your choice......... \n");
   printf("1.Posh\n");
   printf("p.Pop\n");
   printf("3.Display\n");
   printf("4.Exit.........\n");
   fflush(stdin);
   scanf("%c",&n);
   if(n=='1')
   {
    printf("How many number you want to push?");
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        printf("Enter your push number = ");
        scanf("%d",&push_num);
        push(push_num);
    }
   }
   else if(n=='p')
   {
    pop();
   }
   else if(n=='3')
   {
    display();
   }
   else{
    printf("///////EXIT//////");
    break;
   }
}

}