//540. Single Element in a Sorted Array
//Bruteforce

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //bruteforce:sare element ka left right check krenge agar koi vi equal nhe mila then
        //eg your ans

        int n=nums.size();
        //if array size is 1
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            //for first elemt only right we have
            if(i==0){
                if(nums[i]!=nums[i+1]){
                    return nums[i];
                }
            }

            //if last elememt only left we have
           else if(i==n-1){
            if(nums[i]!=nums[i-1]){
                return nums[i];
            }
           }

           //any middle elemnt we will check left and right both
           else{
            if(nums[i]!=nums[i-1]&& nums[i]!=nums[i+1]){
                return nums[i];
            }
           }
        }

        return -1;
        
    }
};


//optimized solution

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        //handeling all edge cases
        if(n==1){
            return nums[0];
        }
       if(nums[0]!=nums[1]){
        return nums[0];
       } 
       if(nums[n-1]!=nums[n-2]){
        return nums[n-1];
       }
       int low=1;
       int high=n-2;

       while(low<=high){
        int mid=(low+high)/2;
        //uniq element when left and right are not eqaul
        if(nums[mid]!=nums[mid+1]&& nums[mid]!=nums[mid-1] ){
            return nums[mid];
        }
        //if on left half (even,odd) trim the left half
        if((mid%2==0 && nums[mid]==nums[mid+1])||(mid%2==1 && nums[mid]==nums[mid-1])){
            //trim the left half
            low=mid+1;
        }
        //else you are in right half trim the right half
        else{
            high=mid-1;
        }
       }

       return -1;
       
    }
};


