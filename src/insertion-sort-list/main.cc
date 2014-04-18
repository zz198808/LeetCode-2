/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode sorted_head(0);
        for (ListNode *it = head; it != NULL; ) {
            ListNode *next = it->next;
            
            InsertToSortedList(&sorted_head, it);
            
            it = next;
        }
        return sorted_head.next;
    }
private:
    void InsertToSortedList(ListNode *sorted_head, ListNode *it)
    {
        ListNode *last = sorted_head;
        
        while (sorted_head->next != NULL) {
            
            if (sorted_head->next->val > it->val) {
                break;
            }
            
            last = sorted_head->next;
            sorted_head = sorted_head->next;
        }
        it->next = sorted_head->next;
        last->next = it;
    }
};