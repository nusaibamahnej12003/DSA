#include<stdio.h>
#include<string.h>
//reverse the srting and,,
//evaluate same as postfix but exchange ( and ) and,,
// print reversly
#define size 20
char stack[size],t=-1;
char prefix[20],j=-1;
void push(char a)
{
   if(t<size-1) 
    stack[++t]=a;
}
void pop(void)
{
    if(t>=0)
    t--;
}
char top(void)
{
   return stack[t];
}
int precedence(char a)
{
    switch(a)
    {
        case '^':return 3;
        case '*':
        case '/':
        case '%':return 2;
        case '+':
        case '-':return 1;
        default: return 0;

    }
}
void infixtopostfix(char *infix)
{
    char ch;
    int i=0;
    int len =strlen(infix);
  for(int i=len-1;i>=0;i--)
    {
        ch=infix[i];
        if(ch>='A'&&ch<='Z')
        {
            prefix[++j]=ch;
        }
        else
        {
            switch(ch){
                case ')':push(ch);break;
                case '(':
                {
                    while(top()!=')'){
                    prefix[++j] =top();
                    pop();}
                    pop();
                    break;
                }
                default:
                {
                    //if 'top' > 'ch' then pop; //else 'ch' push
                   if(precedence(top())>=precedence(ch))
                   {
                    prefix[++j]=top();pop();
                   }
                   push(ch);
                   break;
                }
            }
        }
    }
        while(t!=-1)
        {
            prefix[++j]=top();
            pop();
        }
      
    
     prefix[++j]='\0';
     printf("Prefix Expression is :");
     for(i=len-1;i>=0;i--)
   { printf("%c ",prefix[i]);}

}

int main()
{
    char infix[20];
    printf("Enter an infix expression : ");
    fflush(stdin);
    scanf("%s",infix);
    infixtopostfix(infix);

}