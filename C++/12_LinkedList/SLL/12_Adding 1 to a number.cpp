/*
Brute Approach :
1. reverse the list
2. add 1 in temp->data(where temp point to head)
3. traverse the list
 at start carry =1 
 on traversing add 1 -> temp->data+carry 
    - if(temp->data <10)
        - carry = 0 and break
    - else : temp->data = 0 and carry = 1
4. if carry = 1 so we need to create new node which has data 1(carry) and its next point to head
5. return newHead

time complexity : O(3N)
space complexity : O(1)




optimal approach  - using recursive method 
base case : temp = null then return 1 and start backtrack 

-  traverse and when base case true return temp->next
if base case false add carry to temp->data
- if data is under the 10 return 0 
- else replace temp->data = 0 and return 1 

time complexity : O(N)
space complexity : O(N)





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

Node *reverse(Node *head)
{
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {

        // in each iteration at a time only one node get reversed
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

Node *AddingOne(Node *head)
{

    // reverse the list
    head = reverse(head);
    int carry = 1;
    Node *temp = head;

    //
    while (temp != nullptr)
    {
        temp->data = temp->data + carry;

        // if data is under the 10
        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }

    if (carry == 1)
    {
        Node *newNode = new Node(1);
        head = reverse(head);
        newNode->next = head;
        return newNode;
    }

    head = reverse(head);

    return head;
}



int helper(Node* temp){

    // it is the base case where backtracking will start 
    if(temp ==  nullptr){
        return 1 ;
    }

// it goes to the next of the temp and during backtracking get the carry value 
int carry = helper(temp->next);
temp->data = temp->data + carry ;
    // if data is under the 10 return carry 0 
    if(temp->data <10){
        return 0 ;
    }

    else{
       temp->data = 0 ;
       return 1 ; 
    }

    return 1 ;

}


// optimal approach 
Node * AddingOneLL(Node* head){ 
 int carry = helper(head);

 // if carry is remaining (equals to 1) then we need to create a one new node which carry the data 1 
 if(carry ==1){
    Node* newHead = new Node(1);
    newHead->next = head;
    return newHead;
 }
 return head;
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
    Node *head = new Node(9);
    insert_end(head, 9);
    insert_end(head, 9);
    insert_end(head, 9);

    traverseLL(head);
    cout << endl;

    // head = AddingOne(head);
    // traverseLL(head);
    head = AddingOneLL(head);
    traverseLL(head);

    return 0;
}