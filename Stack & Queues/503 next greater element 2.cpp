class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //by virtual curcular array,we are not making they array elemt two time instead of it
        //we will do something so that it will behvae like circular vector
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
                if(!st.empty() && st.top()>nums[i%n]){
                    ans[i]=st.top();
                }

            }
            st.push(nums[i%n]);
        }

        return ans;
        
    }
};