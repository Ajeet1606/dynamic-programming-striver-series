
# [Frog Jump](https://www.codingninjas.com/codestudio/problem-details/frog-jump_3621012)

### Easy

There is a frog on the 1st step of an N stairs long
 staircase. The frog wants to reach the Nth stair.
  HEIGHT[i] is the height of the (i+1)th stair.
  If Frog jumps from ith to jth stair, the energy
   lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.
   In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.


### For Example
```
If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.
```

### Input Format:
```
The first line of the input contains an integer, 'T,’ denoting the number of test cases.

The first line of each test case contains a single integer,' N’, denoting the number of stairs in the staircase,

The next line contains ‘HEIGHT’ array.
```

### Output Format:
```
For each test case, return an integer corresponding to the minimum energy lost to reach the last stair.
```

### Constraints:
```
1 <= T <= 10
1 <= N <= 100000.
1 <= HEIGHTS[i] <= 1000 .

Time limit: 1 sec
```