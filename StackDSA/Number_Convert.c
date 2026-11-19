#include<stdio.h>
int main()
{
    int n,num1,num2;
    char c;
    printf("1.Binary\n");
    printf("2.Decimal\n");
    printf("3.Octal\n");
    printf("4.Hexadecimal\n");
    printf("Enter your choice value : ");
    scanf("%d",&n);
    if(n>=1&&n<=4)
    {
        printf("Summmation(+)\n");
        printf("Substraction(-)\n");
        printf("Multiplication(*)\n");
        printf("Division(/)\n");
        printf("Enter your choice operation : ");
        fflush(stdin);
        scanf("%c",&c);
       
        if(n==2)
        {
            printf("Enter your 1st number = ");
            scanf("%d",&num1);
            printf("Enter your 2nd number = ");
            scanf("%d",&num2);
            if(c=='+')
            printf("Result = %d\n",num1+num2);
            else if(c=='-')
            printf("Result = %d\n",num1-num2);
            else if(c=='*')
            printf("Result = %d\n",num1*num2);
            else if(c=='/')
            printf("Result = %d\n",num1/num2);
        }
        else if(n==3)
        {
            printf("Enter your 1st number = ");
            scanf("%o",&num1);
            printf("Enter your 2nd number = ");
            scanf("%o",&num2);
            if(c=='+')
            printf("Result = %o\n",num1+num2);
            else if(c=='-')
            printf("Result = %o\n",num1-num2);
            else if(c=='*')
            printf("Result = %o\n",num1*num2);
            else if(c=='/')
            printf("Result = %o\n",num1/num2);
        }
        else if(n==4)
        {
            printf("Enter your 1st number = ");
            scanf("%x",&num1);
            printf("Enter your 2nd number = ");
            scanf("%x",&num2);
            if(c=='+')
            printf("Result = %x\n",num1+num2);
            else if(c=='-')
            printf("Result = %x\n",num1-num2);
            else if(c=='*')
            printf("Result = %x\n",num1*num2);
            else if(c=='/')
            printf("Result = %x\n",num1/num2);
        }
    }

}