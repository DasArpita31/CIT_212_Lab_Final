#include <iostream>
using namespace std;

int dequeArr[100];
int front = -1, rear = -1;

void insertFront(int value)
{
    if ((front == 0 && rear == 99) || (front == rear + 1))
    {
        cout << "Deque Overflow\n";
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = 99;
    }
    else
    {
        front--;
    }

    dequeArr[front] = value;
}

void insertRear(int value)
{
    if ((front == 0 && rear == 99) || (front == rear + 1))
    {
        cout << "Deque Overflow\n";
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == 99)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    dequeArr[rear] = value;
}

void deleteFront()
{
    if (front == -1)
    {
        cout << "Deque Underflow\n";
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == 99)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void deleteRear()
{
    if (front == -1)
    {
        cout << "Deque Underflow\n";
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = 99;
    }
    else
    {
        rear--;
    }
}

void display()
{
    if (front == -1)
    {
        cout << "Deque is empty\n";
        return;
    }

    int i = front;

    while (true)
    {
        cout << dequeArr[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % 100;
    }

    cout << endl;
}

int main()
{
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(2);

    cout << "Deque elements: ";
    display();

    deleteFront();
    deleteRear();

    cout << "After deletion: ";
    display();

    return 0;
}