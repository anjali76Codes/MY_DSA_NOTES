#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data1, Node *left1, Node *right1)
    {
        data = data1;
        left = left1;
        right = right1;
    }

    Node(int data1)
    {
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};

void inOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";

    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

Node *createTree()
{
    Node *root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(9);

    root->left->left = new Node(7);
    root->left->left->left = new Node(8);

    root->right->right = new Node(10);
    root->right->right->right = new Node(11);

    return root; // Return the root of the tree
}

int main()
{
    Node *root = createTree();
    cout << "Inorder Traversal: " << endl;
    preOrderTraversal(root);
    cout << endl;
    inOrderTraversal(root);

    cout << endl;
    postOrderTraversal(root);

    return 0;
}