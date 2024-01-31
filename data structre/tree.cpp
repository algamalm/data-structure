#include <iostream>
using namespace std;
class node
{
public:
    int data = 0;
    node *left = NULL;
    node *right = NULL;
};
class tree
{
public:
    node *root = new node();
    tree()
    {
        root = NULL;
    }

    bool isempty()
    {
        return root == NULL;
    }

    node *insert(node *r, int value)
    {
        node *newnode = new node();
        newnode->data = value;
        if (r == NULL)
        {
            r = newnode;
        }
        else if (value < r->data)
        {
            r->left = insert(r->left, value);
        }
        else if (value >= r->data)
        {
            r->right = insert(r->right, value);
        }
        return r;
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void pre_order(node *r) // root - left - right
    {
        if (r == NULL)
            return;
        cout << r->data << endl;
        pre_order(r->left);
        pre_order(r->right);
    }
    void in_order(node *r) // left - root - right
    {
        if (r == NULL)
            return;
        in_order(r->left);
        cout << r->data << endl;
        in_order(r->right);
    }
    void post_order(node *r) // left - right - root
    {
        if (r == NULL)
            return;
        post_order(r->left);
        post_order(r->right);
        cout << r->data << endl;
    }
    void pre_order()
    {
        pre_order(root);
    }
    void in_order()
    {
        in_order(root);
    }
    void post_order()
    {
        post_order(root);
    }

    node *search(node *r, int value)
    {
        if (r == NULL)
        {
            return NULL;
        }
        else if (value == r->data)
        {
            return r;
        }
        else if (value < r->data)
        {
            return search(r->left, value);
        }
        else if (value > r->data)
        {
            return search(r->right, value);
        }
    }
    bool search(int value)
    {
        node *result = search(root, value);
        return result == NULL;
    }

    node *minimum(node *r)
    {
        if (r == NULL)
            return NULL;
        else if (r->left == NULL)
            return r;
        else
            return minimum(r->left);
    }
    node *maximum(node *r)
    {
        if (r == NULL)
            return NULL;
        else if (r->right == NULL)
            return r;
        else
            return maximum(r->right);
    }
    node *Delete(node *r, int value)
    {
        if (r == NULL)
            return NULL;
        else if (value < r->data)
            r->left = Delete(r->left, value);
        else if (value > r->data)
            r->right = Delete(r->right, value);
        else
        {
            if (r->left == NULL && r->right == NULL)
            {
                r = NULL;
            }
            else if (r->left == NULL && r->right != NULL)
            {
                node *min = minimum(r->right);
                r->data = min->data;
                r->right = Delete(r->right, min->data);
            }
            else
            {
                node *max = maximum(r->left);
                r->data = max->data;
                r->left = Delete(r->left, max->data);
            }
        }
        return r;
    }
    int sumTheTreeValues(node *root)
    {
        if (root == nullptr)
            return 0;
        else
            return root->data + sumTheTreeValues(root->left) + sumTheTreeValues(root->right);
    }
    int sumTheTreeValues()
    {
        return sumTheTreeValues(root);
    }
};
int main()
{
    tree tr;
    int value = 0;
    for (int i = 0; i < 7; i++)
    {
        cout << "inter the value you went add in tree." << endl;
        cin >> value;
        tr.insert(value);
    }
    cout << "=========\n";
    tr.in_order();
    cout << tr.sumTheTreeValues() << endl;
    cout << "enter the item you went delete.\n";
    cin >> value;
    tr.Delete(tr.root, value);
    cout << "=========\n";
    tr.in_order();
    return 0;
}