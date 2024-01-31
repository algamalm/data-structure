#include <iostream>
using namespace std;
#include <exception>
class node
{
public:
    int data;
    node *next;
};

class stack
{
public:
    node *top = new node();
    stack()
    {
        top = NULL;
    }

    void push(int value)
    {
        node *newnode = new node(); // Create a new node
        newnode->data = value;
        newnode->next = top;
        top = newnode;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "the stack is empty you con't detet";
        }
        else
        {
            node *delptr = top;
            top = top->next;
            delete[] delptr;
        }
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    bool isfound(int item)
    {
        node *temp = top;
        while (temp != NULL)
        {
            if (temp->data == item)
                return true;
            temp = temp->next;
        }
        return false;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "the stack is empty : ";
            return 0; // or any other suitable value to indicate an empty stack
        }
        else
        {
            return top->data;
        }
    }

    int count()
    {
        int point = 0;
        node *temp = top;
        while (temp != NULL)
        {
            point++;
            temp = temp->next;
        }
        return point;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "the stack is empty.\n";
        }
        else
        {
            node *temp = top;
            cout << "the items in the stack.\n";
            while (temp != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};
int main()
{
    stack s;
    cout << s.peek() << endl;
    int value = 0;
    for (int i = 0; i < 4; i++)
    {
        cout << "enter the value you went to push.\n";
        cin >> value;
        s.push(value);
    }
    s.display();

    cout << "enter the 1 if you went delete the item or any number if you don't went delete the item.\n";
    cin >> value;
    if (value == 1)
    {
        s.pop();
        s.display();
    }

    cout << "the value of top elements is : " << s.peek() << endl;

    cout << "the count in the stack is : " << s.count() << endl;

    cout << "enter the value you went to found.\n";
    cin >> value;
    if (s.isfound(value))
    {
        cout << "the item is found.\n";
    }
    else
    {
        cout << "the item is not found.\n";
    }
}