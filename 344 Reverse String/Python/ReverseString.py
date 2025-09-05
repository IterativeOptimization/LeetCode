from typing import List

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        # A List is provided rather than an array, may as well leverage the built in functionality.
        s.reverse()

# Various test cases.
#input_value = []
#input_value = ['o']
#input_value = ['h','e','l','l','o']
input_value = ['H','a','n','n','a','h']

# Display the starting value.
print("Input Value: {val}", input_value)

# Perform the operation on the data.
mySolution = Solution()
mySolution.reverseString(s=input_value)

# Display the final value.
print("Output Value: {val}", input_value)
