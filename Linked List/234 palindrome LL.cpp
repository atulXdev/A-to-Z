//bruteforce by stack
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        stack<int> st;
        //adding all elemnts of LL to stack
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }

        //comparong all elemnts of stacks (LIFO) so every first element of LL
        //compared with LL as psuhed in stack
        temp=head;
        while(temp!=NULL){
            if(st.top()!=temp->val){
                return false;
            }
            st.pop();
            temp=temp->next;
        }


        //optimized without stack

        /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* reverseLL(ListNode* head){
    ListNode* curr=head;
    ListNode* prev=nullptr;

    while(curr!=nullptr){
        ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

    }

    return prev;

}
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return true;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        //fast->next=nullptr means its odd len LL node at fast at last and slow
        //is completly at the middle so age wale ko reverse krdo
        //fast->next->next!=nullptr its even len LL there are two middle 
        //and we are intreseted to stop slow in first middle eg m1 so that
        //we can reverse the nodes we encounter ahead and compare and check palin

        //VIP in Even if fast!=null then slow stands on middle m1 and when fast
        //stands at second last node eg fast->next->next==nullptr then middle stands
        //at m1

        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* revHead=reverseLL(slow->next);
        ListNode* temp=revHead;
        //chahe odd ka case or even hamesa rev wala LL hi chota hoga so usi pe loop
        //chalaenge taki odd wala ek extra node compare na ho

        while(temp!=nullptr){
            if(head->val!=temp->val){
                return false;
            }
            temp=temp->next;
            head=head->next;
        }

        return true;
        
    }
};

        return true;

        
    }
};
