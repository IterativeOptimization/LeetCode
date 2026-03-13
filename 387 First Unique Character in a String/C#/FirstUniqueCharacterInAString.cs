class main
{
    static public void Main(String[] args)
    {
        // Various test cases.
        // 0
        // string input_value = "leetcode";

        // 2
        string input_value = "loveleetcode";

        // -1
        // string input_value = "aabb";

        // Display the starting value.
        Console.WriteLine("Input Value: {0}", input_value);

        // Perform the operation on the data.
        Solution mySolution = new Solution();
        int output_value = mySolution.FirstUniqChar(input_value);

        // Display the final value.
        Console.WriteLine("Output Value: {0}", output_value);
    }
}

public class Solution
{
    public int FirstUniqChar(string s)
    {
        // Make note of each letter found in the string and the number of occurrences.
        int[] character_counts = new int[26];
        int value_of_a = 'a';
        foreach (char each_char in s)
        {
            character_counts[(each_char - value_of_a)] += 1;
        }

        // Starting from the front of the string, report which letter is used only once, if any.
        int iterations = 0;
        foreach (char each_char in s)
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
