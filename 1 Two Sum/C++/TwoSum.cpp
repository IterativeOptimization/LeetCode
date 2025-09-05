#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> array_as_map;
        int search_target;
        vector<int> answer_vector;

        // Go through each entry of the original input vector.  We are guaranteed that there is a solution somewhere in here.
        for (int i_each_vector_position = 0; i_each_vector_position < nums.size(); ++i_each_vector_position)
        {
            // Subtract each number of the input from the target value.  This yields the number that we are looking for.
            search_target = target - nums[i_each_vector_position];

            // Check if the number we are looking for is already in the map of values.
            if (array_as_map.count(search_target))
            {
                // If it is, we are done!  Return the current number from the input vector and the previous number stored in the map.
                answer_vector = {array_as_map[search_target], i_each_vector_position};
                return answer_vector;
            }

            // If the number is not already in the map, go ahead and store it.
            // It is okay to overwrite anything stored at this position because we are only going to need one value for the solution.
            // This means if there are three or more copies of this number in the input, the value may be overwritten several times,
            // but this is okay because we know this number will not be involved in the solution as the solution only uses two numbers.
            array_as_map[nums[i_each_vector_position]] = i_each_vector_position;
        }

        // We should never reach this point as a solution is guaranteed, but it keeps the complier from being unhappy.
        return answer_vector;
    }
};

int main()
{
    // Various test cases.
    vector<int> input_value = {2, 7, 11, 15};
    // vector<int> input_value = {3, 2, 4};
    // vector<int> input_value = {3, 3};
    // vector<int> input_value = {-1, 111, 53, 2, -3, 4, 5};

    int target = 9;
    // int target = 6;
    // int target = 1;

    // Display the starting value.
    string display_input_string(input_value.begin(), input_value.end());
    cout << "Given input: ";
    for (int each_int : input_value)
    {
        cout << each_int << " ";
    }
    cout << endl;

    cout << "Given target: " << target << endl;

    // Perform the operation on the data.
    Solution *mySolution = new Solution();
    vector<int> output_value = mySolution->twoSum(input_value, target);

    // Display the final value.
    string display_output_string(output_value.begin(), output_value.end());
    cout << "Received output: ";
    for (int each_int : output_value)
    {
        cout << each_int << " ";
    }
    cout << endl;
}
