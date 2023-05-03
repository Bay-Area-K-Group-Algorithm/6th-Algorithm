## Link
[Burst Balloons](https://leetcode.com/problems/burst-balloons/)

## Topic
* Dynamic Programming

## Approach
1. **Subproblem**: `dp(lo, hi)` returns the maximum possible score from `nums[lo:hi].`
2. **Guess**:  Which ballon `lo <= i <= hi` should be bursted *lastly* to return the optimal solution?
3. **Recurrence**: `dp(lo, hi)` is the maximum among `dp(lo, i-1) + dp(i+1, hi) + nums[lo-1] * nums[i] * nums[hi+1]` for `lo <= i <= hi.`
4. **Topology**: from shorter to longer substrings.
5. **Solve**: `dp(0, n-1).`
   
<!-- ## Note
-->