class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int count = 0;
        ListNode *temp = head;
        // first count total number of nodes.
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        count -= n; // getting index of node which is previous to the node to be removed.
        if (count == 0)
        { // if head is to be removed.
            head = head->next;
            return head;
        }
        // otherwise travel to node which is previous to the node to be removed.
        temp = head;
        while (--count)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next; // remove the node
        return head;
    }
};