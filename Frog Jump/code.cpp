int minEnergy(int currentIndex, int target, vector<int>&heights, vector<int>&memo)
{
    if(currentIndex == target)  return 0;
    if(currentIndex > target) return 10000000;
    if(memo[currentIndex] != -1) return memo[currentIndex];

    int oneJump = abs(heights[currentIndex+1]-heights[currentIndex]) + 
                  minEnergy(currentIndex+1,target,heights,memo);
    int twoJump = 10000000;
    if(currentIndex+2 <= target)
        twoJump = abs(heights[currentIndex+2]-heights[currentIndex]) +
                  minEnergy(currentIndex+2,target,heights,memo);

    memo[currentIndex] = min(oneJump,twoJump);
    return memo[currentIndex];
}

int frogJump(int n, vector<int> &heights)
{
    vector<int>memo(n,-1);
    return minEnergy(0,n-1,heights,memo);
}

//Time Complexity = O(2^n), two options at each stage
//Space Complexity = O(n), since we are using memo
