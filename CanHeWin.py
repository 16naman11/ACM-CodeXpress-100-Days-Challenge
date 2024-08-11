'''In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.

Given two integers maxChoosableInteger and desiredTotal, print "yes" if the first player to move can force a win, otherwise, print "no". Assume both players play optimally.'''


def can_win(maxChoosableInteger, desiredTotal):
    # If the maximum achievable sum with all integers is less than the desired total, the first player cannot win.
    if (1 + maxChoosableInteger) * maxChoosableInteger // 2 < desiredTotal:
        return "no"

    # Initialize a dictionary to store previously computed results.
    memo = {}

    def can_win_helper(remaining, state):
        if state in memo:
            return memo[state]

        # Iterate through each integer.
        for i in range(1, maxChoosableInteger + 1):
            # Check if the current integer has been used.
            if state & (1 << i) == 0:
                # If choosing the current integer results in a win or forces the opponent to lose, return True.
                if remaining - i <= 0 or not can_win_helper(remaining - i, state | (1 << i)):
                    memo[state] = True
                    return True

        # If no winning move is found, mark this state as False and return False.
        memo[state] = False
        return False

    # Call the helper function starting with the initial total and no integers chosen.
    return "yes" if can_win_helper(desiredTotal, 0) else "no"

# Input reading and test case handling
T = int(input().strip())
for _ in range(T):
    maxChoosableInteger, desiredTotal = map(int, input().strip().split())
    print(can_win(maxChoosableInteger, desiredTotal))