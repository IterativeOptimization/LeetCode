using System.Collections.Generic;

class main
{
    static public void Main(String[] args)
    {
        // Various test cases.
        int[] input_value = { 2, 7, 11, 15 };
        // int[] input_value = { 3, 2, 4 };
        // int[] input_value = { 3, 3 };
        // int[] input_value = { -1, 111, 53, 2, -3, 4, 5 };

        int target = 9;
        // int target = 6;
        // int target = 1;

        // Display the starting value.
        Console.WriteLine("Input Value: {0}", string.Join(",", input_value));
        Console.WriteLine("Target Value: {0}", target);

        // Perform the operation on the data.
        Solution mySolution = new Solution();
        int[] output_value = mySolution.TwoSum(input_value, target);

        // Display the final value.
        Console.WriteLine("Output Value: {0}", string.Join(",", output_value));
    }
}

public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        Dictionary<int, int> array_as_dictionary = new Dictionary<int, int>();
        int search_target;

        // Go through each entry of the original input array.  We are guaranteed that there is a solution somewhere in here.
        for (int i_each_array_position = 0; i_each_array_position < nums.Length; ++i_each_array_position)
        {
            // Subtract each number of the input from the target value.  This yields the number that we are looking for.
            search_target = target - nums[i_each_array_position];

            // Check if the number we are looking for is already in the dictionary of values.
            if (array_as_dictionary.ContainsKey(search_target))
            {
                // If it is, we are done!  Return the current number from the input array and the previous number stored in the dictionary.
                return new int[] { array_as_dictionary[search_target], i_each_array_position };
            }

            // If the number is not already in the dictionary, go ahead and store it.
            // It is okay to overwrite anything stored at this position because we are only going to need one value for the solution.
            // This means if there are three or more copies of this number in the input, the value may be overwritten several times,
            // but this is okay because we know this number will not be involved in the solution as the solution only uses two numbers.
            array_as_dictionary[nums[i_each_array_position]] = i_each_array_position;
        }

        // We should never reach this point as a solution is guaranteed, but it keeps the complier from being unhappy.
        return null;
    }
}
