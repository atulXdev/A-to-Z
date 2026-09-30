//gfg link:https://www.geeksforgeeks.org/problems/previous-smaller-element/1

class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n=arr.size();
      vector<int> ans(n,-1);
      stack<int> st;
      for(int i=0;i<n;i++){
          while(!st.empty() && st.top()>=arr[i]){
              st.pop();
          }
          
          if(!st.empty() && st.top()<arr[i]){
              ans[i]=st.top();
          }
          
          st.push(arr[i]);
      }
      
      return ans;
    }
};