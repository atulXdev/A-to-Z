//leetcode ques:34
//Time O(n)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
 //time O(n)--> we want in O(logn) linear search
  int first=-1;
  int second=-1;
  int n=nums.size();
   for(int i=0;i<n;i++){
    if(nums[i]==target){
        if(first==-1){
            first=i;

       }

       second=i;
    }
   } 
   vector<int> ans={first,second};

   return ans;   
    }
};


//optimized

class Solution {
public:

    int firstocc(vector<int>& nums, int n, int target) {
        int low = 0;
        int high = n - 1;
        int first = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                first = mid;
                high = mid - 1; // move left
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return first;
    }

    int secondocc(vector<int>& nums, int n, int target) {
        int low = 0;
        int high = n - 1;
        int second = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                second = mid;
                low = mid + 1; // move right
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return second;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int first = firstocc(nums, n, target);

        if (first == -1)
            return {-1, -1};

        int last = secondocc(nums, n, target);

        return {first, last};
    }
};