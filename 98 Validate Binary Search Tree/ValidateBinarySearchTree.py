# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def isValidBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        # If the left side of the tree has been populated, explore down that side.
        if (None != root.left):
            # Every node on left side of the tree must be smaller/less than the root value.
            if (False == self.recursive_validate(root.left, root.val, None)):
                # Some value, somewhere on the left side was invalid.
                return False

        # If the right side of the tree has been populated, explore down that side.
        if (None != root.right):
            # Every node on left side of the tree must be larger/greater than the root value.
            if (False == self.recursive_validate(root.right, None, root.val)):
                # Some value, somewhere on the right side was invalid.
                return False

        # If both sides of the tree have been explored, and no issue was found, the tree is valid.
        return True


    def recursive_validate(self, subtree_root, must_be_smaller_than_this_value, must_be_larger_than_this_value):
        # Confirm that this node value is smaller/less than the smallest preceding node value - this could be the root value, it could be some other left side node value.
        if ((None != must_be_smaller_than_this_value) and (must_be_smaller_than_this_value <= subtree_root.val)):
                return False

        # Confirm that this node value is larger/greater than the largest preceding node value - this could be the root value, it could be some other right side node value.
        if ((None != must_be_larger_than_this_value) and (must_be_larger_than_this_value >= subtree_root.val)):
                return False

        # If the left side of the tree has been populated, explore down that side.
        if (None != subtree_root.left):
            # Since the above comparison succeeded, this node's value is less than the prior nodes in the tree.  Thus, it can be passed in as the smallest/lowest value yet found.
            if (False == self.recursive_validate(subtree_root.left, subtree_root.val, must_be_larger_than_this_value)):
                # If a comparison somewhere down the tree resulted in false, the tree is not valid, bubble the result up the chain.
                return False

        # If the right side of the tree has been populated, explore down that side.
        if (None != subtree_root.right):
            # Since the above comparison succeeded, this node's value is less than the prior nodes in the tree.  Thus, it can be passed in as the largest/greatest value yet found.
            if (False == self.recursive_validate(subtree_root.right, must_be_smaller_than_this_value, subtree_root.val)):
                # If a comparison somewhere down the tree resulted in false, the tree is not valid, bubble the result up the chain.
                return False

        return True


# Various test cases.

# 213
# input_value = TreeNode(val=2)
# input_value.left = TreeNode(val=1)
# input_value.right = TreeNode(val=3)

# 51436
# input_value = TreeNode(val=5)
# input_value.left = TreeNode(val=1)
# input_value.right = TreeNode(val=4)
# input_value.right.left = TreeNode(val=3)
# input_value.right.right = TreeNode(val=6)

# 222
input_value = TreeNode(val=2)
input_value.left = TreeNode(val=2)
input_value.right = TreeNode(val=2)

# 5460037
# input_value = TreeNode(val=5)
# input_value.left = TreeNode(val=4)
# input_value.right = TreeNode(val=6)
# input_value.left.left = None
# input_value.left.right = None
# input_value.right.left = TreeNode(val=3)
# input_value.right.right = TreeNode(val=7)

# Perform the operation on the data.
mySolution = Solution()
result = mySolution.isValidBST(root=input_value)

# Display the final value.
print("Output Value: ", result)
