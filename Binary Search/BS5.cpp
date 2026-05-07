//leetcode:Q:81. Search in Rotated Sorted Array II

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                return true;
            }
            //handeling the edge for deuplicate element
            //what happen if low mid and high are same=> how will you check the sorted half
            //simply we will trim the search space
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low=low+1;
                high=high-1;
                continue;
            }

            //if left half is sorted
            if(nums[low]<=nums[mid]){
       //elemnt target in left half range then trim left half
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }

            //else right half is sorted
            else{
                if(nums[high]>=target && target>=nums[mid]){
                    low=mid+1;
                }

                else{

                    high=mid-1;
                }
            }
        }

        return false;
        
        
    }
};