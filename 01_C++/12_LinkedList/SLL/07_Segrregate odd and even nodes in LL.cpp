#include <iostream>
#include <vector>
using namespace std;

// Sum of two linked lists
/*
  5 -> 7
  3 -> 8 -> 1 -> 9

  Output:
  8 -> 5 -> 2 -> 9

 Time Complexity: O(N) N is the number of Nodes in LinkedList. As we are traversing LinkedList once.

Space Complexity: O(1) We are just Manipulating the Links, not using any extra space.
*/

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

// time complexity : O(2N)
Node *oddEvenGroup(Node *head)
{

    // base condition: there should be atleast 2 nodes in ll
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // array for storing the result
    vector<int> arr;

    // Odd indexes
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    // take the last element
    if (temp)
        arr.push_back(temp->data);

    // even indexes
    temp = head->next;
    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp)
        arr.push_back(temp->data);

    // we have the new array - replace in the linked list
    int i = 0;
    temp = head;

    while (temp)
    {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }

    return head;
}

// optimal approach - O(N)
// we can do this in one pass - just keep track of the odd and even indexes
// and replace the data in the linked list in one pass
Node* segregate_odd_even(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;

    while (even != nullptr && even->next != nullptr) {
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;

      
    }

    // Link the odd list to the even list
    odd->next = evenHead;
    return head;    
}

int main()
{

    Node *head = new Node(1);
    insert_end(head, 3);
    insert_end(head, 4);
    insert_end(head, 2);
    insert_end(head, 5);
    insert_end(head, 6);

    head = oddEvenGroup(head);
    traverseLL(head);
    cout << endl;
    head = segregate_odd_even(head);
    traverseLL(head);

    return 0;
}