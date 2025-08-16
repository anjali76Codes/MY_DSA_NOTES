/*
Rotate  the Linked list by k

#optimal approach
- traverse and calculate the len
-  if k = len that means multiples of k  for this no need to rotate it because it return the original
(Ex. len = 5 and l = 10 then 5->return original then 5+5 also return original )

- for smaller value  and higher value
    - find len- k -> res is my new last node on kth rotation
    so update the head i.e head = newLastNode->next
    newLastNode->next = null

return head

time complexity : O(2N)
space complexity : O(1)

*/


#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1,  Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};


// Function to insert a node at the end of the linked list
Node* insert_at_end(Node* head, int ele) {
    Node* new_node = new Node(ele);
    if (head == nullptr) {
        return new_node;  // If the list is empty, return the new node as the head
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Function to traverse and print the linked list
void traverseLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}



Node *findNthNode(Node *head, int N)
{
    Node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        if (count == N)
        {
            break ;
        }
        temp = temp->next;
    }
    return temp;
}

Node *Rotate_by_k(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr || k == 0)
        return head;

    int len = 1;
    Node *tail = head;
    //  traverse till end not beyond the end and find the list length
    while (tail->next != nullptr)
    {
        len++;
        tail = tail->next;
    }

    // when given k is multiples of len
    if (k % len == 0)
        return head;

    // update the k when it is bigger/smaller  (not equal to len)
    k = k % len;

    // we need to find the that nth node  which will be our  new last node
    Node *newLastNode = findNthNode(head, len - k);
    
    // above we got the last node after the rotation so update the head now 
    head = newLastNode->next ; 
    // now we need to update the next of the new last node to null
    newLastNode->next = nullptr;
    
    return head ;

}

int main()
{

    Node* head = new Node(2);
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);
    head = insert_at_end(head, 6);

    head = Rotate_by_k(head , 2);           
    traverseLL(head);
        return 0;
}
