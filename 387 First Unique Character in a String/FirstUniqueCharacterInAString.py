class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """

        # Make note of each letter found in the string and the number of occurrences.
        character_counts = {}
        for each_char in s:
            if each_char not in character_counts:
                character_counts[each_char] = 1
            else:    
                character_counts[each_char] += 1

        # Starting from the front of the string, report which letter is used only once, if any.
        iterations = 0
        for each_char in s:
            if character_counts[each_char] == 1:
                return iterations
            iterations += 1

        # If no letter occurred a single time, return special value.
        return -1


# Various test cases.
# 0
# input_value = "leetcode"

# 2
# input_value = "loveleetcode"

# -1
input_value = "aabb"

# Display the starting value.
print("Input Value: ", input_value)

# Perform the operation on the data.
mySolution = Solution()
output_value = mySolution.firstUniqChar(s=input_value)

# Display the final value.
print("Output Value: ", output_value)
