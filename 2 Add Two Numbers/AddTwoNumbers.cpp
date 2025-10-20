#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return RecursiveNodeAddition(*l1, *l2, 0);
    }

private:
    ListNode *RecursiveNodeAddition(ListNode& FirstList, ListNode& SecondList, int CarryValue)
    {
        // Overwrite the second list values in order to avoid having to allocate new memory.
        SecondList.val = FirstList.val + SecondList.val + CarryValue;

        // At most 9 + 9 will be added, so it is safe to say no more than 1 will every be carried over to the next position.
        if (SecondList.val >= 10)
        {
            SecondList.val %= 10;
            CarryValue = 1;
        }
        else
        {
            CarryValue = 0;
        }

        // If the lists both continue, go down the line adding them.
        if ((nullptr != FirstList.next) && (nullptr != SecondList.next))
        {
            SecondList.next = RecursiveNodeAddition(*FirstList.next, *SecondList.next, CarryValue);
        }
        // At least one list has ended, but the other may continue if they are not the same length.
        else
        {
            ListNode finish_this_list;
            if (nullptr != FirstList.next)
            {
                finish_this_list = FirstList;
            }
            else
            {
                finish_this_list = SecondList;
            }

            // Since the second list has been overwritten thus far to save memory allocation, create some extra trackers.
            // This is needed to avoid overwriting the nodes being operated on if the second list was the longer of the two.
            ListNode* current_node = &SecondList;
            ListNode* next_node;
            while (nullptr != finish_this_list.next)
            {
                next_node = finish_this_list.next;

                // if the second list was the longer of the two, keep overwriting it, otherwise allocate a new node
                if(nullptr != current_node->next)
                {
                    current_node->next->val = finish_this_list.next->val + CarryValue;
                }
                else
                {
                    current_node->next = new ListNode(finish_this_list.next->val + CarryValue);
                }

                // Could be 9 + 1 so it may be necessary to carry a one.
                if (current_node->next->val >= 10)
                {
                    current_node->next->val %= 10;
                    CarryValue = 1;
                }
                else
                {
                    CarryValue = 0;
                }

                current_node = current_node->next;
                finish_this_list = *next_node;
            }

            // If the longer list has been finished and a carry value remains, create a new node at the end to store that value.
            if (0 != CarryValue)
            {
                current_node->next = new ListNode(CarryValue);
            }
        }

        return &SecondList;
    }
};

void clean_up(ListNode *delete_me)
{
    if (nullptr != delete_me)
    {
        clean_up(delete_me->next);
    }
    delete delete_me;
}

int main()
{
    // Various test cases.

    // Set one - same length lists + carryover
    // 243
    // ListNode* input_value_one = new ListNode(2);
    // input_value_one->next = new ListNode(4);
    // input_value_one->next->next = new ListNode(3);

    // 564
    // ListNode* input_value_two = new ListNode(5);
    // input_value_two->next = new ListNode(6);
    // input_value_two->next->next = new ListNode(4);

    // Set two - both zero values + one node length lists
    // 0
    // ListNode* input_value_one = new ListNode(0);

    // 0
    // ListNode* input_value_two = new ListNode(0);

    // Set three - longer first list + new carryover node required at the end
    // 9999999
    ListNode* input_value_one = new ListNode(9);
    input_value_one->next = new ListNode(9);
    input_value_one->next->next = new ListNode(9);
    input_value_one->next->next->next = new ListNode(9);
    input_value_one->next->next->next->next = new ListNode(9);
    input_value_one->next->next->next->next->next = new ListNode(9);
    input_value_one->next->next->next->next->next->next = new ListNode(9);

    // 9999
    ListNode* input_value_two = new ListNode(9);
    input_value_two->next = new ListNode(9);
    input_value_two->next->next = new ListNode(9);
    input_value_two->next->next->next = new ListNode(9);

    // Set four - longer second list
    // 249
    // ListNode* input_value_one = new ListNode(2);
    // input_value_one->next = new ListNode(4);
    // input_value_one->next->next = new ListNode(9);

    // 5649
    // ListNode* input_value_two = new ListNode(5);
    // input_value_two->next = new ListNode(6);
    // input_value_two->next->next = new ListNode(4);
    // input_value_two->next->next->next = new ListNode(9);

    // Set five - zero value + longer second list + identical output to second list
    // 0
    // ListNode *input_value_one = new ListNode(0);

    // 278
    // ListNode *input_value_two = new ListNode(2);
    // input_value_two->next = new ListNode(7);
    // input_value_two->next->next = new ListNode(8);

    // Display the starting value.
    ListNode *current_node = input_value_one;
    cout << "Input Value One: " << endl;
    while (nullptr != current_node)
    {
        cout << current_node->val << endl;
        current_node = current_node->next;
    }
    current_node = input_value_two;
    cout << "Input Value Two: " << endl;
    while (current_node != nullptr)
    {
        cout << current_node->val << endl;
        current_node = current_node->next;
    }

    // Perform the operation on the data.
    Solution mySolution = Solution();
    current_node = mySolution.addTwoNumbers(input_value_one, input_value_two);

    // Display the final value.
    cout << "Output Value: " << endl;
    while (current_node != nullptr)
    {
        cout << current_node->val << endl;
        current_node = current_node->next;
    }

    // Delete the dynamically allocated heap memory.
    clean_up(input_value_one);
    clean_up(input_value_two);
}
