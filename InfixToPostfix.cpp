#include<iostream>
#include<stack>
using namespace std;

int precedence(char op)
{
    if(op=='^')
    return 3;
    if(op=='*'|| op=='/')
    return 2 ;
    if(op=='+'||op=='-')
    return 1;

    return 0;
}
int main()
{
    string infix;
    string postfix="";

    cout<<"Enter infix expression:";
    cin>>infix;
    stack<char>st;

    for(int i = 0;i<infix.length();i++)
    {
        char ch = infix[i];
        if(isalnum(ch))
        {
            postfix +=ch;
        }
        else if(ch=='(')
        {
            st.push(ch);
        }
        else if(ch==')')
        {
            while(!st.empty() && st.top() !='(')
            {
                postfix +=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && precedence(st.top())>=precedence(ch))
            {
                postfix +=st.top();
                st.pop();
            }
            st.push(ch);

        }
    }
    while(!st.empty())
    {
        postfix +=st.top();
        st.pop();
    }
    cout<<"Postfix Expression="<<postfix<<endl;
    return 0;
}