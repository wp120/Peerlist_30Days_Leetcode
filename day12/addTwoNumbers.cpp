class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *t = NULL;
        ListNode *head = NULL;
        int carry = 0;
        while (l1 != NULL || l2 != NULL)
        {
            if (t == NULL)
            { // It means this is our first node
                t = new ListNode();
                head = t;
            }
            else
            { // It is not the first node
                t->next = new ListNode();
                t = t->next;
            }
            t->val = carry;
            if (l1 != NULL)
            {
                t->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                t->val += l2->val;
                l2 = l2->next;
            }
            carry = t->val / 10;
            t->val %= 10;
        }
        if (carry != 0)
        { // if carry is not zero then one more digit is required.
            t->next = new ListNode();
            t->next->val = carry % 10;
            t = t->next;
            carry /= 10;
        }
        return head;
    }
};