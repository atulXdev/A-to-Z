


// Find out how many times the array is rotated
// Subscribe to TUF+

// Hints
// Company
// Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 0 and n-1 (including). Determine the number of rotations performed on the array.


// Example 1

// Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]

// Output: 4

// Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.

// Example 2

// Input: nums = [3, 4, 5, 1, 2]

// Output: 3

// Explanation: The original array should be [1, 2, 3, 4, 5]. So, we can notice that the array has been rotated 3 times.

// Now your turn!

// Input: nums = [4, 5, 1, 2]

// Output:

// Pick your answer

class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        //trick:index of min element  gives no of rotation
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=INT_MAX;
        int index=-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(nums[low]<=nums[high]){
                if(nums[low]<ans){
                    ans=nums[low];
                    index=low;
                }

                break;
            }

            //left half sorted
            if(nums[low]<=nums[mid]){
                if(nums[low]<ans){
                    ans=nums[low];
                    index=low;
                }
                low=mid+1;
            }

            else{
                if(nums[low]<ans){
                    ans=nums[low];
                    index=low;
                }

                high=mid-1;
            }
        }

        return index;

        
    }
};