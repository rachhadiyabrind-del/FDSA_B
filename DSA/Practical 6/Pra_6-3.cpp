#include <iostream>
#include <stack>
using namespace std;

int getPriority(char op)
{
    switch (op)
    {
    case '^':
        return 3;

    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

int main()
{
    string infix, postfix = "";
    stack<char> s;
    cout << "Enter infix expression: ";
    cin >> infix;
    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        switch (ch)
        {
        case '(':
            s.push(ch);
            break;
        case ')':
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty())
                s.pop();
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!s.empty() &&
                   s.top() != '(' &&
                   getPriority(s.top()) >= getPriority(ch))
            {

                postfix += s.top();
                s.pop();
            }

            s.push(ch);
            break;
        default:
            postfix += ch;
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    cout << "Postfix: " << postfix << endl;
    return 0;
}