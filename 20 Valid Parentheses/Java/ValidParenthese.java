import java.util.Stack;

class main {
    public static void main(String[] args)
    {
        // Various test cases.
        // String input_value = "()";
        String input_value = "()[]{}";
        // String input_value = "(]";
        // String input_value = "([])";
        // String input_value = "([)]";
        // String input_value = "[";
        // String input_value = "]";

        // Display the starting value.
        System.out.println("Input Value: " + input_value);

        // Perform the operation on the data.
        Solution mySolution = new Solution();
        boolean output_value = mySolution.isValid(input_value);

        // Display the final value.
        System.out.println("Output Value: " + output_value);
    }
}

class Solution
{
    public boolean isValid(String s)
        {
            Stack<Character> open_parenthesis_stack = new Stack<Character>();
            char just_popped_char;
            char each_char;
            int input_length = s.length();
            
            for (int i_each_char = 0; i_each_char < input_length; ++i_each_char)
            {
                each_char = s.charAt(i_each_char);

                // start a new open
                if (each_char == '(' || each_char == '[' || each_char == '{')
                {
                    open_parenthesis_stack.push(each_char);
                }
                else
                {
                    // nothing on the stack to close, not enough openings
                    if (open_parenthesis_stack.size() == 0)
                    {
                        return false;
                    }
    
                    just_popped_char = open_parenthesis_stack.pop();
    
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
            if (open_parenthesis_stack.size() != 0)
            {
                return false;
            }
    
            return true;
        }
}
