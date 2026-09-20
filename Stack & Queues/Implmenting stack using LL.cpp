#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int d,Node* n){
        data=d;
        next=n;
    }
    
    Node(int d){
        data=d;
        next=nullptr;
    }
};

class Stack{
    public:
    Node* top;
    int size=0;
    
    void push(int x){
        Node* temp= new Node(x);
        temp->next=top;
        top=temp;
        size++;
    }
    
    void pop(){
        Node* last=top;
        top=top->next;
        delete last;
        size--;
    }
    
    int topi(){
        return top->data;
        
    }
    
    int size{
        return size;
    }
}

int main()
{
    

    return 0;
}