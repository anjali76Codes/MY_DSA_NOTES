/*
Reverse DLL

# Brute Approach :
1. traverse a list and push all data one by one into the stack (LIFO)
2. Again in the list insert the top of the stack and pop the stack ele one by one so that we get the reverse of DLL.

Time Complexity : O(2N)
Space Complexity : O(N)


#Optimal Approach :
Time Complexity : O(N)
Space Complexity : O(1)

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



Node *Reverse_DLL(Node *head)
{
    Node *temp = head;

    // if head is empty or there is only one element
    // we can directly just return the head
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // create a stack to store
    stack<int> st;
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }


// start again by assigning head to temp 
    temp = head ;

    while (temp != nullptr)
    {

        // insert the top of the stack in the list
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}


// optimal approach 
// In-place link exchange method
Node* reverseDLL(Node* head) {
    
    // Check if the list is empty
    // or has only one node
    if (head == NULL || head->next == NULL) {
        // No change is needed;
        // return the current head
        return head; 
    }
    
     // Initialize a pointer to
     // the previous node
    Node* back = NULL;  
    
    // Initialize a pointer to
    // the current node
    Node* current = head;   

    // Traverse the linked list
    while (current != NULL) {
        // Store a reference to
        // the previous node
        back = current->prev; 
        
        // Swap the previous and
        // next pointers
        current->prev = current->next; 
        
        // This step reverses the links
        current->next = back;          
        
        // Move to the next node
        // in the original list
        current = current->prev; 
    }
    
    // The final node in the original list
    // becomes the new head after reversal
    return back->prev;
}


void printList(Node *head)
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
    vector<int> arr = {10, 20, 30, 40};
    Node *head = Array_To_DLL(arr);
    printList(head);
    cout << endl
         << "Doubly Linked List After Reversing " << endl;

    // Insert a node with value 10 at the end
    // head = Reverse_DLL(head);
    head = reverseDLL(head);
    printList(head);
}