//bruteforce 
class Solution {
public:

bool possible(vector<int>& arr,int day,int m,int k){
    int noOfBloom=0;
    int count=0;
    int n=arr.size();

    for(int i=0;i<n;i++){
        
        //count will increase till we get consicutive no of days of blooming
        //when we incounter non blooming day count=0 then compute noOfbloom then
        //start looking for next consecutive
        if(arr[i]<=day){
            count++;
        }

        else{
            noOfBloom+=count/k;
            count=0;
        }
    }

    //agar koi non blooming mila hi nhe tvi compute hoga.At last final compute
    noOfBloom+=count/k;

    if(noOfBloom>=m){
        return true;
    }

    else{
        return false;
    }
}

int minDays(vector<int>& bloomDay, int m, int k) {

    //if total flowers required is greater than available flowers
    if((long long)m*k > bloomDay.size()){
        return -1;
    }

    int maxi=*max_element(bloomDay.begin(),bloomDay.end());

    for(int day=1;day<=maxi;day++){
        if(possible(bloomDay,day,m,k)){
            return day;
        }

    }

    return -1;

        
    }
};

//Binary search optimized

//bruteforce 
class Solution {
public:

bool possible(vector<int>& arr,int day,int m,int k){
    int noOfBloom=0;
    int count=0;
    int n=arr.size();

    for(int i=0;i<n;i++){
        
        //count will increase till we get consicutive no of days of blooming
        //when we incounter non blooming day count=0 then compute noOfbloom then
        //start looking for next consecutive
        if(arr[i]<=day){
            count++;
        }

        else{
            noOfBloom+=count/k;
            count=0;
        }
    }

    //agar koi non blooming mila hi nhe tvi compute hoga.At last final compute
    noOfBloom+=count/k;

  return noOfBloom>=m;
}

int minDays(vector<int>& bloomDay, int m, int k) {

    //if total flowers required is greater than available flowers
    if((long long)m*k > bloomDay.size()){
        return -1;
    }
   
   int mini=INT_MAX;
   int maxi=INT_MIN;
   for(int i=0;i<bloomDay.size();i++){
    mini=min(bloomDay[i],mini);
    maxi=max(bloomDay[i],maxi);
   }

  int low=mini;
  int high=maxi;

  while(low<=high){
    int mid=(low+high)/2;

    if(possible(bloomDay,mid,m,k)){
        high=mid-1;
    }
    else{
        low=mid+1;
    }
  }

  return low;
        
    }
};