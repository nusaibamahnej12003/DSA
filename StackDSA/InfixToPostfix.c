#include<stdio.h>
#define size 20
char stack[size],t=-1;
char postfix[20],j=-1;
void push(char a)
{
    t++;
    stack[t]=a;
}
void pop(void)
{
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
    while((ch=infix[i++])!='\0')
    {
        if(ch>='A'&&ch<='Z')
        {
            postfix[++j]=ch;
        }
        else
        {
            switch(ch){
                case '(':push(ch);break;
                case ')':
                {
                    while(top()!='('){
                    postfix[++j] =top();
                    pop();}
                    pop();
                    break;
                }
                default:
                {
                    //if 'top' > 'ch' then pop; //else 'ch' push
                   if(precedence(top())>=precedence(ch))
                   {
                    postfix[++j]=top();pop();
                   }
                   push(ch);
                   break;
                }
            }
        }
    }
        while(t!=-1)
        {
            postfix[++j]=top();
            pop();
        }
      
    
     postfix[++j]='\0';
    printf("Postfix Expression is :%s\n",postfix);

}

int main()
{
    char infix[20];
    printf("Enter an infix expression : ");
    fflush(stdin);
    scanf("%s",infix);
    infixtopostfix(infix);

}