/*
we are given the sum k
in given DLL we have to find the all possible pairs which is equal to sum k


#Brute Approach :
time complexity :  near about O(n2)
space complexity : O(1)

optimal approach 
- list is in sorted order
time complexity : O(2N)
space complexity : O(1)
-


*/



#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

public:
    Node(int data1, Node *prev1, Node *next1)
    {
        data = data1;
        prev = prev1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

Node *Array_To_DLL(vector<int> &arr)
{

    // first node
    Node *head = new Node(arr[0]);
    Node *temp = head;

    // insert remaining ele
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i], temp, nullptr);

        // to link with first node add prev and next
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

// brute approach
vector<pair<int, int>> find_all_pairs(Node *head, int k)
{
    Node *temp1 = head;
    // data structure which store the all pairs
    vector<pair<int, int>> pairs;

    // traverse temp1 till end
    while (temp1)
    {
        // take next node for sum
        Node *temp2 = temp1->next;

        // temp2 traverse one by one and check for sum
        while (temp2 && temp1->data + temp2->data <= k)
        {
            if (temp1->data + temp2->data == k)
            {
                pairs.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }

    return pairs;
}


// findTail
Node* findTail(Node* head) {
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
        }
        return temp;
        }



vector<pair<int, int>> find_all_pairs_with_sum(Node *head, int k)
{
    vector<pair<int, int>> ans;

    // when list is empty
    if (head == NULL)
        return ans;

    // two pointer one point to head and another to tail
    Node *left = head;
    Node *right = findTail(head);

    // traverse the list till left pointer data is less than right pointer
    while (left->data < right->data)
    {

        // when both pointer sum = given sum
        if (left->data + right->data == k)
        {

            // push this pair in ds and move both pointer left(one move ahead) and right(one move behind)
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        // when left pointer data + right pointer data < given sum
        else if (left->data + right->data < k)
        {
            // move left pointer one step ahead
            left = left->next;
        }
        else
        {
            // move right pointer one step behind
            right = right->prev;
        }
    }
    return ans;
}

int main()
{

    vector<int> arr = {10, 20, 25, 40,50, 60, 65};
    int k = 60;
    Node *head = Array_To_DLL(arr);
    printList(head);

    vector<pair<int, int>> res = find_all_pairs_with_sum(head, k);
    for (auto &p : res)
    {
        cout << "(" << p.first << "," << p.second << ")";
    }

    return 0;
}