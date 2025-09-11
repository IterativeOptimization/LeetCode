class main
{
    static public void Main(String[] args)
    {
        // Various test cases.
        // int[][] input_value = { new []{1,3}, new []{2,6}, new []{8,10}, new []{15,18}};
        // int[][] input_value = { new []{1,4}, new []{4,5}};
        // int[][] input_value = { new []{1,4}, new []{1,4}};
        int[][] input_value = { new []{4,7}, new []{3,5}, new []{6,10}, new []{12, 15}};
        // int[][] input_value = { new []{3,10}, new []{4,7}};
        // int[][] input_value = { new []{1,4}, new []{0,5}};  // impose a larger range onto a smaller one
        // int[][] input_value = { new []{2,3}, new []{4,5}, new []{8,9}, new []{6,7}, new []{1,10}};  // sequentially larger
        // int[][] input_value = { new []{2,5}, new []{7,10}, new []{4,8}};  // span the gap

        // Display the starting value.
        Console.WriteLine("Input Value:");
        foreach(int[] i_each_int_array in input_value)
        {
            Console.WriteLine("[{0}]", String.Join(", ", i_each_int_array));
        }

        // Perform the operation on the data.
        Solution mySolution = new Solution();
        int[][] output_value = mySolution.Merge(input_value);

        // Display the final value.
        Console.WriteLine("Output Value:");
        foreach(int[] i_each_int_array in output_value)
        {
            Console.WriteLine("[{0}]", String.Join(", ", i_each_int_array));
        }
    }
}

public class Solution {
    // Comparison method for the purpose of sorting the array of arrays.
    static int CompareFirstIndex(int[] a, int[] b)
    {
        return a[0].CompareTo(b[0]);
    }

    public int[][] Merge(int[][] intervals)
    {
        // Sort the array of arrays using a comparison object in ascending order.
        // This puts the lowest interval (smallest first number) at the start.
        Comparison<int[]> comparison = new Comparison<int[]>(CompareFirstIndex);
        Array.Sort(intervals, comparison);

        // Container object to store the ongoing result during the merging process.
        List<int[]> final_answer = new List<int[]>();
        final_answer.Add(intervals[0]);

        int[] current_interval;
        int[] next_sorted_interval;
        // Go through each interval within the provided array.
        for (int i_each_interval = 0; i_each_interval < intervals.Length; ++i_each_interval)
        {
            // Compare each successive interval against the last interval in the result container.
            current_interval = intervals[i_each_interval];
            next_sorted_interval = final_answer[final_answer.Count - 1];

            // Due to the sorting order of the array, the intervals will be the same or increasing in size (value),
            // Thus, it is only necessary to merge from the right side of the answer interval (higher number of the two in a given interval).
            // If lowest number of the new interval (6,10) is LESS than or EQUAL to the highest number of an existing interval (4,7)...
            if (current_interval[0] <= next_sorted_interval[1])
            {
                // ...but GREATER than or EQUAL to the lowest number of that same interval...
                if (current_interval[0] >= next_sorted_interval[0])
                {
                    // ...there IS an overlap, but is the new interval extent larger than the existing one?
                    if (current_interval[1] > next_sorted_interval[1])
                    {
                        // Yes, the new interval extends the current answer interval to the right ([4,7] + [6,10] -> [4,10])
                        next_sorted_interval[1] = current_interval[1];
                        continue;
                    } else {
                        // No, the new interval fits inside the existing answer interval, no need to add it.
                        continue;
                    }
                }
            }

            // If the new interval does not overlap the last answer interval, add it to the list.
            final_answer.Add(current_interval);
        }

        return final_answer.ToArray();
    }
}
