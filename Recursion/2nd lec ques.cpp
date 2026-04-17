//printing name n times
#include <iostream>
using namespace std;
//time:O(n) n recursion calls
//space:O(n) jitna function call utna stack full
void printname(int i,int n){
    if(i>n){
        return;
    }
    
    cout<<"Akay"<<endl;
    
    printname(i+1,n);
};
int main() {
    printname(1,3);
    
    

    return 0;
}

//printing 1 to n
#include <iostream>
using namespace std;
void printname(int i,int n){
    if(i>n){
        return;
    }
    
    cout<<i<<endl;
    
    printname(i+1,n);
};
int main() {
    printname(1,4);
    
    

    return 0;
}

//printing in reverse order
#include <iostream>
using namespace std;
void printname(int i,int n){
    if(i<n){
        return;
    }
    
    cout<<i<<endl;
    
    printname(i-1,n);
};
int main() {
    printname(4,1);
    
    

    return 0;
}

//printing in staright order but by i--==>Using backtracking
//we will print in last sare function call stack me jayenge
//like-->Return krenge reverse me so ulta chlenge firvi ans sidha hi ayega
#include <iostream>
using namespace std;
void printnum(int i,int n){
    if(i<1){
        return;
    }
    printnum(i-1,n);
    //printing it later after finishing fun call
    cout<<i <<endl;
}


int main() {
    
    printnum(3,3);
   

    return 0;
}