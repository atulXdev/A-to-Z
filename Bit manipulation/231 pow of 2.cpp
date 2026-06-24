class Solution {
public:
    bool isPowerOfTwo(int n) {
        //a no is pow of  2 if it has only one set bit
        //ex a no is 5 bit 010100 and no 4 eg 5-1 has right most bit zero and all right bit 1
        //010011
        //so prev no ek sath and kro agar 0 aya then pow of 2

         if (n <= 0) return false;

        return (n & (n - 1)) == 0;
        
    }
};