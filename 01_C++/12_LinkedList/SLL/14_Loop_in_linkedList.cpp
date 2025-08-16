/*
Detect a loop in linked list
loop ==> minimum of one node  where I can start and reach back

# using hashing
time complexity : O(n* 2logn) it depends on how it mapped 
space complexity : O(n)


# Tortoise and hare method 
# optimal approach - using two pointer
intuition : in two pointer approach we have two pointers slow and fast  and we are moving them simultaneously but slow move one step and fast two step ahead 
- so slow is always go away to 1 step to fast but fast is always come towards 2 step to slow so the average distance or d is d-1 and at one time d becomes 0 that's why we move slow one step and fast two step  when slow and fast reach at same position then we can say yes loop is present in the list 

because in linear list there is no any possibility to collide this two pointer or occupy the same position 

time complexity : O(n) 

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
bool Detect_loop(Node* head){
    map<Node* , int>mp ;
    Node * temp = head ;

    while(temp){
if(mp.find(temp) != mp.end()){
    return true ; 
}

mp[temp] = 1 ; 
temp= temp->next ;

    }

    return false ; 

}



// using two pointer 
bool Detect_Loop(Node* head){
    Node * slow = head ;
    Node * fast = head ;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next ;
        fast = fast->next->next ;
        if(slow == fast){
            return true ;
            }
            }
            return false ;
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
   
    bool res = Detect_loop(head);
    cout<<res<<endl;
    return 0;
}