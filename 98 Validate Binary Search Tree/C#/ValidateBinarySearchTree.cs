// Definition for a binary tree node.
public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class main
{
    static public void Main(String[] args)
    {
        // Various test cases.

        // 213
        // TreeNode input_value = new TreeNode(val:2);
        // input_value.left = new TreeNode(val:1);
        // input_value.right = new TreeNode(val:3);

        // 51436
        // TreeNode input_value = new TreeNode(val:5);
        // input_value.left = new TreeNode(val:1);
        // input_value.right = new TreeNode(val:4);
        // input_value.right.left = new TreeNode(val:3);
        // input_value.right.right = new TreeNode(val:6);

        // 222
        // TreeNode input_value = new TreeNode(val:2);
        // input_value.left = new TreeNode(val:2);
        // input_value.right = new TreeNode(val:2);

        // 5460037
        TreeNode input_value = new TreeNode(val: 5);
        input_value.left = new TreeNode(val: 4);
        input_value.right = new TreeNode(val: 6);
        input_value.left.left = null;
        input_value.left.right = null;
        input_value.right.left = new TreeNode(val: 3);
        input_value.right.right = new TreeNode(val: 7);

        // Display the starting value.
        Queue<TreeNode> display_this_tree = new Queue<TreeNode>();
        display_this_tree.Enqueue(input_value);
        TreeNode current_node = null;
        while (0 < display_this_tree.Count)
        {
            current_node = display_this_tree.Dequeue();
            Console.WriteLine("Input Value: {0}", current_node.val.ToString());
            if (null != current_node.left)
            {
                display_this_tree.Enqueue(current_node.left);
            }
            if (null != current_node.right)
            {
                display_this_tree.Enqueue(current_node.right);
            }
        }

        // Perform the operation on the data.
        // Display the final value.
        Solution mySolution = new Solution();
        Console.WriteLine("Output Value: {0}", mySolution.IsValidBST(input_value));
    }
}

public class Solution
{
    private bool recursive_validate(TreeNode subtree_root, int? must_be_smaller_than_this_value, int? must_be_larger_than_this_value)
    {
        // Confirm that this node value is smaller/less than the smallest preceding node value - this could be the root value, it could be some other left side node value.
        // Note that this leverages a quirk of C# whereby comparing null to any value results in false.  Thus, if the nullable int is set to null, the result is false.
        if (must_be_smaller_than_this_value <= subtree_root.val)
        {
            return false;
        }

        // Confirm that this node value is larger/greater than the largest preceding node value - this could be the root value, it could be some other right side node value.
        // Note that this leverages a quirk of C# whereby comparing null to any value results in false.  Thus, if the nullable int is set to null, the result is false.
        if (must_be_larger_than_this_value >= subtree_root.val)
        {
            return false;
        }

        // If the left side of the tree has been populated, explore down that side.
        if (null != subtree_root.left)
        {
            // Since the above comparison succeeded, this node's value is less than the prior nodes in the tree.  Thus, it can be passed in as the smallest/lowest value yet found.
            if (!recursive_validate(subtree_root.left, subtree_root.val, must_be_larger_than_this_value))
            {
                // If a comparison somewhere down the tree resulted in false, the tree is not valid, bubble the result up the chain.
                return false;
            }
        }

        // If the right side of the tree has been populated, explore down that side.
        if (null != subtree_root.right)
        {
            // Since the above comparison succeeded, this node's value is less than the prior nodes in the tree.  Thus, it can be passed in as the largest/greatest value yet found.
            if (!recursive_validate(subtree_root.right, must_be_smaller_than_this_value, subtree_root.val))
            {
                // If a comparison somewhere down the tree resulted in false, the tree is not valid, bubble the result up the chain.
                return false;
            }
        }

        return true;
    }

    public bool IsValidBST(TreeNode root)
    {
        // If the left side of the tree has been populated, explore down that side.
        if (null != root.left)
        {
            // Every node on left side of the tree must be smaller/less than the root value.
            if (false == recursive_validate(root.left, root.val, null))
            {
                //  Some value, somewhere on the left side was invalid.
                return false;
            }
        }

        // If the right side of the tree has been populated, explore down that side.
        if (null != root.right)
        {
            // Every node on left side of the tree must be larger/greater than the root value.
            if (false == recursive_validate(root.right, null, root.val))
            {
                //  Some value, somewhere on the right side was invalid.
                return false;
            }
        }

        // If both sides of the tree have been explored, and no issue was found, the tree is valid.
        return true;
    }
}
