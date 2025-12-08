class main
{
    static public void Main(String[] args)
    {
        // Various test cases.
        string[] input_value = {"eat","tea","tan","ate","nat","bat"};
        // string[] input_value = {""};
        // string[] input_value = {"a"};
        // string[] input_value = {"a", "a"};

        // Display the starting value.
        Console.WriteLine("Input Value: {0}", input_value.ToString());

        // Perform the operation on the data.
        Solution mySolution = new Solution();
        IList<IList<string>> output_value = mySolution.GroupAnagrams(input_value);

        // Display the final value.
        Console.WriteLine("Output Value: ");
        foreach(IList<string> each_anagram_group in output_value)
        {
            foreach(string each_anagram in each_anagram_group)
            {
                Console.Write(string.Format($"{each_anagram} "));
            }
            Console.WriteLine();
        }
    }
}

public class Solution
{
    public IList<IList<string>> GroupAnagrams(string[] strs)
    {
        Dictionary<string, List<string>> sorted_letters_and_anagrams = new Dictionary<string, List<string>>();
        IList<IList<string>> answer = new List<IList<string>>();
        char[] sorted_input_array;
        string sorted_string;
        int input_array_length = strs.Length;

        for(int i_each_input_string = 0; i_each_input_string < input_array_length; i_each_input_string++)
        {
            // Sort each of the words by letter value in ascending order (ex. "abcabc" -> "aabbcc")
            sorted_input_array = strs[i_each_input_string].ToCharArray();
            Array.Sort(sorted_input_array);
            sorted_string = new string(sorted_input_array);

            // If a word with these letters has not been seen before, create a new place for it in the hashtable.
            if(sorted_letters_and_anagrams.ContainsKey(sorted_string) == false)
            {
                sorted_letters_and_anagrams.Add(sorted_string, new List<string>());
                // Track the results for each letter grouping in a separate list conforming to the expected return type.
                // This prevents having to iterate through the results a second time to convert to the expected output format.
                answer.Add(sorted_letters_and_anagrams[sorted_string]);
            }

            // Store the original word as the value for the hashtable position corresponding to the sorted letter grouping.
            // If multiple input words have the same letter grouping after the sort operation, they are anagrams as they contain the same letters.
            sorted_letters_and_anagrams[sorted_string].Add(strs[i_each_input_string]);
        }

        return answer;
    }
}
