class Solution {
public:
 //finding the max banana piles
        int maxpile(vector<int>& v){
            int maxi=INT_MIN;
            int n=v.size();
            for(int i=0;i<n;i++){
               maxi=max(maxi,v[i]);
            }

            return maxi;
        }

          //for each mid elemnt : eg is our banana/hour counting total no of hours
        //its taking for total array traversal
        //for example we get mid as 6 means 6 banana per hours so we will calculate
        //total hours according to this 6 banana per hour

        long long countTotalHours(vector<int> &v,int hourly){
            int n=v.size();
            long long totalH=0;
            for(int i=0;i<n;i++){
                totalH+=ceil((double)v[i]/(double)hourly);
            }
            return totalH;
        }

    int minEatingSpeed(vector<int>& piles, int h) {
       
      
        int low=1;
        int high=maxpile(piles);

        while(low<=high){
            int mid=(low+high)/2;
            long long totalH=countTotalHours(piles,mid);

            if(totalH<=h){
                high=mid-1; //there is possibilty of getting more lower
            }
     //increse to more banana so that on div we get smaller hour so that total hour come smaller
            else{
                low=mid+1;
            }
        }

        return low;
        
    }
};