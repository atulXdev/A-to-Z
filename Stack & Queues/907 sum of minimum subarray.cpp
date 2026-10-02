//EXTREME BRUTEFORC WITH TLE T:O(N*2)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum=0;
        int mod=(int)(1e9+7);
        
        for(int i=0;i<arr.size();i++){
          int mini=arr[i];
            for(int j=i;j<arr.size();j++){
                if(arr[j]<mini){
                mini=min(mini,arr[j]);}
                sum=(sum+mini)%mod;

            }
        }

        return sum;
        
    }
};


class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // optimized
        // we will take each element has contributed to our answer
        // how many times (in how much subarray it is smaller)
        // like first element 1 contributing our ans 6 times to total += 1 * 6

        // [1,4,6,7,3,7,8,1]
        // take case of 3 -> how many times 3 will contribute
        // -> until if we find new smaller element
        // so that's why we will check next smaller element
        // and prev smaller element of each element

        // upon subtracting index we will get individual contribution
        // of that element

        // like 3:
        // nse = 1 at index 7
        // 7 - 4 = 3 -> 3 can contribute to 3 positions on right
        // prev smaller element = 1 at index 0
        // 4 - 0 = 4 -> 3 can contribute to 4 positions on left

        // total contribution = 4 * 3 = 12 subarrays
        // contribution to answer = 12 * 3 = 36

        int n = arr.size();
        int mod = 1e9 + 7;

        // prevsl[i] = index of previous smaller element
        vector<int> prevsl(n, -1);

        stack<int> st;

        for (int i = 0; i < n; i++) {

            // remove elements greater than current element
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                prevsl[i] = st.top();
            }

            // store index, not value
            st.push(i);
        }

        // nextsl[i] = index of next smaller element
        vector<int> nextsl(n, n);

        // clear stack
        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {

            // remove elements greater than or equal to current element
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nextsl[i] = st.top();
            }

            // store index
            st.push(i);
        }

        long long sum = 0;

        // calculate contribution of every element
        for (int i = 0; i < n; i++) {

            // number of choices on left
            long long left = i - prevsl[i];

            // number of choices on right
            long long right = nextsl[i] - i;

            // total number of subarrays where arr[i]
            // is the minimum
            long long contribution =
                (1LL * arr[i] * left % mod) * right % mod;

            sum = (sum + contribution) % mod;
        }

        return sum;
    }
};
