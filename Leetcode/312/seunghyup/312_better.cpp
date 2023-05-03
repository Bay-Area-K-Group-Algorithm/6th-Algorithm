// Time: O(n^3 k^2) where n is nums.size() and k is number of distinct values in nums
// Space: O(n^2 k^2)
class Solution {
public:
    unordered_map<int, int> memo;
    int maxCoins(vector<int>& nums) {
        return dp(nums, 0, (int)nums.size()-1, 1, 1);
    }

    int dp(const vector<int>& nums, const int& lo, const int& hi, const int& left, const int& right) {
        if (lo > hi) {
            return 0;
        }
        else {
            int key = ((lo * 300 + hi) * 101 + left) * 101 + right;
            if (memo.find(key) == memo.end()) {
                for (int i = lo; i <= hi; ++i) {
                    memo[key] = max(memo[key], left * nums[i] * right + dp(nums, lo, i-1, left, nums[i]) + dp(nums, i+1, hi, nums[i], right));
                }
            }
            return memo[key];
        }
    }
};