/*
Detect a loop in linked list
loop ==> minimum of one node  where I can start and reach back

# using hashing
time complexity : O(n* 2logn) it depends on how it mapped 
space complexity : O(n)


# Tortoise and hare
time complexity : O(n)
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
// using hashing 
Node* starting_loop(Node* head){
    map<Node* , int>mp ;
    Node * temp = head ;

    while(temp){
if(mp.find(temp) != mp.end()){
    return temp; 
}

mp[temp] = 1 ; 
temp= temp->next ;

    }

    return NULL; 

}



// using two pointer 
Node* starting_node_Loop(Node* head){
    Node * slow = head ;
    Node * fast = head ;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next ;
        fast = fast->next->next ;
        if(slow == fast){
            return slow ;
            }
            }
            return NULL ;
    }


int main()
{
    Node *head = new Node(1);
    Node * second = new Node(3);
    Node * third = new Node(4);
    Node * fourth = new Node(2);
    Node * fifth = new Node(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    fifth->next = third; // Creating a loop for testing
   
head = starting_loop(head);
    cout<<head->data<<endl;
head = starting_node_Loop(head);
    cout<<head->data<<endl;
    return 0;
}