'''Given an array nums of n elements, you need to construct a binary search tree out of that array (just like previous question A binary search tree is a binary tree where the value of each node is greater than or equal to the values of its left subtree and less than the values of its right subtree ).

find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.'''

class TreeNode:
    def __init__(self, value):
        self.val = value
        self.left = None
        self.right = None

def constructBST(nums):
    if not nums:
        return None

    root = TreeNode(nums[0])

    for num in nums[1:]:
        insertNode(root, num)

    return root

def insertNode(root, value):
    if not root:
        return TreeNode(value)

    if value < root.val:
        root.left = insertNode(root.left, value)
    else:
        root.right = insertNode(root.right, value)

    return root

def maxAncestorDiff(root):
    if not root:
        return 0

    return max(
        maxAncestorDiff(root.left),
        maxAncestorDiff(root.right),
        maxDescendantDiff(root.left, root.val),
        maxDescendantDiff(root.right, root.val)
    )

def maxDescendantDiff(node, ancestor_val):
    if not node:
        return 0

    return max(
        abs(node.val - ancestor_val),
        maxDescendantDiff(node.left, ancestor_val),
        maxDescendantDiff(node.right, ancestor_val)
    )

# Input reading and processing
T = int(input())
for _ in range(T):
    n = int(input())
    nums = list(map(int, input().split()))

    # Construct the binary search tree
    root = constructBST(nums)

    # Find and print the maximum ancestor-node difference
    result = maxAncestorDiff(root)
    print(result)

