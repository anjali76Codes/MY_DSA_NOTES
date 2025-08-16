/*
Sort 0's 1's 2's in linked list
=====================================

Brute Approach :
1. create three cnt that stores count of 0 , 1 ,2
2. traverse the linked list and count the number of 0 , 1 ,2
3. check if cnt0 , cnt1 , cnt2  and accordingly replace the 0 , 1, 2

time complexity : O(2N)
space complexity : O(1)



optimal approach :
1. create three dummy node that store the total 0 , 1, 2 respectively.
2. three variable that point to head of each
3. by traversing get three list and by arranging links attached them
4. delete the dummy nodes

time complexity : O(N)
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
        next = nullptr;
    }
};

// brute approach
Node *SortLL(Node *head)
{
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    Node *temp = head;

    // traverse the entire list and keep the track of the 0's 1's and 2's
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            cnt0++;
        }

        else if (temp->data == 1)
        {
            cnt1++;
        }

        else
        {
            cnt2++;
        }

        temp = temp->next;
    }

    // assign again temp = head
    temp = head;
    // if any of the cnt is remaining
    while (temp != nullptr)
    {
        if (cnt0)
        {
            // replace the data with 0
            temp->data = 0;
            cnt0--;
        }

        else if (cnt1)
        {
            // replace the data with 1
            temp->data = 1;
            cnt1--;
        }

        else
        {
            // replace the data with 2
            temp->data = 2;
            cnt2--;
        }

        // go to the next node
        temp = temp->next;
    }

    return head;
}

Node *sortList(Node *head)
{
    // dummy nodes for all 0's , 1's ,2's
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    // three pointers that point each head respectively
    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;

    // traversing the main list
    Node *temp = head;
    while (temp)
    {
        // if the data is 0 , add it to the zero list
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }

        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }

        else
        {
            two->next = temp;
            two = two->next;
        }
        // move to the next node
        temp = temp->next;
    }

    // establish the link connection between the all three nodes
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;

    one->next = twoHead->next;
    two->next = nullptr;

    // new head that points the new list after the link done in all the nodes
    Node *newHead = zeroHead->next;

    // delete the dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
}

// optimal approach

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
    Node *head = new Node(1);
    insert_end(head, 1);
    insert_end(head, 0);
    insert_end(head, 2);
    insert_end(head, 0);
    insert_end(head, 0);

    traverseLL(head);

    Node *sortedList = SortLL(head);
    cout << endl;
   

    traverseLL(sortedList);

    
    Node *Res = sortList(head);
    cout<<endl;
    traverseLL(Res);
        
}