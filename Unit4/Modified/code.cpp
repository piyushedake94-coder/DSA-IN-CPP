
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

Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

int findMin(Node* root) {
    int comparisons = 0;

    cout << "\nPath to Minimum: ";
    Node* temp = root;

    while (temp != NULL) {
        cout << temp->data;
        comparisons++;

        if (temp->left != NULL) {
            cout << " -> ";
            temp = temp->left;
        } else {
            break;
        }
    }

    cout << "\nMinimum Element: " << temp->data;
    cout << "\nComparisons for Minimum: "
         << comparisons << endl;

    return temp->data;
}

int findMax(Node* root) {
    int comparisons = 0;

    cout << "\nPath to Maximum: ";
    Node* temp = root;

    while (temp != NULL) {
        cout << temp->data;
        comparisons++;

        if (temp->right != NULL) {
            cout << " -> ";
            temp = temp->right;
        } else {
            break;
        }
    }

    cout << "\nMaximum Element: " << temp->data;
    cout << "\nComparisons for Maximum: "
         << comparisons << endl;

    return temp->data;
}

int main() {
    Node* root = NULL;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive number.\n";
        return 0;
    }

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    findMin(root);
    findMax(root);

    return 0;
}
