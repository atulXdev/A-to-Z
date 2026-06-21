//bruteforce

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //extreme bruteforce count the len of LL len-n give eske age wala node delete kro
        //fix linking;

        ListNode* temp=head;
        int count=0;
        //this loop for counting len of LL
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }

        int res=count-n;
        //eske just age wala node udana h 

        //egde case agar head node uda rhe ho then len==n handle linking properly
        if(count==n){
            ListNode* oldHead=head;
            head=head->next;
            delete oldHead;
            return head;
        }
temp=head;
        while(res>1){
            temp=temp->next;
            res--;

        }

        ListNode* deleteNode=temp->next;
        temp->next=temp->next->next;
        delete deleteNode;

        return head;
        
    }
};

//optimized sol
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //solving using fast and slow pointers
        //jb tak fast pointer end tak badhega tab tak slow pointer us node ke piche ake khada
        //ho jayega fast sbse phle utna bhaga do jitna 'n' h after that move slow and fast together and when fast teaches end you have to delete slow next

        ListNode* fast=head;
        ListNode* slow=head;

        for(int i=0;i<n;i++){
            fast=fast->next;
        }
//if its a head node you need to delete
if(fast==NULL) return head->next;

while(fast->next!=NULL){
    fast=fast->next;
    slow=slow->next;
}

ListNode* delNode=slow->next;
slow->next=slow->next->next;

delete delNode;
return head;
        
    }
};