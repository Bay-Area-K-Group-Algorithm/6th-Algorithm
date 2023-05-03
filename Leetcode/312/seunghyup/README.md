## Link
[Burst Balloons](https://leetcode.com/problems/burst-balloons/)

## Topic
* Dynamic Programming

## Approach
1. **Subproblem**: `dp(lo, hi, left, right)` returns the maximum possible score from `nums[lo:hi],` given left and right border values.
2. **Guess**:  Which ballon `lo <= i <= hi` should be bursted *lastly* to return the optimal solution?
3. **Recurrence**: `dp(lo, hi, left, right)` is the maximum among `dp(lo, i-1, left, nums[i]) + dp(i+1, hi, nums[i], right) + left * nums[i]] * right` for `lo <= i <= hi.`
4. **Topology**: from shorter to longer substrings
5. **Solve**: `dp(0, n-1, 1, 1)`
   
<!-- ## Note
-->