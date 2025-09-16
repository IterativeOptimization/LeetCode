# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def sortList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if (None == head):
            return head

        current_node = head
        nodes_as_list = []

        # Load the values into a sortable structure.
        while (None != current_node):
            nodes_as_list.append(current_node)
            current_node = current_node.next

        # Sort in ascending order.
        nodes_as_list.sort(key=lambda each_item: each_item.val)

        # Note the new head of the list in order to return it later.
        current_node = head = nodes_as_list[0]

        # Relink the singly linked list nodes in sorted order.
        for i_each_node in nodes_as_list[1:]:
            current_node.next = i_each_node
            current_node = current_node.next

        # Designate the new end of the list to avoid a potential circularly linked list.
        current_node.next = None

        return head


# Various test cases.
input_value = ListNode(val=4)
input_value.next = ListNode(val=2)
input_value.next.next = ListNode(val=1)
input_value.next.next.next = ListNode(val=3)

# input_value = ListNode(val=-1)
# input_value.next = ListNode(val=5)
# input_value.next.next = ListNode(val=3)
# input_value.next.next.next = ListNode(val=4)
# input_value.next.next.next.next = ListNode(val=0)

# Display the starting value.
current_node = input_value
print("Input Value: ")
while (None != current_node):
    print(current_node.val, " ")
    current_node = current_node.next

# Perform the operation on the data.
mySolution = Solution()
current_node = mySolution.sortList(head=input_value)

# Display the final value.
print("Output Value: ")
while (None != current_node):
    print(current_node.val, " ")
    current_node = current_node.next
