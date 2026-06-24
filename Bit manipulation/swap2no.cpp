#include <iostream>

using namespace std;
//XOR : even no of 1->0       odd no of 1->1
//xor of num with same num is 0 :eg 5^5=0

int main() {
    int a=5,b=10;
    
    a=a ^ b;
    b=a ^ b;
    //(a^b)^b=a
    a=a ^ b; //(a^b)^a =b
    
    cout <<a<<endl;
    cout <<b<<endl;
  

    return 0;
}