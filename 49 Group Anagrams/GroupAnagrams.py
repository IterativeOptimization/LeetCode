class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        sorted_letters_and_anagrams = {}
        answer = []
        sorted_string = ""

        for each_input_string in strs:
            # Sort each of the words by letter value in ascending order (ex. "abcabc" -> "aabbcc")
            sorted_string = ''.join(sorted(each_input_string))

            # If a word with these letters has not been seen before, create a new place for it in the hashtable.
            # If multiple input words have the same letter grouping after the sort operation, they are anagrams as they contain the same letters.
            if sorted_string not in sorted_letters_and_anagrams:
                sorted_letters_and_anagrams[sorted_string] = []
                # Track the results for each letter grouping in a separate list conforming to the expected return type.
                # This prevents having to iterate through the results a second time to convert to the expected output format.
                answer.append(sorted_letters_and_anagrams[sorted_string])

            # Store the original word as the value for the hashtable position corresponding to the sorted letter grouping.
            sorted_letters_and_anagrams[sorted_string].append(each_input_string)

        return answer


# Various test cases.
input_value = {"eat","tea","tan","ate","nat","bat"};
# input_value = {""};
# input_value = {"a"};
# input_value = {"a", "a"};

# Display the starting value.
print("Input Value: ", input_value)

# Perform the operation on the data.
mySolution = Solution()
output_value = mySolution.groupAnagrams(strs=input_value)

# Display the final value.
print("Output Value: ")
for each_anagram_group in output_value:
    print(each_anagram_group)
