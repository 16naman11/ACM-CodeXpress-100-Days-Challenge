#Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

#Print "Yes" if there is a 132 pattern in nums, otherwise, print "No".

def has_132_pattern(nums):
    n = len(nums)
    if n < 3:
        return "No"

    min_i = nums[0]
    for j in range(1, n - 1):
        for k in range(j + 1, n):
            if min_i < nums[k] < nums[j]:
                return "Yes"
        min_i = min(min_i, nums[j])

    return "No"

# Input
T = int(input())
for _ in range(T):
    n = int(input())
    nums = list(map(int, input().split()))
    
    # Output
    result = has_132_pattern(nums)
    print(result)

