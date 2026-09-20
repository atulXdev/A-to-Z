//ALL OPERATION DONE IN TC OF O(1)

#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int st[10];
    int top=-1;
    
    //push add element to the top
    void push(int x){
        if(top>=9){
            cout << "OUT OF MEMORY" <<endl;
            return;
        }
        top++;
        st[top]=x;
    }
    //removing the topmost element
    void pop(){
        if(top==-1){
            cout<<"Unable to remove" <<endl;
            return ;
        }
        top--;
        
    }
    //fetch the last element pushed in
    int topi(){
        if(top==-1){
            return -1;
        }
        
        return st[top];
    }
    
    int size(){
        if(top==-1){
            cout << "No element inserted sir" <<endl;
        }
        int ans=top+1;
        return ans;
    }
    
    void display(){
        for(int i=0;i<=top;i++){
            cout << st[i] << endl;
        }
    }
    
};

int main()
{
   Stack st;
   st.push(10);
   st.push(20);
   st.push(40);
  st.pop();
int ans=  st.topi();
cout << ans << endl;
  st.display();
   

    return 0;
}