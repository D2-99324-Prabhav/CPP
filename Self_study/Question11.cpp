#include<iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

    friend class LinkedList;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList(void) : head(NULL)
    {   }

    void add_first(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void add_last(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void display(void)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list1;
    list1.add_last(10);
    list1.add_last(20);
    list1.add_last(30);
    list1.add_first(5);
    list1.display();

    return 0;
}