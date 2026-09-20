#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
    int capacity = 10;
    int qu[10];
    int currsize = 0;
    int start = -1;
    int end = -1;

    // Insert element
    void push(int x) {
        if (currsize == capacity) {
            cout << "Can't insert, Queue is full" << endl;
            return;
        }

        if (currsize == 0) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % capacity;
        }

        qu[end] = x;
        currsize++;
    }

    // Remove element from front
    int pop() {
        if (currsize == 0) {
            cout << "No elements to pop" << endl;
            return -1;
        }

        int fir = qu[start];

        if (currsize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % capacity;
        }

        currsize--;

        return fir;
    }

    // Get front element
    int top() {
        if (currsize == 0) {
            cout << "No elements" << endl;
            return -1;
        }

        return qu[start];
    }

    // Get current size
    int size() {
        return currsize;
    }
};

int main() {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(7);

    cout << "Popped: " << q.pop() << endl;

    cout << "Front: " << q.top() << endl;

    cout << "Size: " << q.size() << endl;

    return 0;
}