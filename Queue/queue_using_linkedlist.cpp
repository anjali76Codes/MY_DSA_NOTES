#include<bits/stdc++.h>
using namespace std;

// using linked list 
class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};


class Queue{

//  create head and tail node 
Node* head;
Node* tail;

public:
Queue(){
    head = tail = NULL;
}

//          10 -> 20 -> 30 -> 40
void enqueue(int data){
    Node* newNode = new Node(data);
    if(empty()){
        head = tail = newNode ;
 
    }

    else{
        tail->next = newNode;
        tail = newNode;
    }
}


void dequeue(){
    if(empty()){
      cout<<"queue is underflow"<<endl;
    }

    else{
        // first in first out -> current head should be remove
        Node * temp = head ;
        head = head->next ;
        delete temp;

    }

}


int front(){
    if(empty()){
        cout<<"queue is empty"<<endl;
        return -1;
    }

    
return head->data;


}

bool empty(){
    return head==NULL;

}


};


int main()
{

    Queue q;
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.dequeue();
    }


// queue in stl
queue<int>qu;
     qu.push(11);
    qu.push(12);
    qu.push(13);
    qu.push(14);

    while(!qu.empty()){
        cout<<qu.front()<<endl;
        qu.pop();
    }

return 0;
}