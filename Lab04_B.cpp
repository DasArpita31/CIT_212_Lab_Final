#include <iostream>
#include <stack>
using namespace std;

void moveDisk(stack<int>& src, stack<int>& dest, char s, char d)
{
    int a, b;

    if(src.empty())
    {
        a = dest.top();
        dest.pop();
        src.push(a);
        cout << "Move disk " << a << " from " << d << " to " << s << endl;
    }
    else if(dest.empty())
    {
        a = src.top();
        src.pop();
        dest.push(a);
        cout << "Move disk " << a << " from " << s << " to " << d << endl;
    }
    else
    {
        a = src.top();
        b = dest.top();

        if(a > b)
        {
            dest.pop();
            src.push(b);
            cout << "Move disk " << b << " from " << d << " to " << s << endl;
        }
        else
        {
            src.pop();
            dest.push(a);
            cout << "Move disk " << a << " from " << s << " to " << d << endl;
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    stack<int> A, B, C;

    for(int i=n; i>=1; i--)
        A.push(i);

    int totalMoves = (1 << n) - 1;

    char s='A', a='B', d='C';

    if(n % 2 == 0)
        swap(a, d);

    for(int i=1; i<=totalMoves; i++)
    {
        if(i % 3 == 1)
            moveDisk(A, C, s, d);
        else if(i % 3 == 2)
            moveDisk(A, B, s, a);
        else
            moveDisk(B, C, a, d);
    }

    return 0;
}