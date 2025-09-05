import java.util.Arrays;
import java.util.HashMap;

class main {
    public static void main(String[] args) {
        // Various test cases.
        int[] input_value = { 2, 7, 11, 15 };
        // int[] input_value = { 3, 2, 4 };
        // int[] input_value = { 3, 3 };
        // int[] input_value = { -1, 111, 53, 2, -3, 4, 5 };

        int target = 9;
        // int target = 6;
        // int target = 1;

        // Display the starting value.
        System.out.println("Input Value: " + Arrays.toString(input_value));
        System.out.println("Target Value: " + target);

        // Perform the operation on the data.
        Solution mySolution = new Solution();
        int[] output_value = mySolution.twoSum(input_value, target);

        // Display the final value.
        System.out.println("Output Value: " + Arrays.toString(output_value));
    }
}

class Solution {
    public int[] twoSum(int[] nums, int target)
    {
        HashMap<Integer, Integer> array_as_hashmap = new HashMap<Integer, Integer>();
        int search_target;

        // Go through each entry of the original input array.  We are guaranteed that there is a solution somewhere in here.
        for (int i_each_array_position = 0; i_each_array_position < nums.length; ++i_each_array_position)
        {
            // Subtract each number of the input from the target value.  This yields the number that we are looking for.
            search_target = target - nums[i_each_array_position];

            // Check if the number we are looking for is already in the hashmap of values.
            if (array_as_hashmap.containsKey(search_target)) {

                // If it is, we are done!  Return the current number from the input array and the previous number stored in the hashmap.
                return new int[] { array_as_hashmap.get(search_target), i_each_array_position };
            }

            // If the number is not already in the hashmap, go ahead and store it.
            // It is okay to overwrite anything stored at this position because we are only going to need one value for the solution.
            // This means if there are three or more copies of this number in the input, the value may be overwritten several times,
            // but this is okay because we know this number will not be involved in the solution as the solution only uses two numbers.
            array_as_hashmap.put(nums[i_each_array_position], i_each_array_position);
        }

        // We should never reach this point as a solution is guaranteed, but it keeps the complier from being unhappy.
        return null;
    }
}
