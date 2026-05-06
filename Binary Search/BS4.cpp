//ques:33
class Solution {
public:
    int search(vector<int>& nums, int target) {
         //always check for the sorted half either its left for right;
        //after getting the sorted half check your target lies under that sorted half
        int n=nums.size();
        int low=0;
        int high=n-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                return mid;
            }

            //if left half is sorted
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;

                }
                else{
                    low=mid+1;
                }
            }

            //right half sorted
            else{
                if(nums[high]>=target && target>=nums[mid]){
                    low=mid+1;
                }

                else{
                    high=mid-1;
                }
            }

        }
        return -1;
    }
};