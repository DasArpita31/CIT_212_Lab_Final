#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node* createTree() {
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node* newNode = new Node(x);

    cout << "Left child of " << x << ": ";
    newNode->left = createTree();

    cout << "Right child of " << x << ": ";
    newNode->right = createTree();

    return newNode;
}

int main() {
    cout << "Enter tree nodes (-1 for NULL):\n";

    Node* root = createTree();

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}