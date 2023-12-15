#include <iostream>
using namespace std;

class ArrayQueue {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int front, rear;

public:
    ArrayQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1 && front == 0) || (rear + 1 == front);
    }

    void enqueue(int value) {
        if (isFull()) {
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    void deleteAtPosition(int position) {
        if (isEmpty() || position < 0) {
            return;
        }

        int count = (rear - front + 1 + MAX_SIZE) % MAX_SIZE;

        if (position >= count) {
            return;
        }

        int index = (front + position) % MAX_SIZE;

        if (front == rear) {
            front = rear = -1;
        } 
        else {
            for (int i = index; i < rear; i = (i + 1) % MAX_SIZE) {
                arr[i] = arr[(i + 1) % MAX_SIZE];
            }

            rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
        }
    }

    void display() {
        if (isEmpty()) {
            return;
        }

        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);

        cout << endl;
    }
};

int main() {
    ArrayQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    queue.display();

    queue.dequeue();

    cout << "Front element: " << queue.getFront() << endl;

    queue.deleteAtPosition(1);

    queue.display();

    return 0;
}
