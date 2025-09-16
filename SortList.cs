// Definition for singly-linked list.
public class ListNode
{
    public int val;
    public ListNode next;
    public ListNode(int val = 0, ListNode next = null)
    {
        this.val = val;
        this.next = next;
    }
}

class main
{
    static public void Main(String[] args)
    {
        // Various test cases.
        ListNode input_value = new ListNode(val: 4);
        input_value.next = new ListNode(val: 2);
        input_value.next.next = new ListNode(val: 1);
        input_value.next.next.next = new ListNode(val: 3);

        // ListNode input_value = new ListNode(val:-1);
        // input_value.next = new ListNode(val:5);
        // input_value.next.next = new ListNode(val:3);
        // input_value.next.next.next = new ListNode(val:4);
        // input_value.next.next.next.next = new ListNode(val:0);

        // Display the starting value.
        ListNode current_node = input_value;
        Console.WriteLine("Input Value: ");
        while (current_node != null)
        {
            Console.WriteLine("{0} ", current_node.val.ToString());
            current_node = current_node.next;
        }

        // Perform the operation on the data.
        Solution mySolution = new Solution();
        current_node = mySolution.SortList(input_value);

        // Display the final value.
        Console.WriteLine("Output Value: ");
        while (current_node != null)
        {
            Console.WriteLine("{0} ", current_node.val.ToString());
            current_node = current_node.next;
        }
    }
}

public class Solution
{
    public ListNode SortList(ListNode head)
    {
        if (null == head)
        {
            return head;
        }

        ListNode current_node = head;
        List<ListNode> nodes_as_list = new List<ListNode>();

        // Load the values into a sortable structure.
        while (current_node != null)
        {
            nodes_as_list.Add(current_node);
            current_node = current_node.next;
        }

        // Sort in ascending order.
        nodes_as_list.Sort((x,y) => x.val.CompareTo(y.val));

        // Note the new head of the list in order to return it later.
        current_node = head = nodes_as_list[0];
        
        // Relink the singly linked list nodes in sorted order.
        for (int i_each_node = 1; i_each_node < nodes_as_list.Count; ++i_each_node)
        {
            current_node.next = nodes_as_list[i_each_node];
            current_node = current_node.next;
        }

        // Designate the new end of the list to avoid a potential circularly linked list.
        current_node.next = null;

        return head;
    }
}
