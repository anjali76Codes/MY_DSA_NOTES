/*
find middle of the node
if number of nodes are even then there are two node which lie on same so in this case take right side node

expression : (n/2 +1) node will always be a middle of the LL


simplest way :
1. find the n -> length of the node
2. find the middle node using n/2 +1 expression
3. again point temp to head and decrease the middle node cnt by 1
    -if(middleNode == 0 ) break
3. return the middle node

time complexity : O(N+N/2)
space complexity :  O(1)


optimAL Approach : 
time complexity : O(n/2)
space complexity : O(1)
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
        next = NULL;
    }
};

// array to linked list
Node *Array_to_LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);

        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

// find the middle of the node
Node *findMiddle(Node *head)
{
    // 1. find total length of the node
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    // use the expression that return the middle node
    int mid = len / 2 + 1;

    // assign temp again to head to return the middle node
    temp = head;
    while (temp != NULL)
    {
        mid--;
        if (mid == 0)
            break;

        temp = temp->next;
    }

    return temp;
}

// optimal approach
Node *findMiddleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// print the list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null";
}

int main()
{
    vector<int> arr = {10, 20, 30, 45, 50};
    Node *head = Array_to_LL(arr);
    printList(head);

    Node* middleNode = findMiddle(head);

    cout<<endl<<middleNode->data<<"";

    Node *middleN = findMiddleNode(head);
    cout << endl<< middleN->data << "";
}
