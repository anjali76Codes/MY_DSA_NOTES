/*
Insertion in singly LL
    - insertHead
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



// insert  at first node -> head - O(1)
Node* insertHead(Node* head , int data){
    Node* newNode = new Node(data, head);
    return newNode ;

}



// insert at end 
Node* insertAtLast(Node*head , int data){

  Node*temp  = head ;
  Node*newNode = new Node(data);
  // when LL is empty 
  if(head == nullptr){
    return newNode ;
    }
    while(temp->next != nullptr){
        temp = temp->next ;
        }
        temp->next = newNode ;
        return head ;
}




Node *insertAt_position(Node *head, int element, int k)
{

    // when list is empty
    if (head == NULL)
    {

        // when we have to insert first node (head)
        if (k == 1)  return new Node(element);
        
        else return head;
    
    }

    //  at first position insert the new node
    if (k == 1)
    {
        Node *temp = new Node(element, head);
        return temp;
    }

   
    int cnt = 0;

    Node *temp = head;
    while (temp)
    {
        cnt++;

        
       /* checking if the current node being traversed is the node just before the position where we want to insert a new node. */
        if (cnt == k - 1)
        {

           
            Node *newNode = new Node(element, temp->next);
            temp->next = newNode;

            // first make connection of the new node to the temp's next
            // then make connection of the temp's next to the new node
            break;
        }

        // until that we will keep moving forward
        temp = temp->next;
    }

    // the last tail case also gets covered by the while loop

    return head;
}

Node *insert_element(Node *head, int element, int val)
{
    // base case
    if (head == NULL)
    {

        // as the value is not present in the linked list
        return head;
    }

    // if we want to insert at the first
    if (head->data == val)
    {
        Node *temp = new Node(element, head);
        return temp;
    }

    // in other cases
    Node *temp = head;

    // never go to the last element so write while condition for that
    while (temp->next != NULL)
    {
        // so that we can go to one position behind
        if (temp->next->data == val)
        {
            Node *newNode = new Node(element, temp->next);
            temp->next = newNode;
            break;
        }

        temp = temp->next;
    }

    return head;
}



void printList(Node*head){
    while(head != nullptr){
        cout<<head->data<<" -> ";
        head = head->next ;
        }
        cout<<"null"<<endl ;
}


int main(){
    Node*head = nullptr ;
    head = insertHead(head, 10);
    head = insertHead(head, 30);
    head = insertHead(head, 20);
    head = insertHead(head, 60);
    head = insertAtLast(head , 45);
    head = insertAt_position(head , 27 ,3);
    head = insert_element(head , 25 , 45);
printList(head);
    
}