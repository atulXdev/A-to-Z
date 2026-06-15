//REVERSE SINGLY LINKED LIST 206

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        stack<int> st;
        ListNode* temp=head;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;

        while(temp!=NULL){
            temp->val=st.top();
            st.pop();
            temp=temp->next;
        }

        return head;
        
    }
};

//reverse doubly LL by swapping the links
https://www.naukri.com/code360/problems/reverse-a-doubly-linked-list_1116098
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/

Node* reverseDLL(Node* head)
{   //single or no element case
    if(head==NULL || head->next==NULL){
        return head;
    }
//WE ARE REVERSING THE LINK ONLY(SWAPPING)
    Node* prev=NULL;
    Node* curr=head;
    while(curr!=NULL){
        prev=curr->prev;
        curr->prev=curr->next;
        curr->next=prev;

        //move a pointer ahaed after swapping the links
        curr=curr->prev;

    }

    return prev->prev;
}

