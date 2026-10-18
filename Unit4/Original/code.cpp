#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert an element into the BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find minimum by traversing leftmost nodes
int findMin(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!\n";
        return -1;
    }

    while (root->left != NULL)
        root = root->left;

    return root->data;
}

// Find maximum by traversing rightmost nodes
int findMax(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!\n";
        return -1;
    }

    while (root->right != NULL)
        root = root->right;

    return root->data;
}

int main() {
    Node* root = NULL;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive number of elements.\n";
        return 0;
    }

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nMinimum element: " << findMin(root) << endl;
    cout << "Maximum element: " << findMax(root) << endl;

    return 0;
}
