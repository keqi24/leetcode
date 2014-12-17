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
        ListNode* newHead = NULL;
        ListNode* newNode = NULL;
        int val = 0;
        while(node) {
            if(node->next && node->next->val == node->val) {
                val = node->val;
                node = node->next->next;
                while(node && node->val == val) {
                    node = node->next;
                }
             } else {
                if(newHead == NULL) {
                    newHead = node;
                    newNode = node;
                    node = node->next;
                } else {
                    newNode->next = node;
                    newNode = node;
                    node = node->next;
                }
             }
        }
        if(newNode != NULL) 
            newNode->next = NULL;
        
        return newHead;
    }
};