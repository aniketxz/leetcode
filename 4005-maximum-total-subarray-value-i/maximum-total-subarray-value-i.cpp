class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        return 1LL * k * (max_val - min_val);
    }
};