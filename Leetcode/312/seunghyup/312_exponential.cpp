// O(n 2^n) time and space
// Time Limit Exceeded
class Solution {
public:
    unordered_map<vector<bool>, int> memo;
    int maxCoins(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        return dp(nums, used, 0);
    }

    int dp(const vector<int>& nums, vector<bool>& used, const int& numUsed) {
        const int n = (int)nums.size();
        if (n == numUsed) {
            return 0;
        }
        else {
            if (memo.find(used) == memo.end()) {
                vector<int> unusedIndices;
                for (int i = 0; i < used.size(); i++) {
                    if (!used[i]) {
                        unusedIndices.push_back(i);
                    }
                }
                int res = 0;
                for (int i = 0; i < unusedIndices.size(); ++i) {
                    int left = i ? nums[unusedIndices[i-1]] : 1;
                    int cur = nums[unusedIndices[i]];
                    int right = i+1 < unusedIndices.size() ? nums[unusedIndices[i+1]] : 1;
                    used[unusedIndices[i]] = true;
                    res = max(res, left*cur*right + dp(nums, used, numUsed+1));
                    used[unusedIndices[i]] = false;
                }
                memo[used] = res;
            }
            return memo[used];
        }
    }
};