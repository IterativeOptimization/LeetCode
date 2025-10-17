class main
{
    static public void Main(String[] args)
    {
        // Various test cases.
        // string input_value = "()";
        // string input_value = "()[]{}";
        string input_value = "(]";
        // string input_value = "([])";
        // string input_value = "([)]";
        // string input_value = "[";
        // string input_value = "]";

        // Display the starting value.
        Console.WriteLine("Input Value: {0}", input_value);

        // Perform the operation on the data.
        Solution mySolution = new Solution();
        bool output_value = mySolution.IsValid(input_value);

        // Display the final value.
        Console.WriteLine("Output Value: {0}", output_value);
    }
}

public class Solution
{
    public bool IsValid(String s)
    {
        Stack<char> open_parenthesis_stack = new Stack<char>(s.Length);
        char just_popped_char;

        foreach (char each_char in s)
        {
            // start a new open
            if (each_char == '(' || each_char == '[' || each_char == '{')
            {
                open_parenthesis_stack.Push(each_char);
            }
            else
            {
                // nothing on the stack to close, not enough openings
                if (open_parenthesis_stack.Count == 0)
                {
                    return false;
                }

                just_popped_char = open_parenthesis_stack.Pop();

                // does the close match the last open?
                if (each_char == ')')
                {
                    if (just_popped_char != '(')
                    {
                        return false;
                    }
                }
                else if (each_char == ']')
                {
                    if (just_popped_char != '[')
                    {
                        return false;
                    }
                }
                else
                {
                    if (just_popped_char != '{')
                    {
                        return false;
                    }
                }
            }
        }

        // still something on the stack, not enough closings
        if (open_parenthesis_stack.Count != 0)
        {
            return false;
        }

        return true;
    }
}
