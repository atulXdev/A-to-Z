//ques link:https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937

//m1:as there will be only three possible elements in LL so,count no of 0,1 and two in first traversal,and in text traversal do data
//replacement first place 0 then 1 and then 2

//Time com:O(2n) space:O(1)

Node* sortList(Node *head){
    Node* temp=head;
    int count0=0;
    int count1=0;
    int count2=0;
    //first traversal for counting no of zeros one and two
    while(temp!=NULL){
        if(temp->data==0){
            count0++;
        }
        else if(temp->data==1){
            count1++;
        }

        else{
            count2++;
        }

        temp=temp->next;
    }

    //2nd traversal for replacement of 0 1 and 2 first replace 0 till our zerocount ends then 1 and then 2
    temp=head;
    while(temp!=NULL){
        if(count0!=0){
            temp->data=0;
            count0--;
        }
        else if(count1!=0){
            temp->data=1;
            count1--;
        }

        else{
            temp->data=2;
            count2--;
        }

        temp=temp->next;
    }

    return head;
}

//m1:in single traversal make 3 LL one having only 0,one having only 1 and another having 2 and do a good linking between them 
//such that last 0 node point to first head and so on bro



Node* sortList(Node *head){
    
    //if its a single node
    if(!head || !head->next) return head;

    Node* zeroHead= new Node(-1);
    Node* oneHead= new Node(-1);
    Node* twohead=new Node(-1);

    Node* zero=zeroHead;
    Node* one=oneHead;
    Node* two=twohead;

    Node* temp=head;

    while(temp){
        if(temp->data==0){
        zero->next=temp;
        //moving current point of zero to next assigned val
        zero=zero->next;
        }
        else if(temp->data==1){
            one->next=temp;
            one=one->next;
        }

        else{
            two->next=temp;
            two=two->next;
        }

        temp=temp->next;
    }

    //one linking 3 LL
    zero->next=oneHead->next ?oneHead->next:twohead->next;
    one->next=twohead->next;
    two->next=NULL;

    Node* newhead=zeroHead->next;
return newhead;
    delete newhead;
    delete zeroHead;
    delete oneHead;
    delete twohead;

}




