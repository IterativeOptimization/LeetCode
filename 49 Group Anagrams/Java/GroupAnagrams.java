import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

class main {
    public static void main(String[] args) {
        // Various test cases.
        String[] input_value = {"eat","tea","tan","ate","nat","bat"};
        // String[] input_value = {""};
        // String[] input_value = {"a"};
        // String[] input_value = {"a", "a"};

        // Display the starting value.
        System.out.printf("Input Value: %s\n", Arrays.toString(input_value));

        // Perform the operation on the data.
        Solution mySolution = new Solution();
        List<List<String>> output_value = mySolution.groupAnagrams(input_value);

        // Display the final value.
        System.out.printf("Output Value:\n");
        for(List<String> each_anagram_group : output_value)
        {
            for(String each_anagram : each_anagram_group)
            {
                System.out.printf("%s ", each_anagram);
            }
            System.out.print(System.lineSeparator());
        }
    }
}

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, Integer> sorted_letters_and_anagrams = new HashMap<String, Integer>();
        List<List<String>> answer = new ArrayList<List<String>>();
        char[] sorted_input_array;
        String sorted_string;
        int anagram_group_count = 0;
        Integer index_into_answer = 0;

        for(String each_input_string : strs)
        {
            // Sort each of the words by letter value in ascending order (ex. "abcabc" -> "aabbcc")
            sorted_input_array = each_input_string.toCharArray();
            Arrays.sort(sorted_input_array);
            sorted_string = new String(sorted_input_array);

            index_into_answer = sorted_letters_and_anagrams.get(sorted_string);

            // If a word with these letters has not been seen before, create a new place for it in the hashtable.
            // If multiple input words have the same letter grouping after the sort operation, they are anagrams as they contain the same letters.
            if(index_into_answer == null)
            {
                sorted_letters_and_anagrams.put(sorted_string, anagram_group_count);
                index_into_answer = anagram_group_count;
                anagram_group_count++;
                // Track the results for each letter grouping in a separate list conforming to the expected return type.
                answer.add(new LinkedList<String>());
            }

            // Store the original word as the value for the hashtable position corresponding to the sorted letter grouping.
            answer.get(index_into_answer).add(each_input_string);
        }

        return answer; 
    }
}
