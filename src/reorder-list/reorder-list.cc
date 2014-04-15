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
    void reorderList(ListNode *head) {
        
        int n = 0;
        for (ListNode *it = head; it != NULL; it = it->next) {
            n++;
        }
        int split = (n - 1) / 2;
        int cur = 0;
        ListNode *last = NULL, *rhead = NULL;
        for (ListNode *it = head; it != NULL; ) {
            
            if (n != 1 && cur == n - 1) {
                rhead = it;
            }
            
            if (cur == split) {
                ListNode *tmp = it;
                it = it->next;
                tmp->next = NULL;
            } else if (cur > split) {
                ListNode *tmp = it;
                it = it->next;
                tmp->next = last;
                last = tmp;
            } else {
                it = it->next;
            }
            
            
            cur++;
        }
        
        if (head != NULL) {
            ListNode *ans = head, *it = head->next, *r_it = rhead;
            while (it != NULL && r_it != NULL) {
                ListNode *next_r_it = r_it->next,
                            *next_it = it->next;
                ans->next = r_it;
                ans = ans->next;
                ans->next = it;
                ans = ans->next;
                r_it = next_r_it;
                it = next_it;
            }
            if (it != NULL) {
                ans->next = it;
            } 
            if (r_it != NULL) {
                ans->next = r_it;
            }
        }
    }
};