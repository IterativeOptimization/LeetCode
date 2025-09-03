#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        // Already using an STL vector rather than a simple array, may as well leverage STL reverse.
        reverse(s.begin(), s.end());
    }
};

int main()
{
    // Various test cases.
    // vector<char> input_value = {};
    // vector<char> input_value = {'o'};
    // vector<char> input_value = {'h', 'e', 'l', 'l', 'o'};
    vector<char> input_value = {'H', 'a', 'n', 'n', 'a', 'h'};

    // Display the starting value.
    string display_input_string(input_value.begin(), input_value.end());
    cout << "Given input: " << display_input_string << endl;

    // Perform the operation on the data.
    Solution* mySolution = new Solution();
    mySolution->reverseString(input_value);

    // Display the final value.
    string display_output_string(input_value.begin(), input_value.end());
    cout << "Received output: " << display_output_string << endl;
}
