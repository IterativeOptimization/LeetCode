#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, int> sorted_letters_and_anagrams;
        string sorted_input_string;
        vector<string> original_words_vector;
        pair<map<string, int>::iterator, bool> result_of_insert;
        int anagram_group_count_answer_index = 0;
        
        vector<vector<string>> answer;
        for (string each_input_string : strs)
        {
            // Sort each of the words by letter value in ascending order (ex. "abcabc" -> "aabbcc")
            sorted_input_string = each_input_string;
            sort(sorted_input_string.begin(), sorted_input_string.end());

            // If a word with these letters has not been seen before, create a new place for it in the hashtable.
            // If multiple input words have the same letter grouping after the sort operation, they are anagrams as they contain the same letters.
            result_of_insert = sorted_letters_and_anagrams.insert(make_pair(sorted_input_string, anagram_group_count_answer_index));

            // If the insert occurred, this was a new entry and as such the result container needs to be updated to contain the anagrams.
            if(result_of_insert.second)
            {
                // Track the results for each letter grouping in a separate container conforming to the expected return type.
                answer.push_back(original_words_vector);
                anagram_group_count_answer_index++;
            }

            // Store the original word as the value in the result position corresponding to the sorted letter grouping.
            answer[result_of_insert.first->second].push_back(each_input_string);
        }

        return answer;
    }
};

int main()
{
    // Various test cases.
    vector<string> input_value = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // string[] input_value = {""};
    // string[] input_value = {"a"};
    // string[] input_value = {"a", "a"};

    // Display the starting value.
    cout << "Input Value: " << endl;
    for (string each_string : input_value)
    {
        cout << each_string << " ";
    }
    cout << endl;

    // Perform the operation on the data.
    Solution mySolution = Solution();
    vector<vector<string>> output_value = mySolution.groupAnagrams(input_value);

    // Display the final value.
    cout << "Output Value: " << endl;
    for (vector<string> each_string_vector : output_value)
    {
        for (string each_string : each_string_vector)
        {
            cout << each_string << " ";
        }
        cout << endl;
    }
    cout << endl;
}
