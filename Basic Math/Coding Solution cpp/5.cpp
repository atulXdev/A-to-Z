//print all divisor of no
//time :O(n) not passing alll test cases

// class Solution {
//   public:
//     void print_divisors(int n) {
//         for(int i=1;i<=n;i++){
//             if(n%i==0){
//                 cout << i <<" ";
//             }
//         }
        
//     }
// }


//optimized

class Solution {
  public:
    void print_divisors(int n) {
        vector<int> ls;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
               ls.push_back(i);
               
               if((n/i)!=i){
                ls.push_back(n/i);
            }
            }
            
            
        }
        
        sort(ls.begin(),ls.end());
        
        for(auto it :ls){
            cout <<it <<" ";
        }
        
    }
};