/*
queue is a linear data structure that follows the FIFO mechanism.

Time Complexity:

pop function: O(1)

push function: O(1)

top function: O(1)

size function: O(1)

Space Complexity:

Whole Queue: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

int queueArray[10];
int front = -1;
int rear = -1;

// Enqueue function to add an element to the queue
void enqueue(int data)
{
    // Check if the queue is full
    if (rear >= 9)
    {
        cout << "Queue is full" << endl;
        return;
    }

    // If the queue is empty, set front to 0
    if (front == -1)
        front = 0;

    rear++;
    queueArray[rear] = data;
}

// Dequeue function to remove an element from the queue
int dequeue()
{
    // Check if the queue is empty
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }

    int dequeuedElement = queueArray[front];
    front++;

    // Reset the queue if it becomes empty
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }

    return dequeuedElement;
}

// Function to get the front element of the queue
int Front()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }

    return queueArray[front];
}

// Function to calculate the size of the queue
int Size()
{
    if (front == -1 || front > rear)
        return 0;

    return rear - front + 1;
}

int main()
{
    enqueue(1);
    enqueue(3);
    enqueue(2);
    enqueue(6);

    cout << "Front of queue before deleting any element: " << Front() << endl;
    cout << "Size of queue before deleting any element: " << Size() << endl;
    cout << "The element dequeued is: " << dequeue() << endl;
    cout << "Size of queue after deleting an element: " << Size() << endl;
    cout << "Front of queue after deleting an element: " << Front() << endl;

    return 0;
}
