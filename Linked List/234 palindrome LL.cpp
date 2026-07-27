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

        return true;

        
    }
};