class Solution {
public:
    int digitSum(int num) {
        int sum = 0;

        while(num > 0) {
            sum += (num % 10);
            num /= 10;
        }

        return sum;
    }

    int minElement(vector<int>& nums) {
        int minSum = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            int dSum = digitSum(nums[i]);
            minSum = (dSum < minSum) ? dSum : minSum;
        }

        return minSum;
    }
};