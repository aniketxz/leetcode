class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int lsum = 0, rsum = accumulate(nums.begin(), nums.end(), 0);

        for(int i = 0; i < n; i++) {
            rsum -= nums[i];
            res[i] = (rsum >= lsum) ? rsum - lsum : lsum - rsum;
            lsum += nums[i];
        }

        return res;
    }
};