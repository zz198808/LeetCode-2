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
    ListNode *detectCycle(ListNode *head) {
        if (NULL == head)
            return NULL;
        ListNode *p1 = head, *p2 = head->next;
        while (p2 != NULL && p2->next != NULL) {
            if (p1 == p2) {
                for (ListNode *p = head; p != NULL; p = p->next) {
                    do {
                        if (p == p1) {
                            return p;
                        }
                        p1 = p1->next;                
                    } while (p1 != p2);
                }
                break;
            }
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        return NULL;
    }
};
