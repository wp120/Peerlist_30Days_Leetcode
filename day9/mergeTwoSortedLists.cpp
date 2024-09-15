class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *t = NULL, *head = NULL;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val > list2->val)
            {
                ListNode *temp = list1;
                list1 = list2;
                list2 = temp;
            }
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
        while (list1 != NULL)
        {
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
        {
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