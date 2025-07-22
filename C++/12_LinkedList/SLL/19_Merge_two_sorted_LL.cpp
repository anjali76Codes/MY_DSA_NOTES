/*
Merged two sorted linked list

#Brute Approach :
- first insert the first list then 2nd list into an array
- sort the array
- convert the array to LL

time complexity : O(N1)+O(N2)+ O(NlogN)+ O(N)
space complexity : O(N)

#Optimal approach :  using two pointer approach
- start two pointers at the head of both lists
- compare the values of the nodes
- if first list node is smaller then other then link this to dummy node and move temp1 to next
- else link the second list node to dummy node and move temp2 to next
- return dummy node.next(which is head of the list)

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
        next = nullptr;
    }
};

Node *convert_arr_LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        // Update the node's data
        // with the sorted values
        temp->next = new Node(arr[i]);
        // Move to the next node
        temp = temp->next;
    }
    return head;
}

// brute approach
// using Brute Force approach
Node *mergesortLL(Node *head1, Node *head2)
{
    // Create a vector to store node values
    vector<int> arr;

    // Temporary pointer to traverse the linked list
    Node *temp1 = head1;
    Node *temp2 = head2;

    // Traverse the linked list and store node values in the vector
    while (temp1 != NULL)
    {
        arr.push_back(temp1->data);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        arr.push_back(temp2->data);
        temp2 = temp2->next;
    }

    // Sort the array containing node values
    sort(arr.begin(), arr.end());

    // Reassign sorted values to
    // the linked list nodes
    return convert_arr_LL(arr);
}




// optimal approach 
Node* mergeTwoSortedLinkedLists(Node* head1, Node* head2) {
    // Create a dummy node to  return the head of the merged list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Traverse both lists simultaneously
    while (head1 != nullptr && head2 != nullptr) {
        // Compare elements of both lists and link the smaller node to the merged list current node(which one is smaller)
        if (head1->data <= head2->data) {
            temp->next = head1;

            // move the first list pointer (the list which is smaller move only its pointer)
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }

        // Move the temporary pointer to the next node
        temp = temp->next; 
    }

  // if any list is remaining then link this remaining 
    if (head1 != nullptr) {
        temp->next = head1;
    } else {
        temp->next = head2;
    }
    

    return dummyNode->next;
}


// Function to insert a node at the end of the linked list
Node *insert_at_end(Node *head, int ele)
{
    Node *new_node = new Node(ele);
    if (head == nullptr)
    {
        return new_node; // If the list is empty, return the new node as the head
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Function to traverse and print the linked list
void traverseLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

int main()
{
    Node *head1 = new Node(2);
    head1 = insert_at_end(head1, 3);
    head1 = insert_at_end(head1, 4);
    head1 = insert_at_end(head1, 5);
    head1 = insert_at_end(head1, 6);

    Node *head2 = new Node(1);
    head2 = insert_at_end(head2, 3);
    head2 = insert_at_end(head2, 5);
    head2 = insert_at_end(head2, 8);
    head2 = insert_at_end(head2, 9);

    traverseLL(head1);
    traverseLL(head2);

    Node *head = mergesortLL(head1, head2);
    traverseLL(head);

  head = mergeTwoSortedLinkedLists(head1, head2);
    traverseLL(head);


    return 0;
}