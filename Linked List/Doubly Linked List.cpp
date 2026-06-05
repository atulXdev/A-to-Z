#include <bits/stdc++.h>
using namespace std;

//STRUCTURE OF DOUBLY LL
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    
    public:
    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        back=prev1;
    }
    
    public:
    Node(int data1){
         data=data1;
        next=nullptr;
        back=nullptr;
    }
        
};
//CONVERTING ARRAY TO DOUBLY LL
Node* convertArray2DoublyLL(vector<int> & arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    
    return head;
}

//deleting the head of linked list
Node* deleteHead(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    
    delete prev;
    return head;
}

//deleting Tail of LL
Node* deleteTail(Node* head){
   if(head==NULL || head->next==NULL){
       return NULL;
   }
   
   Node* tail=head;
   while(tail->next!=NULL){
       tail=tail->next;
   }
   Node* newtail=tail->back;
   newtail->next=nullptr;
   tail->back=nullptr;
   delete tail;
   return head;
    
}

Node* removeKthNode(Node* head,int k){
    if(head==NULL){
        return NULL;
    }
    int count=0;
    Node* kNode=head;
    while(kNode!=NULL){
        count++;
        if(count==k){
            break;
        }
        kNode=kNode->next;
    }
    Node* prev=kNode->back;
    Node* front=kNode->next;
//single elemnt
    if(prev==NULL && front==NULL){
        return NULL;

    } 
    //at head
    else if(prev==NULL){
        return deleteHead(head);

    }

    else if(front==NULL){
        return deleteTail(head);
    }

    prev->next=front;
    front->back=prev;

    kNode->next=nullptr;
    kNode->back=nullptr;
    return head;

}

//deleting a Node by taking node as param
void deletenode(Node* temp){
    Node* prev=temp->back;
    Node* front=temp->next;
    
    if(front==NULL){
        prev->next=nullptr;
        temp->back=nullptr;
        free(temp);
        return;
    }
    
    prev->next=front;
    front->back=prev;
    
    temp->next=temp->back=nullptr;
    free(temp);
}


void print(Node* head){
    while(head!=NULL){
        cout<<head->data <<" ";
        head=head->next;
    }
}

-------------------------------------------------------------------------------------------------------------------------------
//INSERTION OF NODES

//inserting new node before head :INSERTED HEAD IS NEW HEAD
*Node insertBeforeHead(Node* head,int val){
    //new head next pointing to curr haed and cak pointing to null
    Node* newhead=new Node(val,head,nullptr)
    head->back=newhead;
    
    return newhead;
}

//insert a node before the tail of linked list

*Node insertBeforeTail(Node* head,int val){
    if(head->next==NULL){
        return insertBeforeHead(head,val);
    }
    Node* tail=head;
    while(tail->next!=NULL){
        temp=tail->next;
    }
    Node* prev=tail->back;
    Node* newtail=new Node(val,tail,prev);
    tail->back=newtail;
    prev->next=newtail;

    return head;

}

*Node insertBeforeKthElement(Node* head,int k,int val){
    if(k==1){
        insertBeforeHead(head,val);
    }
    Node* temp=head;
    int count=0;
    while(temp->next!=NULL){
        count++;
        if(count==k){
            break;
        }
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newnode=new Node(val,temp,prev);
    prev->next=newnode;
    temp->back=newnode;
    return head;
    
}
//inserting before the given node,our intetion is not to insert before head in any tesecase
void insertBeforeNode(Node* node,int val){
    Node* prev=node->back;
    Node* newnode= new Node(val,node,prev);
    prev->next=newnode;
    node->back=newnode;
    
}


int main() {
    vector<int> array={3,5,7,8,10};
 Node* head=   convertArray2DoublyLL(array);
//  head=deleteHead(head);
//  print(head);
    
 print(head);
    
    
   
    return 0;
}