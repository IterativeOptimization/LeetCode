# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        return self.RecursiveNodeAddition(l1, l2, 0)


    def RecursiveNodeAddition(self, FirstList, SecondList, CarryValue):
        # Overwrite the second list values in order to avoid having to allocate new memory.
        SecondList.val = FirstList.val + SecondList.val + CarryValue

        # At most 9 + 9 will be added, so it is safe to say no more than 1 will every be carried over to the next position.
        if(SecondList.val >= 10):
            SecondList.val %= 10
            CarryValue = 1
        else:
            CarryValue = 0

        # If the lists both continue, go down the line adding them.
        if((None != FirstList.next) and (None != SecondList.next)):
            SecondList.next = self.RecursiveNodeAddition(FirstList.next, SecondList.next, CarryValue)
        # At least one list has ended, but the other may continue if they are not the same length.
        else:
            finish_this_list = None
            if (None != FirstList.next):
                finish_this_list = FirstList
            else:
                finish_this_list = SecondList

            # Since the second list has been overwritten thus far to save memory allocation, create some extra trackers.
            # This is needed to avoid overwriting the nodes being operated on if the second list was the longer of the two.
            current_node = SecondList
            next_node = None
            while (None != finish_this_list.next):
                next_node = finish_this_list.next

                # if the second list was the longer of the two, keep overwriting it, otherwise allocate a new node
                if(None != current_node.next):
                    current_node.next.val = finish_this_list.next.val + CarryValue
                else:
                    current_node.next = ListNode(val=finish_this_list.next.val + CarryValue)

                # Could be 9 + 1 so it may be necessary to carry a one.
                if (current_node.next.val >= 10):
                    current_node.next.val %= 10
                    CarryValue = 1
                else:
                    CarryValue = 0

                current_node = current_node.next
                finish_this_list = next_node

            # If the longer list has been finished and a carry value remains, create a new node at the end to store that value.
            if(0 != CarryValue):
                current_node.next = ListNode(val=CarryValue)

        return SecondList


# Various test cases.
# Set one - same length lists + carryover
# 243
# input_value_one = ListNode(val= 2)
# input_value_one.next = ListNode(val= 4)
# input_value_one.next.next = ListNode(val= 3)

# 564
# input_value_two = ListNode(val= 5)
# input_value_two.next = ListNode(val= 6)
# input_value_two.next.next = ListNode(val= 4)

# Set two - both zero values + one node length lists
# 0
# input_value_one = ListNode(val=0)

# 0
# input_value_two = ListNode(val=0)

# Set three - longer first list + carryover node required at the end
# 9999999
input_value_one = ListNode(val= 9)
input_value_one.next = ListNode(val= 9)
input_value_one.next.next = ListNode(val= 9)
input_value_one.next.next.next = ListNode(val= 9)
input_value_one.next.next.next.next = ListNode(val= 9)
input_value_one.next.next.next.next.next = ListNode(val= 9)
input_value_one.next.next.next.next.next.next = ListNode(val= 9)

# 9999
input_value_two = ListNode(val= 9)
input_value_two.next = ListNode(val= 9)
input_value_two.next.next = ListNode(val= 9)
input_value_two.next.next.next = ListNode(val= 9)

# Set four - longer second list
# 249
# input_value_one = ListNode(val= 2)
# input_value_one.next = ListNode(val= 4)
# input_value_one.next.next = ListNode(val= 9)

# 5649
# input_value_two = ListNode(val= 5)
# input_value_two.next = ListNode(val= 6)
# input_value_two.next.next = ListNode(val= 4)
# input_value_two.next.next.next = ListNode(val= 9)

# Set five - zero value + longer second list
# 0
# input_value_one = ListNode(val=0)

# 278
# input_value_two = ListNode(val= 2)
# input_value_two.next = ListNode(val= 7)
# input_value_two.next.next = ListNode(val= 8)

# Display the starting value.
current_node = input_value_one
print("Input Value One: ")
while (None != current_node):
    print(current_node.val, " ")
    current_node = current_node.next

current_node = input_value_two
print("Input Value two: ")
while (None != current_node):
    print(current_node.val, " ")
    current_node = current_node.next

# Perform the operation on the data.
mySolution = Solution()
current_node = mySolution.addTwoNumbers(l1=input_value_one, l2=input_value_two)

# Display the final value.
print("Output Value: ")
while (None != current_node):
    print(current_node.val, " ")
    current_node = current_node.next
