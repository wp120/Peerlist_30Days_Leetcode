class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prevNode = NULL; // for the previous node
        ListNode *currNode = head; // for the current node
        ListNode *nextNode = head; // for the next node
        while (currNode != NULL)
        {
            nextNode = currNode->next; // storing next node so we don't loose it after reversing link
            currNode->next = prevNode; // reverse the link
            prevNode = currNode;       // advancing the previous node pointer for next iteration
            currNode = nextNode;       // advancing the current node pointer for next iteration
        }
        return prevNode;
    }
};