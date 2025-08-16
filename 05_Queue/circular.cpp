#include<bits/stdc++.h>
using namespace std;

class CircularQueue{
    int *arr ;
    int currSize , cap;
    int f =0 , r= -1;
    public:

    CircularQueue(int size){
        cap = size ;
        currSize= 0;
        arr = new int[cap];
        f= 0, r= -1 ;
        
    }


    void push(int data){
        if(currSize == cap){
            cout<<"queue is overflow"<<endl;
        }
        else{
            r = (r+1)%cap;
            arr[r]= data;
            currSize++;
        }
  
    }


    void pop(){
        if(empty()){
            cout<<"Queue is empty\n";
        }
        else{
            f = (f+1)%cap ;
            currSize--;
        }

    }


    int front(){
        if(empty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        return arr[f];

    }

    bool empty(){
        return currSize ==0;

    }

};

int main()
{

    CircularQueue cq(5);
    cq.push(10);
    cq.push(100);
    cq.push(200);
    cq.push(300);
    cq.push(400);

    while(!cq.empty()){
        cout<<cq.front()<<endl;
        cq.pop();
    }


return 0;
}