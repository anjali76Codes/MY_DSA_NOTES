/*
 find the Intersection of two list
  return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

  
 # Brute Approach : 
  - keep the track of the second list(any of the ) 
  - traverse the list 1 
  - check if temp node of list 1 is = head2 then return head2 
  - after traversing all the list if there is no any intersecting node then return null 

time complexity : Time Complexity: O(m*n)
- For each node in list 2 entire lists 1 are iterated. 
space complexity : O(1)


 # Better approach :  using hashing 
  Note* : we can consider any of the list to traverse
  - creating one unordered_set which on traversing store the list1 node
  - traverse the 2nd list and check if list2 node is present in the set or not if yes return the temp(that node )

  - if not move to next pointer and check for the next one 
  at the end if not found any then return null


  time complexity :  Time Complexity: O(n+m)
-  Iterating through list 1 first takes O(n), then iterating through list 2 takes O(m)
space complexity : O(n)


# Optimal approach : two pointers approach 
- 1st pointer for list 1 and 2nd pointer for list 2
- 1st pointer traverse the list 1 and 2nd pointer traverse the list 2



*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data1, Node *next1 = nullptr) {
        data = data1;
        next = next1;
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

// Function to find the intersection of two linked lists using an unordered set
Node* findIntersection(Node* head1, Node* head2) {
    unordered_set<Node*> set;
    Node* temp = head1;
    
    // Insert all nodes of head1 into the set
    while (temp != nullptr) {
        set.insert(temp);
        temp = temp->next;
    }
    
    // Traverse head2 and check if any node is in the set
    temp = head2;
    while (temp != nullptr) {
        if (set.find(temp) != set.end()) {
            return temp;  // Intersection found
        }
        temp = temp->next;
    }
    
    return nullptr;  // No intersection found
}




// brute/simple approach 
Node* IntersectionPresent(Node* head1 , Node* head2){
    // keep the track of the second list 
    while(head2 != nullptr){
        
          // traverse the first list
        Node* temp = head1 ;
        while(temp != nullptr){
            // check if node of first list is equal to node of second list if yes return head2 that is node at which both list are intersecting to each other
            if(temp  == head2) return head2 ;
            temp = temp->next ;
        }

        head2 = head2->next ;
    }

    return nullptr;
}


int main() {
    Node* head1 = new Node(2);
    head1 = insert_at_end(head1, 3);
    head1 = insert_at_end(head1, 4);
    head1 = insert_at_end(head1, 5);

    Node* head2 = new Node(1);
    head2 = insert_at_end(head2, 4);
    head2 = insert_at_end(head2, 5);
    
    traverseLL(head1);
    traverseLL(head2);

 head2->next  = head1->next->next;

    Node* res = IntersectionPresent(head1 , head2);
   if(res == nullptr){
    cout<<"No intersection found"<<endl;
   }
   else{
    cout<<res->data<<endl;
   }
    
    return 0;
}
