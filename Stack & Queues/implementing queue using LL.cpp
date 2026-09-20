#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    class Node {
    public:
        int data;
        Node* next;

        Node(int x) {
            data = x;
            next = nullptr;
        }
    };

    Node* top = nullptr;
    int size = 0;

    // Push
    void push(int x) {
        Node* temp = new Node(x);

        temp->next = top;
        top = temp;

        size++;
    }

    // Pop
    int pop() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        Node* temp = top;
        int value = top->data;

        top = top->next;

        delete temp;
        size--;

        return value;
    }

    // Top
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return top->data;
    }

    // Size
    int getSize() {
        return size;
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.peek() << endl;

    cout << "Popped: " << st.pop() << endl;

    cout << "Top: " << st.peek() << endl;

    cout << "Size: " << st.getSize() << endl;

    return 0;
}