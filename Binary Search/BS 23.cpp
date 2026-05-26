//Find row with max 1
//bruteforce
class Solution {
  public:   
  int rowWithMax1s(vector < vector < int >> & mat) {
    int count =0;
    int maxOne=0;
    int rowmaxone=-1;
    int row=mat.size();
    int col=mat[0].size();

    for(int i=0;i<row;i++){

        for(int j=0;j<col;j++){
            count=0;
            if(mat[i][j]==1){
                count++;
            }
            if(count>maxOne){
                maxOne=count;
                rowmaxone=i;
            }
        }
    }

    return rowmaxone;

  }
};


//BS

class Solution {
  public: 
  int lowerbound(vector<int> &arr,int n,int x){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return ans;
  }  
  int rowWithMax1s(vector < vector < int >> & mat) {
    int n=mat.size();
    int m=mat[0].size();
    int cmax=-1;
    int index=-1;

    for(int i=0;i<n;i++){

        int count=m-lowerbound(mat[i],m,1);

        if(count>cmax && count>0){
            cmax=count;
            index=i;
        }
        
    }

    return index;



  }
};