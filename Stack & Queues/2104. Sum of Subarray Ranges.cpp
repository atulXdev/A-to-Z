//EXTREME BRUTEFORCE


class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                maxi=max(maxi,nums[j]);
                mini=min(mini,nums[j]);
                int diff=maxi-mini;
                sum+=diff;
                }
                maxi=INT_MIN;
                mini=INT_MAX;
        }

        return sum;
        
    }
};

//OPTIMIZED SOLUTION