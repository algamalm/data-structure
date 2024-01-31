#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head = new Node();
    LinkedList()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void insertFirst(int value)
    {
        Node *newnode = new Node(); // Create a new node
        newnode->data = value;
        newnode->next = head;
        head = newnode;
    }

    void insertbefore(int item, int value)
    {
        if (isFound(item))
        {
            Node *temp = head;
            Node *newnode = new Node();
            newnode->data = value;
            while (temp != NULL && temp->next->data != item)
            // when next->data equal item the loop is stop this is required
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        else
        {
            cout << "the item if not found.\n";
        }
    }

    void insertlast(int value) // append
    {
        Node *temp = head;
        Node *newnode = new Node();
        newnode->data = value;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "the stack is empty.\n";
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }

    int count()
    {
        int count = 0; // Initialize count to 0
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool isFound(int value)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void Deletefirst()
    {
        if (isEmpty())
        {
            cout << "the linked list is empty you con't detet";
        }
        else
        {
            Node *delptr = head;
            head = head->next;
            delete[] delptr;
        }
    }

    void Deleteitem(int item)
    {
        if (isEmpty())
        {
            cout << "the linked list is empty you con't detet";
        }
        else
        {
            if(head->data == item)
            {
                Deletefirst();
            }
            else if (isFound(item))
            {
                Node *temp = head;
                Node *delptr = new Node();
                while (temp != NULL && temp->next->data != item)
                // when next->data equal item the loop is stop this is required
                {
                    temp = temp->next;
                }
                delptr->next = temp->next;
                temp->next = temp->next->next;
                delete[] delptr;
            }
            else
            {
                cout << "the item if not found.\n";
            }
        }
    }
};

int main()
{
    LinkedList link;
    cout << (link.isEmpty() ? "The linked list is empty.\n" : "The linked list contains.\n");

    int value = 0;
    cout << "Enter the new value: ";
    cin >> value;
    link.insertFirst(value);

    cout << "Enter the new value: ";
    cin >> value;
    link.insertFirst(value);

    int it;
    cout << "enter the item and value you went insert before." << endl;
    cin >> it >> value;
    link.insertbefore(it, value);

    link.display();

    cout << "enter the value you went insert in the last.\n";
    cin >> value;
    link.insertlast(value);

    cout << "==============\n";
    link.display();

    cout << "enter the value you went delete.\n";
    cin >> value;
    link.Deleteitem(value);

    cout << "==============\n";
    link.display();

    cout << "will delete the first item." << endl;
    link.Deletefirst();

    cout << "==============\n";
    link.display();    

    cout << "enter the value you went to sreach.\n";
    cin >> value;
    cout << link.isFound(value);
    return 0;
}