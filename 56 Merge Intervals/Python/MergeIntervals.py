class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        # Sort the array of arrays using a comparison object in ascending order.
        # This puts the lowest interval (smallest first number) at the start.
        intervals.sort()

        # Container object to store the ongoing result during the merging process.
        final_answer = []
        final_answer.append(intervals[0])

        next_sorted_interval = []
        intervals_length = len(intervals)
        #  Go through each interval within the provided array.
        for i_each_range in range(intervals_length):
            # Compare each successive interval against the last interval in the result container.
            next_sorted_interval = final_answer[len(final_answer) - 1]

            # Due to the sorting order of the array, the intervals will be the same or increasing in size (value),
            # Thus, it is only necessary to merge from the right side of the answer interval (higher number of the two in a given interval).
            # If lowest number of the new interval (6,10) is LESS than or EQUAL to the highest number of an existing interval (4,7)...
            if (intervals[i_each_range][0] <= next_sorted_interval[1]):
                # ...but GREATER than or EQUAL to the lowest number of that same interval...
                if (intervals[i_each_range][0] >= next_sorted_interval[0]):
                    # ...there IS an overlap, but is the new interval extent larger than the existing one?
                    if (intervals[i_each_range][1] > next_sorted_interval[1]):
                        # Yes, the new interval extends the current answer interval to the right ([4,7] + [6,10] -> [4,10])
                        next_sorted_interval[1] = intervals[i_each_range][1]
                        continue
                    else:
                        # No, the new interval fits inside the existing answer interval, no need to add it.
                        continue

            #  If the new interval does not overlap the last answer interval, add it to the list.
            final_answer.append(intervals[i_each_range])

        return final_answer


# Various test cases.
#input_value = [[1,3], [2,6], [8,10], [15,18]]
#input_value = [[1,4], [4,5]]
#input_value = [[1,4], [1,4]]
input_value = [[4,7], [3,5], [6,10], [12, 15]]
#input_value = [[3,10], [4,7]]
#input_value = [[1,4], [0,5]]  # impose a larger range onto a smaller one
#input_value = [[2,3], [4,5], [8,9], [6,7], [1,10]]  # sequentially larger
#input_value = [[2,5], [7,10], [4,8]]  # span the gap

# Display the starting value.
print("Input Value: ", input_value)

# Perform the operation on the data.
mySolution = Solution()
output_value = mySolution.merge(intervals=input_value)

# Display the final value.
print("Output Value: ", output_value)
