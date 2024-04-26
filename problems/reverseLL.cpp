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
    ~Node()
    {
        cout << "destructor called for : " << this->data << endl;
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

Node *reverseLL(Node *head)
{
    // iterative approach
    Node *prev = NULL;
    Node *curr = head;
    Node *next = curr->next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *reverseLL2(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverseLL2(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 45);
    insertAtHead(head, tail, 35);
    insertAtHead(head, tail, 56);
    printLL(head);
    cout << "After reversing the linked list" << endl;
    Node *newHead = reverseLL(head);
    printLL(newHead);
    cout << "After reversing the linked list recursive way" << endl;
    Node *rev = reverseLL2(newHead);
    printLL(rev);
}