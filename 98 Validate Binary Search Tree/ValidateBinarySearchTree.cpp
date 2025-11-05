#include <iostream>
#include <optional>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    bool recursive_validate(TreeNode* subtree_root, optional<int> must_be_smaller_than_this_value, optional<int> must_be_larger_than_this_value)
    {
        // Confirm that this node value is smaller/less than the smallest preceding node value - this could be the root value, it could be some other left side node value.
        if ((must_be_smaller_than_this_value.has_value()) && (must_be_smaller_than_this_value <= subtree_root->val))
        {
            return false;
        }

        // Confirm that this node value is larger/greater than the largest preceding node value - this could be the root value, it could be some other right side node value.
        if ((must_be_larger_than_this_value.has_value()) && (must_be_larger_than_this_value >= subtree_root->val))
        {
            return false;
        }

        // If the left side of the tree has been populated, explore down that side.
        if (nullptr != subtree_root->left)
        {
            // Since the above comparison succeeded, this node's value is less than the prior nodes in the tree.  Thus, it can be passed in as the smallest/lowest value yet found.
            if (!recursive_validate(subtree_root->left, subtree_root->val, must_be_larger_than_this_value))
            {
                // If a comparison somewhere down the tree resulted in false, the tree is not valid, bubble the result up the chain.
                return false;
            }
        }

        // If the right side of the tree has been populated, explore down that side.
        if (nullptr != subtree_root->right)
        {
            // Since the above comparison succeeded, this node's value is less than the prior nodes in the tree.  Thus, it can be passed in as the largest/greatest value yet found.
            if (!recursive_validate(subtree_root->right, must_be_smaller_than_this_value, subtree_root->val))
            {
                // If a comparison somewhere down the tree resulted in false, the tree is not valid, bubble the result up the chain.
                return false;
            }
        }

        return true;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        // If the left side of the tree has been populated, explore down that side.
        if (nullptr != root->left)
        {
            // Every node on left side of the tree must be smaller/less than the root value.
            if (false == recursive_validate(root->left, root->val, nullopt))
            {
                //  Some value, somewhere on the left side was invalid.
                return false;
            }
        }

        // If the right side of the tree has been populated, explore down that side.
        if (nullptr != root->right)
        {
            // Every node on left side of the tree must be larger/greater than the root value.
            if (false == recursive_validate(root->right, nullopt, root->val))
            {
                //  Some value, somewhere on the right side was invalid.
                return false;
            }
        }

        // If both sides of the tree have been explored, and no issue was found, the tree is valid.
        return true;
    }
};

void clean_up(TreeNode *delete_me)
{
    if (nullptr != delete_me)
    {
        clean_up(delete_me->left);
        clean_up(delete_me->right);
    }
    delete delete_me;
}

int main()
{
    // Various test cases.

    // 213
    TreeNode *input_value = new TreeNode(2);
    input_value->left = new TreeNode(1);
    input_value->right = new TreeNode(3);

    // 51436
    // TreeNode* input_value = new TreeNode(5);
    // input_value->left = new TreeNode(1);
    // input_value->right = new TreeNode(4);
    // input_value->right->left = new TreeNode(3);
    // input_value->right->right = new TreeNode(6);

    // 222
    // TreeNode* input_value = new TreeNode(2);
    // input_value->left = new TreeNode(2);
    // input_value->right = new TreeNode(2);

    // 5460037
    // TreeNode *input_value = new TreeNode(5);
    // input_value->left = new TreeNode(4);
    // input_value->right = new TreeNode(6);
    // input_value->left->left = nullptr;
    // input_value->left->right = nullptr;
    // input_value->right->left = new TreeNode(3);
    // input_value->right->right = new TreeNode(7);

    // Perform the operation on the data.
    // Display the final value.
    Solution mySolution = Solution();
    bool result = mySolution.isValidBST(input_value);
    printf("Is the Binary Tree Vaild? %s", result ? "True" : "False");

    // Delete the dynamically allocated heap memory.
    clean_up(input_value);
}
