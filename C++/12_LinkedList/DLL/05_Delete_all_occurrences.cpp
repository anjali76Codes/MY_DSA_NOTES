/*
Delete all occurrences of a key in DLL
we are given the key we have to check and delete it and get the final LL

Optimal Approach :
time complexity : O(N)
space complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

public:
    Node(int data1, Node *prev1, Node *next1)
    {
        data = data1;
        prev = prev1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

Node *Array_To_DLL(vector<int> &arr)
{

    // first node
    Node *head = new Node(arr[0]);
    Node *temp = head;

    // insert remaining ele
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i], temp, nullptr);

        // to link with first node add prev and next
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

// optimal approach
Node *Delete_all_occurrences_key(Node *head, int key)
{

    // creating a temp point to head(first node)
    Node *temp = head;

    // traversing temp till end
    while (temp)
    {

        // if  temp->data equals to key then
        if (temp->data == key)
        {

            // first we have to check if our temp is equals to head if yes then update the head
            if (temp == head)
            {
                head = head->next;
            }

            // create two nodes to track the prev and next
            Node *prevNode = temp->prev;
            Node *nextNode = temp->next;

            // establishing the links between the nodes because we have to delete the node which are found equal to key




            // check prev is not equal to null
            if (prevNode)
                prevNode->next = nextNode;

                // check nextNode is not equal to null
            if (nextNode)
                nextNode->prev = prevNode;

            // delete the all occurrences of key
            free(temp);
            // move the temp to next that is nextNode
            temp = nextNode;
        }

        else{
            temp = temp->next;
        }
    }

    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

int main()
{
    vector<int> arr = {10, 20, 30, 30, 50, 30, 40};
    Node *head = Array_To_DLL(arr);
    printList(head);

    head = Delete_all_occurrences_key(head, 30);
    printList(head);

    return 0;
}
