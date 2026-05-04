class Solution {
  public:
    int firstSearch(vector<int> &arr, int k) {
      
     int n=arr.size();
     int low=0;
     int high=n-1;
     int mid;
     
     while(low<=high){
          mid=(high+low)/2;
         
         if(arr[mid]==k){
             return mid;
         }
         
         else if(arr[mid]>k){
             high=mid-1;
         }
         
         else{
             low=mid+1;
         }
     }
     
     return -1;
        
    }
};


//recursive Binary Search

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int bs(int arr[],int low,int high,int target){
    if(low>high){
        return -1;
    }
    
    int mid=(high+low)/2;
    
    if(target==arr[mid]){
        return mid;
    }
    
    if(target>arr[mid]){
       return bs(arr,low=mid+1,high,target);
    }
    
       return bs(arr,low,high=mid-1,target);
    
}

int main()
{
    int arr[]={4,6,18,31,21,67};
    int ans=bs(arr,0,5,21);
    cout <<ans;
    return 0;
}