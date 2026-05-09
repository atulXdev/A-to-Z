Question:https://www.naukri.com/code360/problems/square-root-integral_893351?leftPanelTabValue=SUBMISSION


int floorSqrt(int n)
{
   int low=1;
   int high=n;
   int ans=0;
   while(low<=high){
       long long mid=(low+high)/2;
       long long val=mid*mid;

       if(val<=n){
       low=mid+1;
       }
       else{
           high=mid-1;
       }
   }

   return high;
}
