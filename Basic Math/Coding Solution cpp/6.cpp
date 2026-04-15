//check for prime
class Solution {
  public:
    bool isPrime(int n) {
       int count=0;
       
       for(int i=1;i<=sqrt(n);i++){
           if(n%i==0){
               count++;
               
               if(n/i!=i){
                   count++;
               }
           }
       }
       
       if(count==2){
           return true;
       }
       
       else{
           return false;
       }
        
    }
};