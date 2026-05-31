//Template
#include <bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
        
    }
};

int main() {
    vector<int> arr={1,2,3,4};
    Node* y= new Node(arr[0],nullptr);
    
    cout <<y->data;
    
 
    return 0;
}

//Converting array to LL

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

int main() {
    vector<int> arr={1,2,3,4};
 Node* head=convertArray2LL(arr);
    
    
    
    cout <<head->data;
    
 
    return 0;
}


//Traversal iterating through all elements in LL
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

int main() {
    vector<int> arr={1,2,3,4};
 Node* head=convertArray2LL(arr);
 cout <<head->data <<endl;
 
 Node* temp=head;
 //untile temp is null
 while(temp){
     cout<< temp->data<<" "<<endl;
     temp=temp->next;
     
 }
    
 
    return 0;
}

//LENGTH OF LL
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

//length
int lengthOfLL(Node* head){
    Node* temp=head;
    int count=0;
 while(temp){
     count++;
     temp=temp->next;
 }
 return count;
}

int main() {
    vector<int> arr={1,2,3,4,5};
 Node* head=convertArray2LL(arr);
 cout <<head->data <<endl;
 
 Node* temp=head;
 //untile temp is null
 while(temp){
     cout<< temp->data<<" "<<endl;
     temp=temp->next;
     
 }
 
 int l=lengthOfLL(head);
 cout<<l <<endl;
    
 
    return 0;
}

//check if val is present or not
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

int main() {
    vector<int> arr={1,2,3,4,5};
 Node* head=convertArray2LL(arr);
//  cout <<head->data <<endl;
 
//  Node* temp=head;
//  //untile temp is null
//  while(temp){
//      cout<< temp->data<<" "<<endl;
//      temp=temp->next;
     
//  }
 
//  int l=lengthOfLL(head);
//  cout<<l <<endl;
int check=checkIfPresent(head,4);
cout<<check;
    
 
    return 0;
}