import java.util.ArrayList;

//Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class main {
    public static void main(String[] args) {
        // Various test cases.
        ListNode input_value = new ListNode(4);
        input_value.next = new ListNode(2);
        input_value.next.next = new ListNode(1);
        input_value.next.next.next = new ListNode(3);

        // ListNode input_value = new ListNode(-1);
        // input_value.next = new ListNode(5);
        // input_value.next.next = new ListNode(3);
        // input_value.next.next.next = new ListNode(4);
        // input_value.next.next.next.next = new ListNode(0);

        // Display the starting value.
        ListNode current_node = input_value;
        System.out.println("Input Value: ");
        while (null != current_node)
        {
            System.out.println(current_node.val);
            current_node = current_node.next;
        }

        // Perform the operation on the data.
        Solution mySolution = new Solution();
        current_node = mySolution.sortList(input_value);

        // Display the final value.
        System.out.println("Output Value: ");
        while (null != current_node)
        {
            System.out.println(current_node.val);
            current_node = current_node.next;
        }
    }
}

class Solution {
    public ListNode sortList(ListNode head) {
        if (null == head)
        {
            return head;
        }

        ListNode current_node = head;
        ArrayList<ListNode> nodes_as_list = new ArrayList<ListNode>();

        // Load the values into a sortable structure.
        while (current_node != null)
        {
            nodes_as_list.add(current_node);
            current_node = current_node.next;
        }

        // Sort in ascending order.
        nodes_as_list.sort((node_one, node_two) -> Integer.compare(node_one.val, node_two.val));

        // Note the new head of the arraylist in order to return it later.
        current_node = head = nodes_as_list.get(0);

        // Relink the singly linked list nodes in sorted order.
        int node_list_length = nodes_as_list.size();
        for (int i_each_node = 1; i_each_node < node_list_length; ++i_each_node)
        {
            current_node.next = nodes_as_list.get(i_each_node);
            current_node = current_node.next;
        }

        // Designate the new end of the list to avoid a potential circularly linked list.
        current_node.next = null;

        return head;
    }
}
