class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n, 0);

        // finding suffix sum
        for(int i = n - 2; i >= 0; i--) {
            res[i] = nums[i+1] + res[i+1];
        }

        // finding prefix sum and subtracting
        int lsum = 0;
        for(int i = 1; i < n; i++) {
            lsum += nums[i-1];
            res[i] = abs(res[i] - lsum);
        }

        return res;
    }
};