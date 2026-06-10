#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* head = NULL;

// Insert at start
void insertStart(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertEnd(int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert after kth node
void insertAfterK(int k, int val) {
    Node* temp = head;

    for (int i = 1; i < k && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!\n";
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from start
void deleteStart() {
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void deleteEnd() {
    if (head == NULL) return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Delete kth node
void deleteK(int k) {
    if (head == NULL) return;

    if (k == 1) {
        deleteStart();
        return;
    }

    Node* temp = head;

    for (int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position!\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

// Display list
void display() {
    Node* temp = head;

    if (temp == NULL) {
        cout << "List is empty\n";
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of initial nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertEnd(x);
    }

    int choice, val, pos;

    while (true) {
        cout << "\n1. Insert Start\n2. Insert End\n3. Insert After Kth Node\n";
        cout << "4. Delete Start\n5. Delete End\n6. Delete Kth Node\n7. Display\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertStart(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertEnd(val);
                break;

            case 3:
                cout << "Enter position k and value: ";
                cin >> pos >> val;
                insertAfterK(pos, val);
                break;

            case 4:
                deleteStart();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                cout << "Enter position k: ";
                cin >> pos;
                deleteK(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}