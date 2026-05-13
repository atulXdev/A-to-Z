//Bruteforce
// BS 14 1283. Find the Smallest Divisor Given a Threshold
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());

        for(int i=1;i<=maxi;i++){
            int sum=0;
            for(int n:nums){
                sum += ceil((double)n / i);
            }

            if(sum<=threshold){
                return i;
            }
        }

        return -1;
        
    }
};


//optmized BS

class Solution {
public:

int sumByD(vector<int> &arr,int d){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=ceil((double)arr[i]/d);
    }

    return sum;
}


    int smallestDivisor(vector<int>& nums, int threshold) {

        int low=1;
        int maxi=*max_element(nums.begin(),nums.end());
        int high=maxi;

        while(low<=high){
            int mid=(high+low)/2;

            if(sumByD(nums,mid)<=threshold){
                high=mid-1;
            }

            else{
                low=mid+1;
            }
        }

        return low;


        
    }
};