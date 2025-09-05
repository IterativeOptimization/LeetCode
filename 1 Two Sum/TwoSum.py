from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        list_as_dictionary = {}
        search_target = 0

        # Go through each entry of the original input List.  We are guaranteed that there is a solution somewhere in here.
        for i_each_list_position in range(len(nums)):
            # Subtract each number of the input from the target value.  This yields the number that we are looking for.
            search_target = target - nums[i_each_list_position]

            # Check if the number we are looking for is already in the dictionary of values.
            if (search_target in list_as_dictionary):
                # If it is, we are done!  Return the current number from the input List and the previous number stored in the dictionary.
                return [list_as_dictionary.get(search_target), i_each_list_position]

            # If the number is not already in the dictionary, go ahead and store it.
            # It is okay to overwrite anything stored at this position because we are only going to need one value for the solution.
            # This means if there are three or more copies of this number in the input, the value may be overwritten several times,
            # but this is okay because we know this number will not be involved in the solution as the solution only uses two numbers.
            list_as_dictionary[nums[i_each_list_position]] = i_each_list_position

        # We should never reach this point as a solution is guaranteed, but it keeps the complier from being unhappy.
        return []


# Various test cases.
input_value = [2,7,11,15]
#input_value = [3,2,4]
#input_value = [3,3]
#input_value = [-1,111,53,2,-3,4,5]

target = 9
#target = 6
#target = 1

# Display the starting value.
print("Input Value: {val}", input_value)
print("Target Value: {val}", target)

# Perform the operation on the data.
mySolution = Solution()
output_value = mySolution.twoSum(nums=input_value, target=target)

# Display the final value.
print("Output Value: {val}", output_value)
