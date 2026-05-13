optimized by Bs

class Solution {
public:
  int findDays(vector<int> arr,int cap){
    int days=1,load=0;
    for(int i=0;i<arr.size();i++){

        if(arr[i]+load>cap){
            days+=1;
            load=arr[i];
        }

        else{
            load+=arr[i];
        }
    }

    return days;
  }
    int shipWithinDays(vector<int>& weights, int days) {

        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);

        while(low<=high){
            int mid=(low+high)/2;

            int noOfdays=findDays(weights,mid);

            if(noOfdays<=days){
                high=mid-1;
            }

            else{
                low=mid+1;
            }
        }

        return low;

        
    }
};