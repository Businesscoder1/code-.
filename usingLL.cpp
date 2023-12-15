#include <iostream>

using namespace std;
struct Node {
    int data;
    Node* next;
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;
    }

    void deleteAtPosition(int position) {
        if (position < 0 || isEmpty()) {
            return;
        }

        if (position == 0) {
            pop();
            return;
        }

        Node* current = top;
        Node* previous = nullptr;
        int currentPosition = 0;

        while (current != nullptr && currentPosition < position) {
            previous = current;
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr) {
            return;
        }

        previous->next = current->next;
        delete current;
    }

    void display() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << std::endl;
    }
};

int main() {
    LinkedListStack stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    stack.display();

    stack.pop();

    cout << "Top element: " << stack.peek() << endl;

    stack.deleteAtPosition(1);

    stack.display();

    return 0;
}
