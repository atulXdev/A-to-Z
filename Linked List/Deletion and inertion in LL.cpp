//Deleting the head and tail node
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr){
        data = data1;
        next = next1;
    }
};

Node* convertArray2LL(vector<int> & arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    
    return head;
};

int lengthOfLL(Node* head){
    Node* temp=head;
    int count=0;
 while(temp){
     count++;
     temp=temp->next;
 }
 return count;
}

int checkIfPresent(Node* head,int val){
      Node* temp=head;
 while(temp){
     if(temp->data==val){
         return 1;
     }
     temp=temp->next;
 }
 return 0;
    
    
}

//Remove the head Node*****************************
Node* removesHeads(Node* head){
    if(head==NULL) return head;
    //current head
    Node* temp=head;
    //assigning the head to the next head
    head=head->next;
    //removing the current head to free space
    delete temp;
    
    return head;
}

//remove the tailnode*******************************
Node* removeTailNode(Node* head){
    //if head is null or single element
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    //KEEP MOVING UNTIL WE FIND THE LAST ELEMENT
    while(temp->next->next!=NULL){
        temp=temp->next;
        
    }
    //after completing this loop we are at second last element
    //remove the last
    delete temp->next;
    //make the 2nd last elem as last by pointing it null
    temp->next=nullptr;
    
    return head;
}

int main() {
    vector<int> arr={1,2,3,4,5};
 Node* head=convertArray2LL(arr);
head=removeTailNode(head);
cout<<head->data;
    
 
    return 0;
}

//REMOVING ANY K ELEMENT FROM LL *******************************************************************************

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr){
        data = data1;
        next = next1;
    }
};

Node* convertArray2LL(vector<int> & arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    
    return head;
};

int lengthOfLL(Node* head){
    Node* temp=head;
    int count=0;
 while(temp){
     count++;
     temp=temp->next;
 }
 return count;
}

int checkIfPresent(Node* head,int val){
      Node* temp=head;
 while(temp){
     if(temp->data==val){
         return 1;
     }
     temp=temp->next;
 }
 return 0;
    
    
}

//Remove the head Node*****************************
Node* removesHeads(Node* head){
    if(head==NULL) return head;
    //current head
    Node* temp=head;
    //assigning the head to the next head
    head=head->next;
    //removing the current head to free space
    delete temp;
    
    return head;
}

//remove the tailnode*******************************
Node* removeTailNode(Node* head){
    //if head is null or single element
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    //KEEP MOVING UNTIL WE FIND THE LAST ELEMENT
    while(temp->next->next!=NULL){
        temp=temp->next;
        
    }
    //after completing this loop we are at second last element
    //remove the last
    delete temp->next;
    //make the 2nd last elem as last by pointing it null
    temp->next=nullptr;
    
    return head;
}

//remove k node from LL**********************

Node* removek(Node* head,int k){
    if(head==NULL) return NULL;
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int count=0;
    Node* temp=head;
    Node* prev=NULL;
    
    while(temp!=NULL){
        count++;
        
        if(count==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    
    return head;
}
//remove a element whose val given**********************
Node* removeElm(Node* head,int elm){
    if(head==NULL) return NULL;
    if(head->data==elm){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    
    while(temp!=NULL){
        
        if(temp->data==elm){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    
    return head;
}

int main() {
    vector<int> arr={1,2,3,4,5};
 Node* head=convertArray2LL(arr);
head=removek(head,4);
cout<<head->data;
    
 
    return 0;
}



-----------------------------------------------------------------------------------------------------------------------------------------------------
000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
----------------------------------------------------------------------------------------------------------------------------------

//INSERTION
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr){
        data = data1;
        next = next1;
    }
};

Node* convertArray2LL(vector<int> & arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    
    return head;
};

//inserting in head node:Make a val as head node***************************************************************************************
Node* insertHead(Node* head,int val){
                        //node next will point twoards the head so this node is our current head
    Node* temp=new Node(val,head);
    return temp;
    
}

//inserting node at LAST******************************************
Node* insertTail(Node* head,int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    //by deafult this new node pointing to NULL
    Node* tail=new Node(val);
    temp->next=tail;
    return head;
    
}

//INSERT AT K POISTION OF LL *************************************************************************************

Node* insertPosition(Node* head,int elm,int k){
    //edge cases
    if(head==NULL){
        if(k==1){
            return new Node(elm);
        }
        else{
            return head;
        }
    }
    
    if(k==1){
        return new Node(elm,head);
    }
    Node* temp=head;
    int count=0;
    
    while(temp!=NULL){
        count++;
        //find elem jiske age insert krna h
        //like 3rd elm pe insert krna h to 2nd elem
        if(count==k-1){
            Node* newnode=new Node(elm,temp->next);
            temp->next=newnode;
            break;
            
        }
        temp=temp->next;
    }
    
    return head;
    
    
}

//INSERT A NODE BEFORE A GIVEN NODE SAME H BAS POSITION KE JAGAH VAL GIVEN H*************************************************
Node* insertBeforeValue(Node* head, int el, int val) {
    if(head == NULL) {
        return NULL;
    }
    if(head->data == val) {
        return new Node(el, head);
    }
    Node* temp = head;
    while(temp->next != NULL) {
        if(temp->next->data == val) {
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}



int main() {
    vector<int> arr={1,2,3,4,5};
 Node* head=convertArray2LL(arr);
head=insertHead(head,89);
cout<<head->data;
    
 
    return 0;
}