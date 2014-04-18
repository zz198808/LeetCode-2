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
        srand(time(NULL));
        int n = 0;
        for (ListNode *it = head; it != NULL; it = it->next) {
            n++;
        }
        ListNode* tail;
        return QsortList(head, n, tail);
    }
    
private:
    ListNode* QsortList(ListNode *head, int n, ListNode* &tail) {
        if (n <= 1) {
            tail = head;
            return head;
        }
        ListNode *mid = ChooseMid(head, n);
        ListNode right_head(0);
        ListNode *left = NULL, *right = &right_head;

        bool last_choose = true;
        int lcnt = 0, rcnt = 0;
        for (ListNode *it = head; it != NULL; ) {
            ListNode *next_it = it->next;
            if (it != mid) {
                bool choose_left;
                
                if (it->val < mid->val) {
                    choose_left = true;
                } else if (it->val > mid->val) {
                    choose_left = false;
                } else {    
                    choose_left = !last_choose;
                }
                last_choose = choose_left;
                
                if (choose_left) {
                    it->next = left;
                    left = it;
                    lcnt++;
                } else {
                    right->next = it;
                    right = it;
                    rcnt++;
                }
            }
            it = next_it;
        }
        right->next = NULL;
        ListNode *ltail, *rtail;
        ListNode *lhead = QsortList(left, lcnt, ltail);
        ListNode *rhead = QsortList(right_head.next, rcnt, rtail);
        ListNode *sorted_head;
        if (ltail == NULL) {
            sorted_head = mid;
        } else {
            sorted_head = lhead;
            ltail->next = mid;
        }
        if (rtail == NULL) {
            mid->next = NULL;
            tail = mid;
        } else {
            mid->next = rhead;
            tail = rtail;
        }
        return sorted_head;
   }
   
   ListNode* ChooseMid(ListNode *head, int n) {
       int k = rand() % n;
       for (int i = 0; i < k; i++) {
           head = head->next;
       }
       return head;
   }
   
};