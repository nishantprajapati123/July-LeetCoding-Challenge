// Time complexity :- O(n)
// Space complexity :- O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head == NULL)    return head;
        while(head && head->val == val)
        {
            head = head->next;
        }
        ListNode* curr = head;
        while(curr && curr->next && curr->next->val != val)
        {
            curr = curr->next;
        }
        if(curr==NULL || curr->next == NULL)  return head;
        
        curr->next = removeElements(curr->next->next, val);
        return head;
    }
};