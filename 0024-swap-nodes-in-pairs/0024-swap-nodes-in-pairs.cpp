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

    ListNode* swap(ListNode *h1 ,ListNode *h2 ){
        // ListNode *current = h1;
        // ListNode *next=current->next;
        if(!h2) return h1;
        h1->next=h2->next;
        h2->next=h1;

        return h2;
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;

        ListNode dummy(-100);

        dummy.next=head;
        head=&dummy;
        ListNode *current = head;
        ListNode *next=current->next;
        ListNode *newHead=NULL;

        while(current!=NULL && next!=NULL){
            
            if(current->next==NULL || current->next->next==NULL) break;

            current->next=swap(current->next,current->next->next);
            current=current->next->next;
        }

        return head->next;
    }
};