//swapping in place by single pointer i with n-i-1 element
#include <bits/stdc++.h>
using namespace std;

void fun(int i,int arr[],int n){
    if(i>=n/2){
        return;
    }
    swap(arr[i],arr[n-i-1]);
    
    fun(i=i+1,arr,n);
}

int main() {
    
    int arr[]={1,2,3,4};
    fun(0,arr,4);
    
    for(int n:arr){
        cout <<n;
    }
   
    return 0;
}


//check for palindrome

#include <bits/stdc++.h>
using namespace std;
bool palin(int i,string & s){
    if(i>=s.size()/2){
        return true;
    }
    
    if(s[i]!=s[s.size()-i-1]){
        return false;
    }
    
   return palin(i=i+1,s);
}

int main() {
    
    string s="madam";
    bool output=palin(0,s);
    
    cout<<output;
  
    return 0;
}
