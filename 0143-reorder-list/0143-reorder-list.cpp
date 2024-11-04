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
    ListNode* reverseList(ListNode *head){
        // ListNode dummy= new ListNode(0);
        // dummy->next=head;
        
        ListNode *prev=NULL;
        ListNode *current=head;
        ListNode *next=current->next;

        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    } 
    int  findLength(ListNode *head){
        ListNode* tr=head;
        int c=0;
        while(tr!=NULL){
            c++;
            tr=tr->next;
        }
        return c;
    }

    void display(ListNode *head){
        ListNode *current=head;
        while(current!=NULL){
            cout<<current->val<<" ";
            current=current->next;
        }
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        int n= findLength(head);
        ListNode *prev=NULL,*current=head;
        for(int i=0;i<n/2;i++){
            prev=current;
            current=current->next;
        }
        prev->next=NULL;
        ListNode *secondHead=reverseList(current);
        

        ListNode *tr1=head, *tr2=secondHead;
        ListNode *temp1=NULL,*temp2=NULL;

        prev=NULL;
        while(tr1!=NULL && tr2!=NULL){
            temp1 = tr1->next;
            temp2 = tr2->next;
            tr1->next=tr2;
            tr2->next=temp1;

            prev=tr2;
            tr1=temp1;
            tr2=temp2;
        }
        if(tr2) cout<<tr2->val<<endl;
        cout<<"Prev: "<<prev->val;
        if(n%2) 
            prev->next=tr2;
        // if(tr2!=NULL) tr2->next=temp1;
        
    }
};