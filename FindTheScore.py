#You are given an array nums consisting of positive integers.

#Starting with score = 0, apply the following algorithm:

#Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
#Add the value of the chosen integer to score.
#Mark the chosen element and its two adjacent elements if they exist.
#Repeat until all the array elements are marked.
#Print the score you get after applying the above algorithm.


# Function to calculate the score for a given array
def calculate_score(nums):
    n = len(nums)
    marked = [False] * n
    score = 0
    
    # Iterate until all elements are marked
    while not all(marked):
        # Find the smallest unmarked element and its index
        min_value = float('inf')
        min_index = -1
        for i in range(n):
            if not marked[i] and nums[i] < min_value:
                min_value = nums[i]
                min_index = i
        
        # Mark the chosen element and its two adjacent elements if they exist
        score += min_value
        marked[min_index] = True
        if min_index > 0:
            marked[min_index - 1] = True
        if min_index < n - 1:
            marked[min_index + 1] = True
    
    return score

# Input reading and processing
T = int(input())
for _ in range(T):
    _ = int(input())  # Size of array, not needed for calculation
    nums = list(map(int, input().split()))
    
    # Calculate and print the score for the current test case
    print(calculate_score(nums))
