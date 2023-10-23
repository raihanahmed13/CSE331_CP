#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
node* buildTree(node* root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrder(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }

}
void boundryLeft(node* root) {
    if (root == NULL)
        return;

    if (root->left) {
        cout << root->data << " ";
        boundryLeft(root->left);
    }
    else if (root->right) {
        cout << root->data << " ";
        boundryLeft(root->right);
    }
}
void boundryLeaf(node* root) {
    if (root == NULL) {
        return;
    }
    boundryLeaf(root->left);

    if (!root->left && !root->right) {
        cout << root->data << " ";
    }
    boundryLeaf(root->right);
}

void boundryRight(node* root) {
    if (root == NULL)
        return;

    if (root->right) {

        boundryRight(root->right);
        cout << root->data << " ";
    }
    else if (root->left) {
        boundryRight(root->left);
        cout << root->data << " ";
    }
}


void boundryOrder(node* root) {
    if (root == NULL) {
        cout << "Nothing to print";
    }
    cout << root->data << " ";

    boundryLeft(root->left);

    boundryLeaf(root->left);
    boundryLeaf(root->right);

    boundryRight(root->right);


}


int main()
{
    node* root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1  copy and paste in the input for building tree
    //  level Order traversal
    cout << "Levelorder tarversal: " << endl;
    levelOrder(root);
    cout << endl;
    cout << "Boundry Order tarversal: " << endl;
    boundryOrder(root);
    cout << endl;
}
