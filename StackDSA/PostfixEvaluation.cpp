#include<iostream>
#include<stack>
#include<cctype>

using namespace std;
int calculate(char x,int a,int b)
{
switch(x)
{
    case '+':return a+b;
    case '-':return a-b;
    case '*':return a*b;
    case '/':return a/b;

}
}
int evaluatepostfix(string &postfix)
{
    stack<int> st;
    char ch;
    int i=0;
   for(int i=0;i<postfix.length();i++)
    {
        char ch=postfix[i];
        if(isdigit(ch))
        { st.push(ch-'0');}
        else
        {
            if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
            {
               int b=st.top();
               st.pop();
               int a=st.top(); 
               st.pop();
               int ans=calculate(ch,a,b);
               st.push(ans);
            }
        }

    }
    return st.top();

}
int main()
{
    string postfix;
    cout<<"Enter postfix expression";
    cin>>postfix;
    int result=evaluatepostfix(postfix);
    cout<< "The result is:"<<result;
    return 0;

}

