class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();

        // Total subsets = 2^n
        // Example: n = 3
        // 1 << 3 = 8
        // Masks will go from 0 to 7
        int subset = 1 << n;

        vector<vector<int>> ans;

        // Every number (mask) represents one subset
        for (int i = 0; i < subset; i++) {

            vector<int> l;

            // Check every bit position
            for (int j = 0; j < n; j++) {

                // Create a mask with only jth bit set
                // j=0 -> 001
                // j=1 -> 010
                // j=2 -> 100
                if (i & (1 << j)) {

                    // If jth bit is ON,
                    // include nums[j] in subset
                    l.push_back(nums[j]);
                }
            }

            // Store current subset
            ans.push_back(l);
        }

        return ans;
    }
};