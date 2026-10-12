class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //hardcore bruteforce
        //at each each block we will check the left and right until we encounter a smaller element from the 
        //current bar.
        //at each bar we will go as left as much and as right as much until we encounter a small elem
        //at last we calculte the width eg right-left-1 and area as that block(height)*width
        //TLE AFTER SOME TEST CASE
        int n=heights.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
           int num=heights[i];
           int left=i;
           int right=i;
           while(left>=0 && heights[left]>=num){
            left--;
           }
           while(right<n && heights[right]>=num){
            right++;
           }
           int width=right-left-1;
           int area=num*width;
           maxi=max(maxi,area);
        }
        
        return maxi;
    }

};
-------------------------------------------------------------------------
//simply at each elemt find NSE AND PSE -> WIDTH IS NSE-PSE-1
//AREA=NUM*WIDTH
//THIS WILL BE SUBMITTED

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> psearr(n, -1);
        vector<int> nsearr(n, n);
        stack<int> st;
        stack<int> sti;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (!st.empty()) {
                psearr[i] = st.top();
            }

            st.push(i);
        }

        for (int j = n - 1; j >= 0; j--) {
            while (!sti.empty() && heights[sti.top()] >= heights[j]) {
                sti.pop();
            }

            if (!sti.empty()) {
                nsearr[j] = sti.top();
            }

            sti.push(j);
        }

        for (int i = 0; i < n; i++) {
            int num = heights[i];
            int ps = psearr[i];
            int ns = nsearr[i];

            int width = ns - ps - 1;
            int area = width * num;
            maxi = max(maxi, area);
        }

        return maxi;
    }
};
