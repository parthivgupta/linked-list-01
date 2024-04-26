#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
int getLength(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << "length of linked list is : " << count << endl;
    return count;
};

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // case for empty LL
        // step 1 : create a new node
        Node *newNode = new Node(data);
        // 2 -> update the head
        head = newNode;
        tail = newNode;
    }
    else
    {
        // non empty case;
        Node *newNode = new Node(data);
        // join the new node to head node
        newNode->next = head;
        // update head
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // empty ll
        Node *newNode = new Node(data);
        // single node hai entire list thats why
        // head and tail ko ispar point krna hoga
        head = newNode;
        tail = newNode;
    }
    else
    {
        // create a new node
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}
void createTail(Node *head, Node *tail)
{
    Node *temp = tail;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    int length = getLength(head);
    if (position == 1)
    {
        insertAtHead(head, tail, data);
    }
    else if (position == length + 1)
    {
        insertAtTail(head, tail, data);
    }
    else
    {
        // create a node
        Node *newNode = new Node(data);
        // 2 -> traverse pre // cur to position
        Node *prev = NULL;
        Node *curr = head;
        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        // step 3 -> attach prev to new node
        prev->next = newNode;
        // step - 4 attack new node to curr;
        newNode->next = curr;
    }
}

int main()
{
    // Node *first = new Node(12);
    // Node *second = new Node(11);
    // Node *third = new Node(15);
    // Node *fourth = new Node(9);
    // Node *fifth = new Node(11);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;

    // Node *head = first;
    // Node *tail = fifth;
    // printLL(head);
    // cout << endl;

    // getLength(head);
    // cout << endl;
    // // inserting at the beginning of the list
    // insertAtHead(head, tail, 100);
    // printLL(head);
    // cout << endl;

    // getLength(head);
    // // inserting at last of the linked list
    // insertAtTail(head, tail, 200);
    // printLL(head);
    // getLength(head);
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtTail(head, tail, 50);
    insertAtPosition(head, tail, 70, 4);
    printLL(head);
}