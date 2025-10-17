from collections import deque

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        open_parenthesis_deque = deque()
        just_popped_char = ""

        for each_char in s:
            # start a new open
            if (each_char == '(' or each_char == '[' or each_char == '{'):
                open_parenthesis_deque.append(each_char)
            else:
                # nothing on the stack to close, not enough openings
                if (not open_parenthesis_deque):
                    return False

                just_popped_char = open_parenthesis_deque.pop()

                # does the close match the last open?
                if (each_char == ')'):
                    if (just_popped_char != '('):
                        return False
                elif (each_char == ']'):
                    if (just_popped_char != '['):
                        return False
                else:
                    if (just_popped_char != '{'):
                        return False

        # still something on the stack, not enough closings
        if (open_parenthesis_deque):
            return False

        return True


# Various test cases.
# input_value = "()"
# input_value = "()[]{}"
input_value = "(]"
# input_value = "([])"
# input_value = "([)]"
# input_value = "["
# input_value = "]"

# Display the starting value.
print("Input Value: ", input_value)

# Perform the operation on the data.
mySolution = Solution()
output_value = mySolution.isValid(input_value)

# Display the final value.
print("Output Value: ", output_value)
