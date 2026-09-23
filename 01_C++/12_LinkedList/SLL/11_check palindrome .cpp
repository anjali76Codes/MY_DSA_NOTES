/*
We are given the singly linked list and we have to check given list is palindrome or not

Brute Approach : Using stack
1. traverse the list and push into the stack
2. again insert the top of the stack in the list and check if temp->data != st.top()
    pop stack top and return false
else return true

time complexity : O(2N)
space complexity : O(N)


Optimal Approach :  Using two pointer
for even : fast->next->next != null
for odd : fast->next !=null


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
bool isPalindrome(Node *head)
{
    Node *temp = head;
    stack<int> s;

    // traversing the entire list and pushing the data into the stack
    while (temp)
    {
        s.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    // inserting the data in the list by taking the top of the stack
    while (temp)
    {
        if(temp->data != s.top())    return false ;
        temp = temp->next;
          s.pop();
  
        
      
    }

    return true;
}



// reverse the second half
Node *reverseLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    // reverse the list
    Node *newHead = reverseLL(head->next);
    Node *front = head->next;
    // reverse the link from (front to head -back )
    front->next = head;
    head->next = nullptr;

    return newHead;
}


// optimal approach 
bool checkPalindrome(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    if (head == nullptr || head->next == nullptr)
        return true;

    // we need to find the 2nd half
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // here newHead is the head of the second half
    // newHead is the head of reverse of the second half
    Node *newHead = reverseLL(slow->next);

    // two pointer to compare the ele
    Node *first = head;
    Node *second = newHead;

    // in both pointer second node will end early
    while (second != nullptr)
    {

        if (first->data != second->data)
        {
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseLL(newHead);
    return true;
}

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

    int n;
    cin >> n;
    Node *head = new Node(1);
    insert_end(head, 2);
    insert_end(head, 3);
    insert_end(head, 3);
    insert_end(head, 2);
    insert_end(head, 1);

    traverseLL(head);
    cout << endl;

    bool res = checkPalindrome(head);
    cout<<res<<endl;
    bool ans  = isPalindrome(head);
    cout<<ans<<endl;

    return 0;
}