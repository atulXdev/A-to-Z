#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >>arr[i];
    }
    
    //precompute
    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]=+1;
    }SS
    
    //how many times X appears
    int q;
cin >> q;

while(q--) {
    int number;
    cin >> number;
    cout << hash[number] << endl;
}
    

    return 0;
}

-------------------------------------------------------------------------------------------------------------------------------

//hashing using Character array
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    
    //precompute 
    int hash[26]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }
    
    //fetching based on multiple queries
    int q;
    cin >>q;
    
    while(q--){
        char c;
        cin>>c;
        
        cout <<hash[c-'a'] <<endl;
    }
    
    
    return 0;
}


---------------------------------------------------------------------------------------------------------------------------
//Using Map
#include <bits/stdc++.h>
using namespace std;

int main() {
 int arr[5]={1,1,2,3,3};
 
 //precompute
 map<int,int> mpp;
 for(int i=0;i<5;i++){
     mpp[arr[i]]++;
 }
 
 //fetching
 int q;
 cin >>q;
 while(q--){
     int num;
     cin>>num;
     
     cout << mpp[num]<<endl;
 }
    
    
    return 0;
}
