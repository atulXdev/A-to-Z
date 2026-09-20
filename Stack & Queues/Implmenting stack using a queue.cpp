#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    queue<int> q;

    // Push
    void push(int x) {
        int s = q.size();

        q.push(x);

        // Move all previous elements behind x
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Pop
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        q.pop();
    }

    // Top
    int top() {
        if (q.empty()) {
            return -1;
        }

        return q.front();
    }

    // Size
    int size() {
        return q.size();
    }
};

int main() {
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Top: " << st.top() << endl;

    st.pop();

    cout << "Top: " << st.top() << endl;

    cout << "Size: " << st.size() << endl;

    return 0;
}