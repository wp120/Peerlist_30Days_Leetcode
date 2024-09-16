class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;
        // First count total nodes;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        count /= 2;  // because we have to find middle element;
        temp = head; // Now again traverse from the start upto middle element;
        while (count--)
        {
            temp = temp->next;
        }
        return temp;
    }
};