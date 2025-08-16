/*
1. Array to linked list - O(n)
2. find length - O(n)
3. Search ele in List - worst case (O(n)) , best case(O(1))
*/

#include <bits/stdc++.h>
using namespace std;

// Node structure
class Node
{
    // initialization
public:

        int data;
        Node *next;
  

    // putting the values
public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // end of the list that has next is nullptr
public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// 1.  arr to linked list   1 , 2, 3, 4
Node *arrToLinkedList(int a[], int n)
{
    // 1. head point to 1st ele of the array
    Node *head = new Node(a[0]);
    Node *mover = head;
    // 2. traverse the array and add each element to the linked list
    for (int i = 1; i < n; i++)
    {
        Node* temp = new Node(a[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// 2. find length of LL
int findLength(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}


//3 . Search the ele
bool searchEle(Node *head, int ele)
{
    Node* temp = head ;
    while(temp !=NULL){
        if(temp->data == ele){
            return true ;
            }
            temp = temp->next ;
            }
            return false ;
    }

// print the linked list
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
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *head = arrToLinkedList(arr, n);
    printList(head);

    // print total length 
    cout<<findLength(head)<<endl;

    //check if ele is present or not 
    cout<<searchEle(head, 5)<<endl;
}