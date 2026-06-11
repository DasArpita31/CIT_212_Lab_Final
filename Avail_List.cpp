#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    int x, n;

    // Create sample list: 10 -> 20 -> 30 -> 40
    Node *head = new Node{10, NULL};
    head->next = new Node{20, NULL};
    head->next->next = new Node{30, NULL};
    head->next->next->next = new Node{40, NULL};

    cout << "Enter X (insert after this value): ";
    cin >> x;

    cout << "Enter new item N: ";
    cin >> n;

    Node *ptr = head;

    // Find X
    while (ptr != NULL && ptr->data != x)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        cout << "X not found!" << endl;
        return 0;
    }

    // Take node from AVAIL (create new node)
    Node *newNode = new Node;
    newNode->data = n;

    // Insert after X and before Y
    newNode->next = ptr->next;
    ptr->next = newNode;

    // Display list
    cout << "Updated List: ";
    ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    return 0;
}