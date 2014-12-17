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
    ListNode *deleteDuplicates(ListNode *head) {
         if(!head || !head->next) {
            return head;
        }
        
        ListNode* node = head;
        while(node!=NULL) {
            if(node->next!=NULL && node->next->val == node->val) {
                node->next = node->next->next;
                continue;
            } 
            node = node->next;
        }
        
        return head;
    }
};