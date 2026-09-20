// implment stack using queue;
// we will use 2 stack for this S1 and S2;
// for pushing elements we will follow 3 steps
// 1:Move every elemenst of S1 to S2 ,S1 fully clear(S1->S2)

// 2: add that elment to S1(x)

// 3: Move every element of S2 to S1 (S2 to S1)

#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    queue<int> s1, s2;

    // push(x)
    void push(int x) {

        // 1: Move every elemenst of S1 to S2 ,S1 fully clear(S1->S2)
        while (!s1.empty()) {
            s2.push(s1.front());
            s1.pop();
        }

        // 2: add that elment to S1(x)
        s1.push(x);

        // 3: Move every element of S2 to S1 (S2 to S1)
        while (!s2.empty()) {
            s1.push(s2.front());
            s2.pop();
        }
    }

    // pop()
    void pop() {
        if (s1.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        s1.pop();
    }

    // top()
    int top() {
        if (s1.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return s1.front();
    }

    // size()
    int size() {
        return s1.size();
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;

    st.pop();

    cout << "Top: " << st.top() << endl;

    cout << "Size: " << st.size() << endl;

    return 0;
}

---------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    queue<int> s1, s2;

    // push(x)
    // Simply add element to S1
    void push(int x) {
        s1.push(x);
    }

    // pop()
    void pop() {
        if (s1.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        // Move all elements except the last one
        while (s1.size() > 1) {
            s2.push(s1.front());
            s1.pop();
        }

        // Remove the last element
        s1.pop();

        // Swap S1 and S2
        swap(s1, s2);
    }

    // top()
    int top() {
        if (s1.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        // Move all elements except the last one
        while (s1.size() > 1) {
            s2.push(s1.front());
            s1.pop();
        }

        // Last element is the top of stack
        int ans = s1.front();

        // Move it to S2
        s2.push(s1.front());
        s1.pop();

        // Swap S1 and S2
        swap(s1, s2);

        return ans;
    }

    int size() {
        return s1.size();
    }
};

int main() {
    Stack st;

    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Top: " << st.top() << endl;

    st.pop();

    cout << "Top: " << st.top() << endl;

    st.pop();

    cout << "Top: " << st.top() << endl;

    return 0;
}