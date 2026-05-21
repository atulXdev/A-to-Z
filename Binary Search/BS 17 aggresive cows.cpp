//bs

https://takeuforward.org/plus/dsa/problems/aggressive-cows?source=strivers-a2z-dsa-track


https://www.naukri.com/code360/problems/aggressive-cows_1082559

class Solution {

public:
bool checkposs(vector<int> & arr,int dist,int cows){
    int cowsCount=1;
    //phla cow will always at 0 index, so our last cow 
    int last=arr[0];

    for(int i=1;i<arr.size();i++){
        if(arr[i]-last>=dist){
            cowsCount++;
            last=arr[i];
        }
    }

    if(cowsCount>=cows){
        return true;
    }

    return false;
}
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=1;
        int high=nums[n-1]-nums[0];

        while(low<=high){
            int mid=(low+high)/2;

          if(  checkposs(nums,mid,k)==true){
            low=mid+1;
          }

          else{
            high=mid-1;
          }
        }

        return high;


        
    }
};