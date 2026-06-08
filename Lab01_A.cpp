#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr[100];
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements in sorted order:";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Insertion
    int k;
    cout << "How many elements to insert? ";
    cin >> k;

    while (k--) {
        string x;
        cout << "Enter element to insert: ";
        cin >> x;

        int pos = 0;
        while (pos < n && arr[pos] < x)
            pos++;

        for (int i = n; i > pos; i--)
            arr[i] = arr[i - 1];

        arr[pos] = x;
        n++;
    }

    cout << "After insertion:";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Deletion
    string del;
    cout << "Enter element to delete: ";
    cin >> del;

    int pos = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == del) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Element not found!"<<endl;
    } else {
        for (int i = pos; i < n - 1; i++)
            arr[i] = arr[i + 1];

        n--;

        cout << "After deletion:"<<endl;
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }

    return 0;
}