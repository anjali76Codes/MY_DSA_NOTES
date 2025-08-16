/*
Deletion of singly linked list
    - del head
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

Node *arrToLinkedList(vector<int> &arr, int n)
{
    // 1. head point to 1st ele of the array
    Node *head = new Node(arr[0]);
    Node *mover = head;
    // 2. traverse the array and add each element to the linked list
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// 1. delete head from the LL
Node *deleteHead(Node *head)
{

    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// 2. delete the tail
Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}

// 3. delete the kth node
Node *deleteKthNode(Node *head, int k)
{
    // when LL is empty
    if (head == NULL)
        return head;

    // when we have to remove the first node
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // when k is in between
    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = temp->next;
            delete temp;
            break ;
        }
        prev = temp;

        // before moving the temp to next update the prev to track the previous node
        temp = temp->next;
    }
    return head ;
}
Node *deleteValue(Node *head, int val)
{
    // when LL is empty
    if (head == NULL)
        return head;

    // when we have to remove the first node
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // when k is in between
    // int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        // cnt++;
        if (temp->data == val)
        {
           prev ->next = temp->next ; 
            delete temp;
            break ;
        }
        prev = temp;

        // before moving the temp to next update the prev to track the previous node
        temp = temp->next;
    }
    return head ;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ->";
        head = head->next;
    }
    cout << "null" << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // create the LL
    Node *head = arrToLinkedList(arr, n);

    // Delete the head node
    head = deleteHead(head);

    // Delete the tail node
    // head = deleteTail(head);
    // head = deleteKthNode(head , 3);
   head =  deleteValue(head , 7);

    // Print the updated linked list
    printList(head);
}