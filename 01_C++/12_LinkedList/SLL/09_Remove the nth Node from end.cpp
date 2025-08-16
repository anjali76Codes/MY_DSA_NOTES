/*
Remove the nth node from the end

#Brute approach :
1. N is given traverse the list and get the total node cnt
2. find  res= cnt-N
3. traverse again and do res--
    when res becomes zero  delete the node


time complexity : O(2N)
space complexity : O(1)

# optimal approach :
1. two pointer approach
2. in this instead of doing the total list traverse till N move the 2nd pointer
3. when 2nd reaches at end  first pointer point the nth node
4. if N -> equal to list length return head->next

time complexity : O(N) since the fast pointer will traverse the entire linked list, where N is the length of the linked list. 
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
Node *Remove_nthNode_fromEnd(Node *head, int N)
{
    Node *temp = head;
    int cnt = 0;

    // calculate the total n nodes present in the list
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }

    // when N is equal to total node then head will get delete
    if (cnt == N)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }

    int res = cnt - N;
    temp = head;
    // when res = 0 we got the position where we have to change the link to remove the nth node from end
    while (temp != nullptr)
    {
        res--;
        if (res == 0)
            break;
        temp = temp->next;
    }

    // temp-> next is nothing but the nth node which we have to delete
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;

    return head;
}

// optimal approach - in one pass
Node *RemoveNthNode(Node *head, int N)
{
    Node *slow = head;
    Node *fast = head;

    // move fast till nth
    for (int i = 0; i < N; i++)
    {
        fast = fast->next;
    }

 // if nth node is equal to total node length
    if (fast == nullptr)
    {
        //  Node* newHead = head->next ;
        //  delete head ;
        //  return newHead ;

        return head->next;
    }

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

   

    // after reaching the cnt-n node
    Node *deletenode = slow->next;
    slow->next = slow->next->next;
    delete deletenode;

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
    Node *head = new Node(10);
    insert_end(head, 4);
    insert_end(head, 7);
    insert_end(head, 20);
    insert_end(head, 6);
    insert_end(head, 15);

    traverseLL(head);
    cout << endl;
    // Node *ans = Remove_nthNode_fromEnd(head, n);
    // traverseLL(ans);

    Node *res = RemoveNthNode(head, n);
    traverseLL(res);

    return 0;
}
