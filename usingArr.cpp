#include <iostream>

class ArrayStack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;

public:
    ArrayStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            std::cout << "Stack is full." << std::endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        --top;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }
        return arr[top];
    }

    void deleteAtPosition(int position) {
        if (position < 0 || position > top) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
        
        for (int i = position; i < top; ++i) {
            arr[i] = arr[i + 1];
        }
        --top;
    }

    void display() {
        for (int i = 0; i <= top; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    ArrayStack stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    stack.display();

    stack.pop();

    std::cout << "Top element: " << stack.peek() << std::endl;

    stack.deleteAtPosition(1);

    stack.display();

    return 0;
}
