#include <iostream>
#include <vector>
#include <algorithm>

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

// Sorting function for ListNode comparison.
inline bool list_node_compare (ListNode* node_one, ListNode* node_two)
{
    return (node_one->val < node_two->val);
}

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (nullptr == head)
        {
            return head;
        }

        ListNode* current_node = head;
        vector<ListNode*> nodes_as_vector = vector<ListNode*>();

        // Load the values into a sortable structure.
        while (nullptr != current_node)
        {
            nodes_as_vector.push_back(current_node);
            current_node = current_node->next;
        }

        // Sort in ascending order.
        sort(nodes_as_vector.begin(), nodes_as_vector.end(), list_node_compare);

        // Note the new head of the vector in order to return it later.
        current_node = head = nodes_as_vector[0];

        // Relink the singly linked list nodes in sorted order.
        int node_vector_length = nodes_as_vector.size();
        for (int i_each_node = 1; i_each_node < node_vector_length; ++i_each_node)
        {
            current_node->next = nodes_as_vector[i_each_node];
            current_node = current_node->next;
        }

        // Designate the new end of the list to avoid a potential circularly linked list.
        current_node->next = nullptr;

        return head;
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
    // ListNode *input_value = new ListNode(4);
    // input_value->next = new ListNode(2);
    // input_value->next->next = new ListNode(1);
    // input_value->next->next->next = new ListNode(3);
    // input_value->next->next->next->next = nullptr;

    ListNode* input_value = new ListNode(-1);
    input_value->next = new ListNode(5);
    input_value->next->next = new ListNode(3);
    input_value->next->next->next = new ListNode(4);
    input_value->next->next->next->next = new ListNode(0);
    input_value->next->next->next->next->next = nullptr;


    // Display the starting value.
    ListNode *current_node = input_value;
    cout << "Input Value: " << endl;
    while (nullptr != current_node)
    {
        cout << current_node->val << endl;
        current_node = current_node->next;
    }

    // Perform the operation on the data.
    Solution mySolution = Solution();
    ListNode *head = current_node = mySolution.sortList(input_value);

    // Display the final value.
    cout << "Output Value: " << endl;
    while (nullptr != current_node)
    {
        cout << current_node->val << endl;
        current_node = current_node->next;
    }

    // Delete the dynamically allocated heap memory.
    clean_up(head);
}
