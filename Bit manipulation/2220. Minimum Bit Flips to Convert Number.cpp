class Solution {
public:
    int minBitFlips(int start, int goal) {
        //if we will do XOR in start and goal the no of set bits give no of flips
        //then simply count no of 1 eg your ans
        int ans=start^goal;
        int count=0;

        //its int so we will go till 31

        for(int i=0;i<=31;i++){
            if(ans&(1<<i)){
                count++;
            }

        }

        return count;
        
    }
};