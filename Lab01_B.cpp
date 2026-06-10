#include <iostream>
#include <string>
using namespace std;

int main()
{
    string T, P;

    cout << "Enter text: ";
    cin >> T;

    cout << "Enter pattern: ";
    cin >> P;

    int n = T.length();
    int m = P.length();

    bool found = false;

    for(int i = 0; i <= n - m; i++)
    {
        int j;

        for(j = 0; j < m; j++)
        {
            if(T[i + j] != P[j])
                break;
        }

        if(j == m)
        {
            cout << "Pattern found at index " << i << endl;
            found = true;
        }
    }

    if(!found)
        cout << "Pattern not found!" << endl;

    return 0;
}