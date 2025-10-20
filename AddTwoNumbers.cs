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

        // Set one - same length lists + carryover
        // 243
        // ListNode input_value_one = new ListNode(val: 2);
        // input_value_one.next = new ListNode(val: 4);
        // input_value_one.next.next = new ListNode(val: 3);

        // 564
        // ListNode input_value_two = new ListNode(val: 5);
        // input_value_two.next = new ListNode(val: 6);
        // input_value_two.next.next = new ListNode(val: 4);

        // Set two - both zero values + one node length lists
        // 0
        // ListNode input_value_one = new ListNode(val:0);

        // 0
        // ListNode input_value_two = new ListNode(val:0);

        // Set three - longer first list + new carryover node required at the end
        // 9999999
        // ListNode input_value_one = new ListNode(val: 9);
        // input_value_one.next = new ListNode(val: 9);
        // input_value_one.next.next = new ListNode(val: 9);
        // input_value_one.next.next.next = new ListNode(val: 9);
        // input_value_one.next.next.next.next = new ListNode(val: 9);
        // input_value_one.next.next.next.next.next = new ListNode(val: 9);
        // input_value_one.next.next.next.next.next.next = new ListNode(val: 9);

        // 9999
        // ListNode input_value_two = new ListNode(val: 9);
        // input_value_two.next = new ListNode(val: 9);
        // input_value_two.next.next = new ListNode(val: 9);
        // input_value_two.next.next.next = new ListNode(val: 9);

        // Set four - longer second list
        // 249
        // ListNode input_value_one = new ListNode(val: 2);
        // input_value_one.next = new ListNode(val: 4);
        // input_value_one.next.next = new ListNode(val: 9);

        // 5649
        // ListNode input_value_two = new ListNode(val: 5);
        // input_value_two.next = new ListNode(val: 6);
        // input_value_two.next.next = new ListNode(val: 4);
        // input_value_two.next.next.next = new ListNode(val: 9);

        // Set five - zero value + longer second list
        // 0
        ListNode input_value_one = new ListNode(val:0);

        // 278
        ListNode input_value_two = new ListNode(val: 2);
        input_value_two.next = new ListNode(val: 7);
        input_value_two.next.next = new ListNode(val: 8);


        // Display the starting value.
        ListNode current_node = input_value_one;
        while (null != current_node)
        {
            Console.WriteLine("Input Value One: {0}", current_node.val.ToString());
            current_node = current_node.next;
        }
        current_node = input_value_two;
        while (null != current_node)
        {
            Console.WriteLine("Input Value Two: {0}", current_node.val.ToString());
            current_node = current_node.next;
        }

        // Perform the operation on the data.
        Solution mySolution = new Solution();
        current_node = mySolution.AddTwoNumbers(input_value_one, input_value_two);
        
        // Display the final value.
        while(null != current_node)
        {
            Console.WriteLine("Output Value: {0}", current_node.val.ToString());
            current_node = current_node.next;
        }
    }
}

public class Solution
{
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
    {
        return RecursiveNodeAddition(l1, l2, 0);
    }

    private ListNode RecursiveNodeAddition(ListNode FirstList, ListNode SecondList, int CarryValue)
    {
        // Overwrite the second list values in order to avoid having to allocate new memory.
        SecondList.val = FirstList.val + SecondList.val + CarryValue;

        // At most 9 + 9 will be added, so it is safe to say no more than 1 will every be carried over to the next position.
        if(SecondList.val >= 10)
        {
            SecondList.val %= 10;
            CarryValue = 1;
        }
        else
        {
            CarryValue = 0;
        }

        // If the lists both continue, go down the line adding them.
        if((null != FirstList.next) && (null != SecondList.next))
        {
            SecondList.next = RecursiveNodeAddition(FirstList.next, SecondList.next, CarryValue);
        }
        // At least one list has ended, but the other may continue if they are not the same length.
        else
        {
            ListNode finish_this_list = null;
            if (null != FirstList.next)
            {
                finish_this_list = FirstList;
            }
            else
            {
                finish_this_list = SecondList;
            }

            // Since the second list has been overwritten thus far to save memory allocation, create some extra trackers.
            // This is needed to avoid overwriting the nodes being operated on if the second list was the longer of the two.
            ListNode current_node = SecondList;
            ListNode next_node = null;
            while (null != finish_this_list.next)
            {
                next_node = finish_this_list.next;

                // if the second list was the longer of the two, keep overwriting it, otherwise allocate a new node
                if(null != current_node.next)
                {
                    current_node.next.val = finish_this_list.next.val + CarryValue;
                }
                else
                {
                    current_node.next = new ListNode(val: finish_this_list.next.val + CarryValue);
                }

                // Could be 9 + 1 so it may be necessary to carry a one.
                if (current_node.next.val >= 10)
                {
                    current_node.next.val %= 10;
                    CarryValue = 1;
                }
                else
                {
                    CarryValue = 0;
                }

                current_node = current_node.next;
                finish_this_list = next_node;
            }

            // If the longer list has been finished and a carry value remains, create a new node at the end to store that value.
            if(0 != CarryValue)
            {
                current_node.next = new ListNode(val: CarryValue);
            }
        }

        return SecondList;
    }
}
