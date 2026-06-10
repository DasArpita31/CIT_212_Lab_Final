#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isAlphabetDigit(char c) {
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9'))
        return true;

    return false;
}

int precedence(char x) {
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '^')
        return 3;

    return 0;
}

void POLISH(string Q) {

    stack<char> s;
    string p = "";

    s.push('(');
    Q = Q + ')';

    for (int i = 0; i < Q.length(); i++) {
        char ch = Q[i];

        if (isAlphabetDigit(ch)) {
            p += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {

            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                p += s.top();
                s.pop();
            }

            s.push(ch);
        }
        else if (ch == ')') {

            while (!s.empty() && s.top() != '(') {
                p += s.top();
                s.pop();
            }

            s.pop(); // remove '('
        }
    }

    cout << "Postfix Expression = " << p << endl;
}

int main() {

    string Q;

    cout << "Enter Infix Expression: ";
    cin >> Q;

    POLISH(Q);

    return 0;
}