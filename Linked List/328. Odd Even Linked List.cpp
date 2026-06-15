// FIRST ADDING THE ODD NODES THEN ADDING THE EVEN NODE
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

 //Time(N)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        //edge case if its a null or single element
        if(head==NULL || head->next==NULL){
            return head;
        }

        vector<int> arr;
        //phle add numbers ke node honge then even no ke
        ListNode* temp=head;

        //ADDING ODD INDICES DATA in arr
        while(temp!=NULL && temp->next!=NULL){
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp){
            arr.push_back(temp->val);
        }

        //adding even indices data in arr
        temp=head->next;
        while(temp!=NULL && temp->next!=NULL){
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
         if(temp){
            arr.push_back(temp->val);
        }
        //replacing all the data of LL by arr
        int i=0;
        temp=head;
        while(temp!=NULL){
            temp->val=arr[i++];
            temp=temp->next;
        }

        return head;
        
    }
};

//optmizing the space complexity by not using any external Data strcuture

//We will do link change between the nodes point even indices with even node and odd indices with odd node\
//after doing link changes you will find even node will be at last

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
    ListNode* oddEvenList(ListNode* head) {
          if(head == NULL || head->next == NULL)
            return head;
        ListNode* even=head->next;
        ListNode* odd=head;
        ListNode* evenHead=head->next;

        //Even node will always at last after completing the loop and odd node will
        //be just before it
        //after one itertion even will always just ine ahead of odd

        //we have only check for even node
        while(even!=NULL && even->next!=NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;

            odd=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
        
    }
};

