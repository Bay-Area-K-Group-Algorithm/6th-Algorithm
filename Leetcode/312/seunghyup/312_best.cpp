// O(n^3) time and O(n^2) space
class Solution {
public:
    unordered_map<int, int> memo;
    int maxCoins(vector<int>& nums) {
        return dp(nums, 0, (int)nums.size()-1);
    }

    int dp(const vector<int>& nums, const int& lo, const int& hi) {
        if (lo > hi) {
            return 0;
        }
        else {
            const int key = lo * 300 + hi;
            if (memo.find(key) == memo.end()) {
                const int leftBorder = lo ? nums[lo-1] : 1;
                const int rightBorder = hi+1 < nums.size() ? nums[hi+1] : 1;
                for (int i = lo; i <= hi; ++i) {
                    const int leftHalf = dp(nums, lo, i-1);
                    const int rightHalf = dp(nums, i+1, hi);
                    const int thisBalloon = leftBorder * nums[i] * rightBorder;
                    memo[key] = max(memo[key], leftHalf + rightHalf + thisBalloon);
                }
            }
            return memo[key];
        }
    }
};