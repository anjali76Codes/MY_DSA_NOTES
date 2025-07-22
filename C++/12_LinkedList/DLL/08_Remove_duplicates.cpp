/*
Remove duplicates from the list
list should be in sorted order

#Optimal Approach :
after visualization we can see the outer loop skip the duplicates and traverse only on unique node and inner loop is traverse only on duplicates node so the overall complexity is : 
- time complexity : O(n/2) + O(n/2) -> O(n)
- space complexity : O(1)
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

// optimal approach
Node *Remove_Duplicates(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }

    Node *temp = head;
    // traverse the list
    while (temp != nullptr && temp->next != nullptr)
    {

        // create a nextNode which points to next node for comparing
        Node *nextNode = temp->next;

        // traverse till nextNode becomes null and its data is  equals to temp data
        while (nextNode != nullptr && nextNode->data == temp->data)
        {

            Node *duplicate = nextNode;

            // if temp data is equal to nextNode data then remove it and go to the next node
            nextNode = nextNode->next;
            delete duplicate;
        }


// temp next point to nextNode which is the current node when it not found duplicate 
        temp->next = nextNode ; 
       if(nextNode) nextNode->prev = temp ; 
        temp = temp->next ; 
    }
    return head ;
}

int main()
{
    vector<int> arr = {10, 20,20 , 20 , 30,40 , 40  };
    Node *head = Array_To_DLL(arr);
    printList(head);
head = Remove_Duplicates(head);
printList(head);

    return 0;
}