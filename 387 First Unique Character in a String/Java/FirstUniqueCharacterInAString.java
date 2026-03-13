import java.util.Arrays;

class main {
    public static void main(String[] args) {
        // Various test cases.
        // 0
        // String input_value = "leetcode";

        // 2
        String input_value = "loveleetcode";

        // -1
        // String input_value = "aabb";

        // Display the starting value.
        System.out.printf("Input Value: %s\n", input_value);

        // Perform the operation on the data.
        Solution mySolution = new Solution();
        int output_value = mySolution.firstUniqChar(input_value);

        // Display the final value.
        System.out.printf("Output Value: %s\n", output_value);
    }
}

class Solution
{
    public int firstUniqChar(String s)
    {
        // Make note of each letter found in the string and the number of occurrences.
        int[] character_counts = new int[26];
        int value_of_a = 'a';
        char[] s_as_char_array = s.toCharArray();
        for (char each_char : s_as_char_array)
        {
            character_counts[(each_char - value_of_a)] += 1;
        }

        // Starting from the front of the string, report which letter is used only once, if any.
        int iterations = 0;
        for(char each_char : s_as_char_array)
        {
            if(character_counts[(each_char - value_of_a)] == 1)
            {
                return iterations;
            }
            iterations++;
        }

        // If no letter occurred a single time, return special value.
        return -1;
    }
}
