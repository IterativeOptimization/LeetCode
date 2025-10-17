#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> open_parenthesis_stack;
        char popped_char;

        for(char each_char : s)
        {
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

                popped_char = open_parenthesis_stack.top();
                open_parenthesis_stack.pop();

                // does the close match the last open?
                if (each_char == ')')
                {
                    if (popped_char != '(')
                    {
                        return false;
                    }
                }
                else if (each_char == ']')
                {
                    if (popped_char != '[')
                    {
                        return false;
                    }
                }
                else
                {
                    if (popped_char != '{')
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
};

int main()
{
    // Various test cases.
    // string input_value = "()";
    string input_value = "()[]{}";
    // string input_value = "(]";
    // string input_value = "([])";
    // string input_value = "([)]";
    // string input_value = "[";
    // string input_value = "]";

    // Display the starting value.
    cout << "Input Value: " << input_value << endl;

    // Perform the operation on the data.
    Solution mySolution = Solution();
    bool output_value = mySolution.isValid(input_value);

    // Display the final value.
    cout << "Output Value: " << std::boolalpha << output_value << endl;
}
