/*
Reverse the singly linked list by using iterative as well as recursive method

#Iterative :
Brute approach :
1. traverse the list and push the ele into the stack .
2. again temp  point to head and insert the top of the stack in the list and pop it
3. hence time complexity : O(2N)
    - space complexity : O(N)

Optimal Approach:
1. instead of changing the data here we are changing the links in the list
2. creating prev = null
          temp = head
          front  = temp->next
3. repeat this process until temp !=null
4. return prev (it becomes head now )

time complexity : O(N)
space complexity : O(1)


Recursive :
time complexity : O(N)
space complexity : O(N) -
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// brute approach
Node *ReverseList(Node *head)
{
    Node *temp = head;
    stack<int> s;

    // traversing the entire list and pushing the data into the stack
    while (temp)
    {
        s.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    // inserting the data in the list by taking the top of the stack
    while (temp)
    {
        temp->data = s.top();
        s.pop();
        temp = temp->next;
    }

    return head;
}

// optimal approach - Iterative method

Node *ReverseLL(Node *head)
{
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {

        // in each iteration at a time only one node get reversed 
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

// Recursive method
Node *ReverseLinkedList(Node *head)
{
    // when one or no any node is present
    if (head == nullptr || head->next == nullptr)
        return head;

    // newHead that act as a head in reverse list
    Node *newHead = ReverseLinkedList(head->next);

    // front which point to head->next
    Node *front = head->next;
    
    // we have to link the front next with the head
    front->next = head;
    //  where head  points to null on reverse
    head->next = nullptr;

    return newHead;
}


Node *insert_end(Node *head, int element)
{
    if (head == NULL)
    {
        return new Node(element);
    }

    // common condition
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(element);
    temp->next = newNode;

    return head;
}

void traverseLL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null";
}

int main()
{

    int n;
    cin >> n;
    Node *head = new Node(10);
    insert_end(head, 4);
    insert_end(head, 7);
    insert_end(head, 20);
    insert_end(head, 6);
    insert_end(head, 15);

    traverseLL(head);
    cout << endl;
    // Node *res = ReverseLL(head);
    // traverseLL(res);

    //    head  = ReverseList(head);
    //     cout<<endl;
    //     traverseLL(head);
    head = ReverseLinkedList(head);
    cout << endl;
    traverseLL(head);
    return 0;
}