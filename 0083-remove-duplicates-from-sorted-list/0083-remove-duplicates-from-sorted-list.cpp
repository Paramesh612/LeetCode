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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *tr=head;
        while(tr!=NULL && tr->next!=NULL){
            if(tr->val==tr->next->val){
                tr->next=tr->next->next;
            }else{
                tr=tr->next;
            }
        }
        return head;
    }
};