#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
node *buildTree(node *root)
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

void levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
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

void inorder(node *root)
{
    stack<node *> s;
    node *curr = root;

    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();

        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preorder(node *root)
{
    if (root == NULL)
        return;

    stack<node *> st;
    node *curr = root;
    while (!st.empty() || curr != NULL)
    {

        while (curr != NULL)
        {
            cout << curr->data << " ";

            if (curr->right)
                st.push(curr->right);

            curr = curr->left;
        }
        if (!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
}

void postorder(node *root)
{
    node *curr = root;
    stack<node *> st;
    while (true)
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty())
                break;
            curr = st.top()->right;
            if (curr == nullptr)
            {
                node *temp = nullptr;
                while (!st.empty() && st.top()->right == temp)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
        }
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1  copy and paste in the input for building tree
    //  level Order traversal
    cout << "Levelorder tarversal: " << endl;
    levelOrder(root);
    cout << endl;

    // inorder traversal  (LNR)
    cout << "Inorder Traversal: " << endl;
    inorder(root);
    cout << endl;

    // preorder traversal (NLR)
    cout << "Preorder Traversal: " << endl;
    preorder(root);
    cout << endl;

    // postorder traversal (LRN)
    cout << "Postorder Traversal: " << endl;
    postorder(root);
}
