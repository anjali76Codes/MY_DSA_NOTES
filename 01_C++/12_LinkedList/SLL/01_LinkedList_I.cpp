/*
#Linked list:
Linked list -> Linked list is similar to an array but the difference is linked list do not have the contiguous memory .
Linked list is a dynamic data structure that means we can add or remove the elements based on our requirements
Linked list store the elements in such way that
one element is store the next (i.e the address of next element)



#Uses: Linked list are used in stack , queue
real life examples : browser (to go to the next and on back click coming to the previous )

# Memory space :
it depends on the system :
1. In 32 bit system : int -> 4bytes and * -> 4 bytes
2. In 64 but system : int -> 4 bytes & * -> 8 bytes

so 32 but system takes total space of 8 bytes where as 64 bit system takes 12 bytes memory space 


Time complexity : O(n) 

*/
#include <bits/stdc++.h>
using namespace std;

// Node declaration
class Node
{
    // Create space for the data and next pointer
public:
    int data;     // Stores the data value for the node
    Node *next;   // Pointer to the next node in the linked list

    // Constructor to initialize both data and the next pointer
public:
    Node(int data1, Node *next1)
    {
        data = data1;  // Assign the data value
        next = next1;  // Assign the pointer to the next node
    }

    /* This is a constructor for the `Node` class that takes an integer `data1` as a parameter.
       Inside the constructor:
       - It initializes the `data` member variable to the value of `data1`.
       - It sets the `next` pointer to `NULL`, indicating the node is the last one in the linked list.
       This constructor is useful when creating a new node with just the data value, 
       without specifying the next node. */
public:
    Node(int data1)
    {
        data = data1;   // Assign the data value
        next = nullptr; // Initialize the next pointer to nullptr
    }
};





int main()
{
    // Create a vector to store some integers
    vector<int> arr = {1, 2, 4, 6};


  // Node y = new Node(arr[0]);
    // cout<<y.data;   ->  or next that show the null pointer


    // Dynamically create a new node with the first element of the vector `arr`
    // Here, `y` is a pointer to a new Node object, initialized with the value `arr[0]` (1 in this case)
    Node *y = new Node(arr[0]);

    // Print the data value of the created node
    cout << y->data; // Output: 1
cout<<endl;


    // taken array as input 
    // int n ;
  
    // cin>>n ;
    // int a[n] ;
    // for(int i = 0 ; i< n ; i++){
    //     cin>>a[i] ;
    // }
    // Convert the array to a linked list
    // Node* head = arrToLinkedList(a, n);

    // // Print the linked list
    // while (head != NULL) {
    //     cout << head->data << " -> ";
    //     head = head->next;
    //     }
    //     cout<<"null";
       

    
    

    

    return 0;
}



