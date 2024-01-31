#include <iostream>

using namespace std;
class node
{
public:
    int data;
    node *next;
};
class Queues
{
public:
    node *front = new node();
    Queues()
    {
        front = NULL;
    }

    bool isempty()
    {
        return front == NULL;
    }

    void enqueue(int value)
    {
        node *temp = front;
        node *newnode = new node();
        newnode->data = value;
        if (isempty())
        {
            newnode->next = NULL;
            front = newnode;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            newnode->next = NULL;
            temp->next = newnode;
        }
    }

    void dequeue()
    {
        if (isempty())
        {
            cout << "you con't delete item the queue is empty.\n";
        }
        else
        {
            node *delptr = new node();
            delptr = front;
            front = front->next;
            delete[] delptr;
        }
    }

    int peek()
    {
        if (isempty())
        {
            cout << "the queue is empty : ";
            return 0; // or any other suitable value to indicate an empty stack
        }
        else
        {
            return front->data;
        }
    }
    int gettail()
    {
        node* temp = front;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    int count()
    {
        int point = 0;
        node *temp = front;
        while (temp != NULL)
        {
            point++;
            temp = temp->next;
        }
        return point;
    }

    bool isfound(int value)
    {
        node* temp = front;
        while (temp != NULL)
        {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    void display()
    {
        if (isempty())
        {
            cout << "the queue is empty : ";
        }
        else
        {
            node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }


    void clear()
    {
        while(!isempty())
        {
            dequeue();
        }
    }
};
int main()
{
    Queues qu;
    int value;

    cout << "enter the number you went add the queue.\n";
    cin >> value;
    qu.enqueue(value);

    cout << "enter the number you went add the queue.\n";
    cin >> value;
    qu.enqueue(value);

    cout << "enter the number you went add the queue.\n";
    cin >> value;
    qu.enqueue(value);

    qu.display();

    cout << "\ndelete the first item.\n";
    qu.dequeue();

    qu.display();

    cout << "\nthe value of the first item is : "<< qu.peek() << endl;
    cout << qu.count() << endl;

    cout << "enter the number you went sreach the queue.\n";
    cin >> value;
    cout << (qu.isfound(value) == 1 ? "the item is found." : "the item is not found.") << endl;

    cout << qu.gettail() << endl;
    qu.clear();
    cout << (qu.isempty() ? "the queue is empty." : "the queue is not empty.") << endl;
}
