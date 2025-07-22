/*
Steps :
1. initialize carry = 0 , create a dummy node and current
2. dummy = -1 and curr = dummy
3. initialize sum = carry
4 . create two temp1 and temp2 to traverse the both list
5. while(temp1 != NULL && temp2 != NULL)
    #check conditions 
6. sum = temp1->data + temp2->data + carry
7. carry = sum/10
8. curr->data = sum%10


 Time complexity -> O(max(n1,n2))
 Space complexity -> O(max(n1,n2)) 



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

// Add two list
Node *add_two_list(Node *head1, Node *head2)
{
    int carry = 0;
    // initialize two node to traverse the list
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *dummy = new Node(-1);
    Node *curr = dummy;

    // traverse the list
    while (temp1 != NULL || temp2 != NULL)
    {
        int sum = carry;
        if (temp1)
        {
            sum += temp1->data;
            temp1 = temp1->next;
        }

        if (temp2)
        {
            sum += temp2->data;
            temp2 = temp2->next;
        }
        // return carry
        carry = sum / 10;

        // modulo return the remainder (or we can 0th digit  ) curr node traverse and added the sum of the list
        curr->next = new Node(sum % 10);
        curr = curr->next;
    }

    // check if there is any carry or not if yes then add this
    if (carry)
    {
        // add the carry by creating the new node
        Node *newNode = new Node(carry);
        // point the current to this node
        curr->next = newNode;
    }

    return dummy->next;
}

Node *insert_end(Node *head, int ele)
{
    if (head == nullptr)
        return head;

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(ele);
    temp->next = newNode;
    return head;
}

// print the list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null";
}

int main()
{
    // head creation for both the linked list
    // for 1st list
    Node *head1 = new Node(1);
    head1 = insert_end(head1, 2);

    // for 2nd list
    Node *head2 = new Node(3);
    head2 = insert_end(head2, 6);
    head2 = insert_end(head2, 4);
    head2 = insert_end(head2, 9);

    // print list1
    printList(head1);

    cout << endl;
    // print list2
    printList(head2);
    Node *head = add_two_list(head1, head2);
      cout << endl;
    printList(head);

    return 0;
}