qes link:https://www.naukri.com/code360/problems/nth-root-of-m_1062679

//Find Nth root of m

 //fun to get nth root of m:without overloading
  //return 1 if==m
  //return 0 if<m
  //return 2 if>m

  int fun(int mid,int n,int m){
    long long ans=1;

    for(int i=1;i<=n;i++){
      ans=ans*mid;
      //checking inside the loop for overflow
      if(ans>m){
      return 2;
    }
    }
    

    if(ans==m){
      return 1;
    }

    return 0;

  }
int NthRoot(int n, int m) {
 int low=1;
 int high=m;
 while(low<=high){
   int mid=(low+high)/2;
   int medi=fun(mid,n,m);

   if(medi==1){
     return mid;
   }

   else if(medi==0){
     low=mid+1;
   }

   else{
     high=mid-1;
   }
 }

 return -1;
}