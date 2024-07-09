'''Given a circular integer array nums of length n, print the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.'''


def max_subarray_sum(nums):

    max_sum = current_sum = nums[0]

    for num in nums[1:]:

        current_sum = max(num, current_sum + num)

        max_sum = max(max_sum, current_sum)

    return max_sum

def max_circular_subarray_sum(nums):

    normal_max = max_subarray_sum(nums)

    if normal_max < 0:

        return normal_max  # All elements are negative, return the normal max

    array_sum = sum(nums)

    inverted_nums = [-num for num in nums]

    circular_max = array_sum + max_subarray_sum(inverted_nums)

    return max(normal_max, circular_max)

def main():

    T = int(input())

    for _ in range(T):

        n = int(input())

        nums = list(map(int, input().split()))

        result = max_circular_subarray_sum(nums)

        print(result)

if __name__ == "__main__":

    main()