/*
we have to find the length of the loop

#brute approach :
using hashing
- we track the timer of each node
- so from start at one node and reach again to this node then get the value of this node form the map and do minus (timer-value) -> length of the loop
- here timer is the current time value

time complexity : O(n* 2logn)
space complexity : O(n)


#optimal approach :
- we use two pointers : fast and slow
- fast pointer moves two steps at a time and slow pointer moves one step at a time

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
int find_length_Loop(Node *head)
{

    // creating a map
    map<Node *, int> mp;
    int timer = 1;
    Node *temp = head;

    while (temp)
    {
        if (mp.find(temp) != mp.end())
        {
            // get the  value of the timer which are already present in the map
            int value = mp[temp];

            // current timer value - value which present in map
            return timer - value;
        }

        mp[temp] = timer;
        timer++;
        temp = temp->next;
    }

    return 0;
}

int findLength(Node *slow, Node *fast)
{
    int cnt = 1;
    fast = slow->next;
    while (slow != fast  )
    {
        cnt++;
        fast = fast->next;
        
    }
    return cnt;
}

// using two pointer
int  find_length_loop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;

        fast = fast->next->next;

        if (slow == fast)
        {
            return findLength(slow, fast);
        }
    }
    return 0;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(3);
    Node *third = new Node(4);
    Node *fourth = new Node(2);
    Node *fifth = new Node(5);
    Node *sixth = new Node(6);
    Node *seventh = new Node(7);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    sixth->next = third; // Creating a loop for testing

    int res = find_length_loop(head);
    cout << res << endl;
    return 0;
}
