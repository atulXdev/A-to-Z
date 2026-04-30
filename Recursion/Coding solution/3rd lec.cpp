//first n numbers of parameter recur
#include <iostream>
using namespace std;

void printsum(int num,int sum){
    if(num<1){
        cout <<sum;
        return;
    }
    
    printsum(num-1,sum+num);
    
}


int main() {
    
    printsum(3,0);
    
    return 0;
}

//first n numbers by functional

#include <iostream>
using namespace std;

int printsum(int num){
    if(num==0){
        return 0;
    }
    
    return num+printsum(num-1);
}

int main() {
    int result=printsum(3);
    cout << result;
   

    return 0;
}

////factorial n numbers of functional recur

#include <iostream>
using namespace std;

int printfac(int num){
    if(num==1){
        return 1;
    }
    
    return num*printfac(num-1);
}

int main() {
    int result=printfac(5);
    cout << result;
   

    return 0;
}


////factorial n numbers of parameter recur
#include <iostream>
using namespace std;

int printfac(int num,int p){
    
    if(num==p){
        return p;
    }
    
    return num*printfac(num-1,p);
  
  
}

int main() {
    int result=printfac(5,1);
    cout << result;
   

    return 0;
}
