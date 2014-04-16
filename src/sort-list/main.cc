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
    ListNode *sortList(ListNode *head) {
        int n = 0;
        for (ListNode *it = head; it != NULL; it = it->next) {
            n++;
        }
        return merge_sort(head, n);
        
    }
    
private:
    ListNode *merge_sort(ListNode *head, int n) {
        if (n <= 1) {
            return head;
        }
        ListNode *it = head;
        int ln = (n - 1) / 2;
        for (int i = 0; i < ln; i++) {
            it = it->next;
        }
        ListNode *head2 = it->next;
        it->next = NULL;
        ListNode *left_head = merge_sort(head, ln + 1);
        ListNode *right_head = merge_sort(head2, n - (ln + 1));
        ListNode ans(0), *ans_ptr = &ans;
        while (left_head && right_head) {
            if (left_head->val <= right_head->val) {
                ans_ptr->next = left_head;
                left_head = left_head->next;
                ans_ptr = ans_ptr->next;
            } else {
                ans_ptr->next = right_head;
                right_head = right_head->next;
                ans_ptr = ans_ptr->next;
            }
        }
        if (left_head) {
            ans_ptr->next = left_head;
        }
        if (right_head) {
            ans_ptr->next = right_head;
        }
        return ans.next;
    }
};