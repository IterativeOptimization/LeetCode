#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        // Sort the vector to put the lowest interval (smallest first number) at the start.
        sort(intervals.begin(), intervals.end());

        // Container object to store the ongoing result during the merging process.
        vector<vector<int>> answer_vector;
        answer_vector.push_back(intervals[0]);

        vector<int>* current_range;
        vector<int>* next_sorted_interval;
        // Go through each interval within the provided vector.
        for (int i_each_range = 1; i_each_range < intervals.size(); ++i_each_range)
        {
            // Compare each successive interval against the last interval in the result container.
            current_range = &intervals[i_each_range];
            next_sorted_interval = &answer_vector[answer_vector.size() - 1];

            // Due to the sorting order of the vector, the intervals will be the same or increasing in size (value),
            // Thus, it is only necessary to merge from the right side of the answer interval (higher number of the two in a given interval).
            // If lowest number of the new interval (6,10) is LESS than or EQUAL to the highest number of an existing interval (4,7)...
            if ((*current_range)[0] <= (*next_sorted_interval)[1])
            {
                // ...but GREATER than or EQUAL to the lowest number of that same interval...
                if ((*current_range)[0] >= (*next_sorted_interval)[0])
                {
                    // ...there IS an overlap, but is the new interval extent larger than the existing one?
                    if ((*current_range)[1] > (*next_sorted_interval)[1])
                    {
                        // Yes, the new interval extends the current answer interval to the right ([4,7] + [6,10] -> [4,10])
                        (*next_sorted_interval)[1] = (*current_range)[1];
                        continue;
                    } else {
                        // No, the new interval fits inside the existing answer interval, no need to add it.
                        continue;
                    }
                }
            }

            // If the new interval does not overlap the last answer interval, add it to the list.
            answer_vector.push_back(intervals[i_each_range]);
        }

        return answer_vector;   
    }
};

int main()
{
    // Various test cases.
    vector<vector<int>> input_value = {{1,3}, {2,6}, {8,10}, {15,18}};
    // vector<vector<int>> input_value = {{1,4}, {4,5}};
    // vector<vector<int>> input_value = {{1,4}, {1,4}};
    // vector<vector<int>> input_value = {{4,7}, {3,5}, {6,10}, {12,15}};
    // vector<vector<int>> input_value = {{3,10}, {4,7}};
    // vector<vector<int>> input_value = {{1,4}, {0,5}}; // impose a larger range onto a smaller one
    // vector<vector<int>> input_value = {{2,3}, {4,5}, {8,9}, {6,7}, {1,10}}; // sequentially larger
    // vector<vector<int>> input_value = {{2,5}, {7,10}, {4,8}}; // span the gap

    // Display the starting value.
    cout << "Given input: ";
    for (vector<int> each_int_vector : input_value)
    {
        cout << "[" << each_int_vector[0] << ", " << each_int_vector[1] << "] ";
    }
    cout << endl;

    // Perform the operation on the data.
    Solution mySolution = Solution();
    vector<vector<int>> output_value = mySolution.merge(input_value);

    // Display the final value.
    cout << "Received output: ";
    for (vector<int> each_int_vector : output_value)
    {
        cout << "[" << each_int_vector[0] << ", " << each_int_vector[1] << "] ";
    }
    cout << endl;
}
