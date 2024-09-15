/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *t = NULL;    // For traversing
        ListNode *head = NULL; // For returning as head of final sorted list
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val > list2->val)
            {
                ListNode *temp = list1;
                list1 = list2;
                list2 = temp;
            }
            // The above if-block swaps the values of node pointers if list1 has smaller value than list2.
            // This way we have to write code only for list1->val < list2->val and it'll handle both cases.
            if (t == NULL)
            {
                head = list1; // if this is our first node then saving it in head;
            }
            else
            {
                t->next = list1;
            }
            t = list1;
            list1 = list1->next;
        }
        while (list1 != NULL)
        { // if list2 finishes first
            if (t == NULL)
            {
                head = list1;
            }
            else
            {
                t->next = list1;
            }
            t = list1;
            list1 = list1->next;
        }
        while (list2 != NULL)
        { // if list1 finishes first
            if (t == NULL)
            {
                head = list2;
            }
            else
            {
                t->next = list2;
            }
            t = list2;
            list2 = list2->next;
        }
        return head;
    }
};