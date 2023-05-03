## Link
[Predict the Winner](https://leetcode.com/problems/predict-the-winner/)

## Topic
* Dynamic Programming (2d)

## Approach
1. **Subproblem**: , where the first player gets the maximum score within the array.
 => The number of subproblems: 
2. **Guess**: In , which end the player would choose? 
3. **Recurrence**: is the max value of
 - + ( - ) (the left end is chosen)
 - + ( - ) (the right end is chosen)
4. **Topology**: smaller to larger (fill the dp table diagonally)
5. **Solve**: 
 
## Note
![DP Table](https://i.imgur.com/uy1wdPD.png) 
- holds the maximum score a player can get from 
- The first column and the last row is added to prevent segmentation fault when accessing and 
- Fill diagonally to compute from smaller to larger size of sub problem.
