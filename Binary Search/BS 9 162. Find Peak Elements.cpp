class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        //if one element
        if(n==1){
            return 0;
        }
        //Edge case where fisrt or last elemnt can be peak
        if(nums[0]>nums[1]){
            return 0;
        }

        if(nums[n-1]>nums[n-2]){
            return n-1;
        }

        int low=1;
        int high=n-2;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid-1]&& nums[mid]>nums[mid+1]){
                return mid;
            }
            //if mid on increasing curve then trim the left half

            else if(nums[mid]>nums[mid-1]){
                low=mid+1;

            }

            else{

                high=mid-1;
            }
        }

        return -1;  
        
    }
};