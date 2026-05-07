//153. Find Minimum in Rotated Sorted Array

class Solution {
public:
    int findMin(vector<int>& nums) {
        //minimum element may or may not be in sorted part
        //just take the sorted part and simply update the ans with least element of sorted part
        //now we dont care about sorted part now move to other part and do the same;
        int ans=INT_MAX;
        int n=nums.size();
        int low=0;
        int high=n-1;

        while(low<=high){
            int mid=(low+high)/2;

            //if left half is sorted
            if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);

                //now checking right half
                low=mid+1;
            }
            //if right half is sorted
            else{
                ans=min(ans,nums[mid]);

                //check the left half
                high=mid-1;
            }

        }

        return ans;

    }
};