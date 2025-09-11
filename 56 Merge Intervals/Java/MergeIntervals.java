import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;

class main {
    public static void main(String[] args)
    {
        // Various test cases.
        // int[][] input_value = { {1,3}, {2,6}, {8,10}, {15,18}};
        // int[][] input_value = { {1,4}, {4,5}};
        // int[][] input_value = { {1,4}, {1,4}};
        int[][] input_value = { {4,7}, {3,5}, {6,10}, {12, 15}};
        // int[][] input_value = { {3,10}, {4,7}};
        // int[][] input_value = { {1,4}, {0,5}};  // impose a larger range onto a smaller one
        // int[][] input_value = { {2,3}, {4,5}, {8,9}, {6,7}, {1,10}};  // sequentially larger
        // int[][] input_value = { {2,5}, {7,10}, {4,8}};  // span the gap

        // Display the starting value.
        System.out.println("Input Value: " + Arrays.deepToString(input_value));

        // Perform the operation on the data.
        Solution mySolution = new Solution();
        int[][] output_value = mySolution.merge(input_value);
        
        // Display the final value.
        System.out.println("Output Value: " + Arrays.deepToString(output_value));
    }
}

class Solution
{
    // Comparator with compare method for the purpose of sorting the array of arrays.
    class IntArrayComparator implements Comparator<int[]> {
        @Override
        public int compare(int[] x, int[] y)
        {
            return Integer.compare(x[0], y[0]);
        }
    }

    public int[][] merge(int[][] intervals)
    {
        // Sort the array of arrays using a comparison object in ascending order.
        // This puts the lowest interval (smallest first number) at the start.
        Arrays.sort(intervals, new IntArrayComparator());

        // Container object to store the ongoing result during the merging process.
        ArrayList<int[]> answer_array_list = new ArrayList<int[]>();
        answer_array_list.add(intervals[0]);

        int[] next_sorted_interval;
        // Go through each interval within the provided array.
        for (int i_each_range = 0; i_each_range < intervals.length; ++i_each_range)
        {
            // Compare each successive interval against the last interval in the result container.
            next_sorted_interval = answer_array_list.get(answer_array_list.size() - 1);

            // Due to the sorting order of the array, the intervals will be the same or increasing in size (value),
            // Thus, it is only necessary to merge from the right side of the answer interval (higher number of the two in a given interval).
            // If lowest number of the new interval (6,10) is LESS than or EQUAL to the highest number of an existing interval (4,7)...
            if (intervals[i_each_range][0] <= next_sorted_interval[1])
            {
                // ...but GREATER than or EQUAL to the lowest number of that same interval...
                if (intervals[i_each_range][0] >= next_sorted_interval[0])
                {
                    // ...there IS an overlap, but is the new interval extent larger than the existing one?
                    if (intervals[i_each_range][1] > next_sorted_interval[1])
                    {
                        // Yes, the new interval extends the current answer interval to the right ([4,7] + [6,10] -> [4,10])
                        next_sorted_interval[1] = intervals[i_each_range][1];
                        continue;
                    } else { 
                        // No, the new interval fits inside the existing answer interval, no need to add it.
                        continue;
                    }
                }
            }

            // If the new interval does not overlap the last answer interval, add it to the list.
            answer_array_list.add(intervals[i_each_range]);
        }

        // Convert the arraylist into a standard fixed size array in order to return the expected output.
        int answer_size = answer_array_list.size();
        int[][] final_answer = new int[answer_size][];
        for (int i_each_range = 0; i_each_range < answer_size; ++i_each_range)
        {
            final_answer[i_each_range] = answer_array_list.get(i_each_range);
        }

        return final_answer;
    }
}
