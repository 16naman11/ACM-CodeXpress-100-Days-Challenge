'''You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, print the maximum amount of money you can rob tonight without alerting the police.'''

def max_money(nums):
    n = len(nums)
    
    if n == 0:
        return 0
    if n == 1:
        return nums[0]
    
    # Initialize an array to store the maximum amount robbed up to each house
    dp = [0] * n
    
    # Base cases
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])
    
    # Iterate through the houses and calculate the maximum amount robbed at each house
    for i in range(2, n):
        dp[i] = max(dp[i-1], dp[i-2] + nums[i])
    
    # The final result is the maximum amount robbed at the last house
    return dp[-1]

# Input reading and processing
T = int(input())
for _ in range(T):
    n = int(input())
    nums = list(map(int, input().split()))
    
    # Calculate and print the maximum amount of money that can be robbed
    result = max_money(nums)
    print(result)
