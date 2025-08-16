/*
we are given the singly LL
whenever we have to find the middle node
* remember this :
    - we don't have to try to reach the mid node of the instead of doing this we have to reach at the one node before the middle one because we have to link this node to the next of the middle node .

# Brute Approach :
1. find the length (by traversing the entire list)
2. get the res n/2 and do res-- and if res = 0 then we are actually at the one node before of the  middle so here arrange the links and free the middle node

time complexity : O(n)+ O(n/2)
space complexity : O(1)


optimal approach : using two pointer(tortoise and hare) 
- slow and fast 
- slow move one step and fast two step but first time skip the one step of the slow to get the one node before the middle (in case of even and odd both list)

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

Node *insert_end(Node *head, int ele)
{
    if (head == NULL)
        return head;

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(ele);
    temp->next = newNode;
    return head;
}

void traverseLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

// brute approach
Node *delete_middle(Node *head)
{

     if(head == NULL && head->next == NULL) return NULL ;
    Node *temp = head;
    int N = 0;
    while (temp)
    {
        N++;
        temp = temp->next;
    }

    int res = N / 2;
    temp = head;
    while (temp)
    {
        res--;
        if (res == 0)
        {
            Node *middle = temp->next;
            temp->next = temp->next->next;
            free(middle);
            break;
        }
        temp = temp->next;
    }

    return head;
}

// optimal approach - two pointer approach
Node *delete_middle_node(Node *head)
{

    if(head == NULL && head->next == NULL) return NULL ;
    Node *slow = head;
    Node *fast = head;
    fast = fast->next->next;
    while (fast != NULL && fast ->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *middle = slow->next;
    slow->next = slow->next->next;
    free(middle);
    return head;
}

int main()
{
    Node *head = new Node(2);
    insert_end(head, 3);
    insert_end(head, 5);
    insert_end(head, 7);
    insert_end(head, 6);

    traverseLL(head);
    // head = delete_middle(head);

    // traverseLL(head);

    head = delete_middle_node(head);
    traverseLL(head);
    return 0;
}