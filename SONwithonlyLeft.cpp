#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left, * right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* insert(Node* root, int val) {
    if (root == NULL) {
        Node* newNode = new Node(val);
        return newNode;
    }
    if (val <= root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }
}

int calcSum(Node* root)
{
    if (root == NULL)
        return 0;

    int left = calcSum(root->left);

    int right = calcSum(root->right);

    if (root->left != NULL && root->right == NULL)
    {

        return root->data + left + right;
    }

    return left + right;
}
int main() {
    Node* root = new Node(100);
    root->left = new Node(70);
    root->right = new Node(110);
    root->left->left = new Node(65);
    root->left->right = new Node(90);
    root->right->left = new Node(105);
    root->left->left->left = new Node(60);
    root->left->right->left = new Node(85);
    root->left->right->right = new Node(95);
    root->left->right->left->left = new Node(80);

    cout << "Sum of Nodes having only left child: " << endl;
    cout << calcSum(root);


}