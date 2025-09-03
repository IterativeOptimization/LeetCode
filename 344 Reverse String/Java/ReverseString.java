import java.util.Arrays;

class main {
    public static void main(String[] args) {
        // Various test cases.
        // char[] input_value = {};
        // char[] input_value = {'o'};
        // char[] input_value = {'h','e','l','l','o'};
        char[] input_value = {'H','a','n','n','a','h'};

        // Display the starting value.
        System.out.println("Input Value: " + Arrays.toString(input_value));

        // Perform the operation on the data.
        Solution mySolution = new Solution();
        mySolution.reverseString(input_value);

        // Display the final value.
        System.out.println("Output Value: " + Arrays.toString(input_value));
    }
}

class Solution {
    public void reverseString(char[] s) {
        // Temporary variable to hold the character being swapped.
        char swap_storage = '\0';

        // Store the number of swaps needed so the calculation does not need to be done every iteration.
        // This also accounts for odd length strings by dropping the remainder, zero length and length of one.
        int total_swaps_needed = s.length / 2;
        for (int i_each_letter = 0; i_each_letter < total_swaps_needed; ++i_each_letter)
        {
            // Store the char from the first half of the array.
            swap_storage = s[i_each_letter];

            // Overwrite the char from the first half of the array with one from the second half in place.
            s[i_each_letter] = s[s.length - i_each_letter - 1];

            // Overwrite the char from the second half with the stored char (what the first half used to be) in place.
            s[s.length - i_each_letter - 1] = swap_storage;
        }
    }
}
